/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:37:52 by jbofengo          #+#    #+#             */
/*   Updated: 2025/02/04 16:37:55 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>

# define ALIGNMENT 16

typedef unsigned char t_uch8;

/*
typedef struct s_free
{
	t_uch8		*addr;
	union
	{
		size_t	raw_value;
		struct
		{
			size_t	addr_size : 62;
			size_t	size_flag : 1;
			size_t	addr_flag : 1;
		};
	};
	struct s_free	*next;
}	t_free;
*/

typedef struct s_free
{
	t_uch8		*addr;
	size_t		addr_size;
	struct s_free	*next;
}	t_free;

typedef struct s_arena
{
	t_uch8		*buffer;
	size_t		size;
	t_free		*free_blocks;
	struct s_arena	*prev;
	struct s_arena	*next;
}	t_arena;

typedef struct s_arena
{
	t_arena
}	t_arena;

t_arena	*arena_create(size_t buffer_size);

t_free	*create_free_node(t_uch8 *addr, size_t addr_size);

t_uch8	*get_ptr_in_arena(size_t desired_size, t_arena *arena);

size_t	get_aligned_offset(t_uch8 *buffer_ptr, t_uch8 *buffer_start);

bool	free_ptr_in_arena(void **addr, size_t addr_size, t_arena *arena);

void	destroy_free_list(t_free **blocks);

bool	arena_reset(t_arena *arena, int clear_memory);

void	arena_reset_all(t_arena *arena, int clear_memory);

void	*arena_alloc(size_t n_memb, size_t memb_size, t_arena **arena, bool recursive);

void	destroy_arena(t_arena **arena);

void	destroy_all_arenas(t_arena **arena);

#endif
