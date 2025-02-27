/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:39:49 by jbofengo          #+#    #+#             */
/*   Updated: 2025/02/04 16:39:59 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void	destroy_arena(t_arena **arena)
{
	if (!arena || !*arena)
		return ;
	if ((*arena)->buffer)
		free((*arena)->buffer);
	free(*arena);
	*arena = NULL;
}

void	destroy_arena_list(t_arena **arena)
{
	t_arena	*next;

	if (!arena)
		return ;
	while (*arena)
	{
		next = (*arena)->next;
		destroy_arena(arena);
		*arena = next;
	}
}

size_t	get_type_alignment(size_t size)
{
	if (size >= 16)
		return (16);
	else if (size >= 8)
		return (8);
	else if (size >= 4)
		return (4);
	else if (size >= 2)
		return (2);
	else
		return (1);
}

int	arena_add(t_arena **arena, size_t size)
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
	new_arena->next = *arena;
	*arena = new_arena;
	return (1);
}

void	*arena_alloc(size_t memb_size, size_t n_memb, t_arena **arena)
{
	void		*ptr;
	size_t		alignement;
	uintptr_t	aligned_offset;
	size_t		size;

	if (!arena || !*arena || !(*arena)->buffer)
		return (NULL);
	size = memb_size * n_memb;
	//Verificação de overflow
	if (__builtin_mul_overflow(memb_size, n_memb, &size))
		return (NULL);
	//Obtem o alinhamento com base no tamanho do tipo de dado
	alignement = get_type_alignment(memb_size);
	//Calcular o alinhamento dos tipos na memoria
	aligned_offset = ((*arena)->offset + (alignement - 1)) & ~(alignement - 1);
	//Verifica se o offset alinhado mais o tamanho do tipo de dado é maior que o tamanho do buffer
	if (aligned_offset + size > (*arena)->size)
	{
		if (!arena_add(arena, size))
			return (NULL);
		return (arena_alloc(memb_size, n_memb, arena));
	}
	//Atribui o ponteiro ao endereço do buffer mais o offset alinhado
	ptr = (*arena)->buffer + aligned_offset;
	//Actualiza o offset do buffer
	(*arena)->offset = aligned_offset + size;
	return (ptr);
}

void	arena_reset(t_arena *arena, int clear_memory)
{
	if (!arena)
		return ;
	else if (clear_memory && arena->buffer)
		ft_memset(arena->buffer, 0, sizeof(char) * arena->size);
	arena->offset = 0;
}

void	arena_reset_all(t_arena *arena, int clear_memory)
{
	while (arena)
	{
		arena_reset(arena, clear_memory);
		arena = arena->next;
	}
}

t_arena	*arena_create(size_t buffer_size)
{
	t_arena *arena;

	arena = ft_calloc(1, sizeof(t_arena));
	if (!arena)
	{
		ft_fprintf(2, "Error: Arena allocation failed\n");
		return (NULL);
	}
	//Tamanho mínimo do buffer é 4096
	if (buffer_size < 4096)
		buffer_size = 4096;
	arena->buffer = ft_calloc(buffer_size, sizeof(char));
	if (!arena->buffer)
	{
		ft_fprintf(2, "Error: Arena Criation Failed\n");
		return (free(arena), NULL);
	}
	arena->size = buffer_size;
	arena->offset = 0;
	arena->next = NULL;
	return (arena);
}
