/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:13:45 by jbofengo          #+#    #+#             */
/*   Updated: 2025/03/17 10:58:19 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbt.h"
#include <stdio.h>


void	print_rbt(const char *inf, t_rbt *tree, int index)
{
	if (!tree)
		return ;
	int i = -1;
	while (++i < index)
		printf(" ");
	printf("%s: data: %d color: ", inf, tree->data);
	if (tree->color == BLACK)
		printf("Black\n");
	else
		printf("RED\n");
	print_rbt("left", tree->son[0], index + 5);
	if (*inf == 't')
		printf("\n\n");
	print_rbt("right", tree->son[1], index + 5);
	if (*inf == 't')
		printf("\n");
}

int	main(void)
{
	t_rbt	*tree = NULL;
	
	for (int i = 1; i <= 2000; i++)
		tree = push_tree(tree, create_rbt_node(i));
	print_rbt("top", tree, 5);
	destroy_rb_tree(&tree);
	return (0);
}
