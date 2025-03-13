/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:24:55 by jbofengo          #+#    #+#             */
/*   Updated: 2025/02/28 14:25:07 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

// Cria um novo bloco livre
t_free	*create_free_node(t_uch8 *addr, size_t addr_size)
{
	t_free	*free_block;

	free_block = (t_free *)ft_calloc(1, sizeof(t_free));
	if (!free_block)
	{
		ft_fprintf(2, "Error, while trying to allocate a t_free *\n");
		return (NULL);
	}
	free_block->addr = addr;
	free_block->addr_size = addr_size;
	free_block->next = NULL;
	return (free_block);
}

void	destroy_free_list(t_free **blocks)
{
	t_free	*current;

	if (!blocks || !*blocks)
		return ;
	current = *blocks;
	while (current)
	{
		*blocks = current->next;
		free(current);
		current = *blocks;
	}
}
