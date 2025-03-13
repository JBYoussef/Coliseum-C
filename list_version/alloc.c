/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:31:25 by jbofengo          #+#    #+#             */
/*   Updated: 2025/02/28 13:32:01 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

int	add_new_arena(t_arena **arena, size_t size)
{
	t_arena	*new_arena;

	if (!arena || !*arena)
		return (0);
	if (size < 4096)
		size = 4096;
	else if (size % 4096) //Cria um tamanho multiplo de 4096 - 4KB
		size = ((size / 4096) + 1) * 4096;
	new_arena = arena_create(size);
	if (!new_arena)
	{
		ft_fprintf(2, "Error: Failed to allocate new arena of size %zu\n", size);
		return (0);
	}
	while ((*arena)->prev)
		*arena = (*arena)->prev;
	new_arena->next = *arena;
	(*arena)->prev = new_arena;
	*arena = new_arena;
	return (1);
}

// Pega no ponteiro para um endereço de tamanho desejado e o retorna
void	*decrease_block_size(t_free *current, size_t alloc_size, t_arena *arena, t_free *prev)
{
	t_uch8	*ptr;

	//Get address of the desired pointer
	ptr = current->addr;
	
	//Recalculate the block size and pointer position=
	current->addr += alloc_size;
	current->addr_size -= alloc_size;
	
	// If the block size becomes zero, remove it from the list
	if (!current->addr_size)
	{
		if (prev)
			prev->next = current->next;
		else
			arena->free_blocks = current->next; // Update the start of the list
		free(current);
	}
	return ((void *)ptr);
}

static size_t	get_aligned_offset(t_uch8 *buffer_ptr, t_uch8 *buffer_start)
{
	 size_t	aligned_offset;
	 size_t	arena_offset;
	 size_t	start_align;

	// Alinha o início do buffer para o próximo múltiplo de ALIGNMENT
	start_align = ((size_t)buffer_start + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1);

	// Calcula o deslocamento de buffer_ptr a partir do buffer alinhado
	arena_offset = (size_t)buffer_ptr - start_align;

	// Ajusta o deslocamento para o próximo múltiplo de ALIGNMENT
	aligned_offset = (arena_offset + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1);

	//retornar o offset alinhado
	return (aligned_offset);
}

//Função para o caso de não haver blocos livres ou se nenhum deles tiver espaço suficiente
void	*free_blocks_without_enough_space(t_arena **arena, size_t alloc_size)
{
	size_t	aligned_offset;
	t_free	*current;
	void	*ptr;

	if ((*arena)->prev)
	{
		*arena = (*arena)->prev;
		ptr = arena_alloc(alloc_size, 1, arena, true);
		if (ptr)
			return (ptr);
	}
	if (!add_new_arena(arena, alloc_size))
		return (NULL);
	current = (*arena)->free_blocks;
	aligned_offset = get_aligned_offset(current->addr, (*arena)->buffer);
	if ((*arena)->next && (*arena)->next->free_blocks)
	{
		*arena = (*arena)->next;
		return (decrease_block_size(current, alloc_size + aligned_offset, (*arena)->prev, NULL));
	}
	return (decrease_block_size(current, alloc_size + aligned_offset, *arena, NULL));
}

//Função para pegar o ponteiro de tamanho desejado na lista de blocos livres
void	*arena_alloc(size_t n_memb, size_t memb_size, t_arena **arena, bool recursive)
{
	t_free	*current;
	t_free	*prev;
	size_t	alloc_size;
	size_t	aligned_offset;

	if (!arena || !*arena || !(*arena)->buffer)
		return (NULL);
	else if (__builtin_mul_overflow(memb_size, n_memb, &alloc_size))
		return (NULL);
	prev = NULL;
	current = (*arena)->free_blocks;
	while (current)
	{
		aligned_offset = get_aligned_offset(current->addr, (*arena)->buffer);
		if (current->addr_size >= alloc_size + aligned_offset)
			return (decrease_block_size(current, alloc_size + aligned_offset, *arena, prev));
		prev = current;
		current = current->next;
	}
	if (recursive)
		return (NULL);
	return (free_blocks_without_enough_space(arena, alloc_size));
}
