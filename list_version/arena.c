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
	destroy_free_list(&(*arena)->free_blocks);
	free(*arena);
	*arena = NULL;
}

void	destroy_all_arenas(t_arena **arena)
{
	t_arena	*next;

	if (!arena)
		return ;
	while ((*arena)->prev)
		*arena = (*arena)->prev;
	while (*arena)
	{
		next = (*arena)->next;
		destroy_arena(arena);
		*arena = next;
	}
}

bool	arena_reset(t_arena *arena, int clear_memory)
{
	t_free	*runner;
	t_free	*tmp;

	if (!arena)
		return (0);
	else if (clear_memory && arena->buffer)
		ft_memset(arena->buffer, 0, sizeof(char) * arena->size);
	runner = arena->free_blocks;
	if (!runner)
	{
		arena->free_blocks = create_free_node(arena->buffer, arena->size);
		if (!arena->free_blocks)
			return (0);
		return (1);
	}
	runner = runner->next;
	while (runner)
	{
		tmp = runner;
		runner = tmp->next;
		free(tmp);
	}
	arena->free_blocks->addr = arena->buffer;
	arena->free_blocks->addr_size = arena->size;
	arena->free_blocks->next = NULL;
	return (1);
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
	else if (buffer_size % 4096) //Cria um tamanho multiplo de 4096 - 4KB
		buffer_size = ((buffer_size / 4096) + 1) * 4096;
	arena->buffer = ft_calloc(buffer_size + ALIGNMENT - 1, sizeof(char));
	if (!arena->buffer)
	{
		ft_fprintf(2, "Error: Arena Criation Failed\n");
		return (free(arena), NULL);
	}
	arena->size = buffer_size;
	arena->free_blocks = create_free_node(arena->buffer, buffer_size);
	if (!arena->free_blocks)
	{
		(free(arena->buffer), free(arena));
		return (NULL);
	}
	arena->prev = NULL;
	arena->next = NULL;
	return (arena);
}
