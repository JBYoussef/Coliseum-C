/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:37:26 by jbofengo          #+#    #+#             */
/*   Updated: 2025/02/28 16:50:28 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_version/arena.h"

char	*arena_strdup(const char *s, t_arena **arena)
{	
	size_t	source_sz;
	char	*dest;

	source_sz = ft_strlen(s);
	dest = (char *)arena_alloc(1, source_sz, arena, false);
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_memcpy(dest, s, source_sz + 1);
	return (dest);
}

int	main(void)
{
	t_arena	*arena;
	char	*str;

	arena = arena_create(100);
	if (!arena)
	{
		ft_fprintf(2, "error\n");
		return (1);
	}
	for (int i = 0; i < 100000; i++)
	{
		str = arena_strdup("Olá Mundo\n", &arena);
		if (i % 100 == 0)
			free_ptr_in_arena((void **)&str, 11, arena);
	}
	destroy_all_arenas(&arena);
	return (0);
}
