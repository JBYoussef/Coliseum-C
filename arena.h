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

# include "libft/libft.h"

typedef struct s_arena
{
	unsigned char	*buffer;
	size_t			size;
	size_t			offset;
	struct s_arena	*next;
}	t_arena;

t_arena	*arena_create(size_t buffer_size);

void	arena_reset(t_arena *arena, int clear_memory);

void	arena_reset_all(t_arena *arena, int clear_memory);

void	*arena_alloc(size_t memb_size, size_t n_memb, t_arena **arena);

void	destroy_arena(t_arena **arena);

void	destroy_arena_list(t_arena **arena);

#endif
