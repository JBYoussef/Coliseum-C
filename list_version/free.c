/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:10:11 by jbofengo          #+#    #+#             */
/*   Updated: 2025/02/27 10:10:30 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

bool	merge_with_next_block(t_free *current, size_t addr_size)
{
	t_free	*next_tmp;

	// Mescla com o bloco atual (bloco liberado está depois do bloco atual)
	current->addr_size += addr_size;
	// Verifica se o próximo bloco também pode ser mesclado
	if (current->next && current->addr + current->addr_size == current->next->addr)
	{
		current->addr_size += current->next->addr_size;
		next_tmp = current->next;
		current->next = next_tmp->next;
		free(next_tmp);
	}
	return (1);
}

bool	merge_with_previous_block(t_free *current, t_uch8 *addr_start, size_t addr_size)
{
	// Mescla com o bloco atual (bloco liberado está antes do bloco atual)
	current->addr = addr_start;
	current->addr_size += addr_size;
	return (1);
}

bool	insert_block_before_current(t_free *current, t_free *prev, t_arena *arena, t_free *new_block)
{
	if (!new_block)
		return (0);
	new_block->next = current;
	if (prev)
		prev->next = new_block;
	else
		arena->free_blocks = new_block;
	return (1);
}

bool	validate_and_innit_vars(void **addr, t_uch8 **addr_start, t_arena *arena)
{
	if (!addr || !*addr || !arena || !arena->buffer)
		return (0);
	// Converte o endereço para o tipo correto
	*addr_start = (t_uch8 *)*addr;
	if (*addr_start < arena->buffer || *addr_start >= arena->buffer + arena->size)
		return (0);
	*addr = NULL;
	return (1);
}

bool	free_ptr_in_arena(void **addr, size_t addr_size, t_arena *arena)
{
	t_free		*current;
	t_uch8		*addr_start;
	t_free		*new_block;
	t_free		*prev;

	if (!validate_and_innit_vars(addr, &addr_start, arena))
		return (0);
	// Se a lista de blocos livres estiver vazia, cria um novo nó
	if (!arena->free_blocks)
	{
		arena->free_blocks = create_free_node(addr_start, addr_size);
		return (arena->free_blocks != NULL);
	}
	addr_size += get_aligned_offset(addr_start, arena->buffer);
	current = arena->free_blocks;
	prev = NULL;
	// Percorre a lista de blocos livres
	while (current)
	{
		// Bloco a ser liberado está antes do bloco atual
		if (addr_start + addr_size == current->addr)
			return (merge_with_previous_block(current, addr_start, addr_size));
		// Bloco a ser liberado está depois do bloco atual
		else if (current->addr + current->addr_size == addr_start)
			return (merge_with_next_block(current, addr_size));
		// Bloco a ser liberado está antes do bloco atual e não pode ser mesclado
		else if (addr_start < current->addr)
			return (insert_block_before_current(current, prev, arena, create_free_node(addr_start, addr_size)));
		// Avança para o próximo bloco
		prev = current;
		current = current->next;
	}
	// Se chegou aqui, o bloco liberado deve ser adicionado ao final da lista
	new_block = create_free_node(addr_start, addr_size);
	if (!new_block)
		return (0);
	prev->next = new_block;
	return (1);
}
