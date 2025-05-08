/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:54:56 by jbofengo          #+#    #+#             */
/*   Updated: 2025/05/08 09:55:20 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_H
# define RBT_H

# include <stdlib.h>
# include <unistd.h>

# define RED 1
# define BLACK 0

typedef struct	s_rbt
{
	int		data;
	char		color;
	struct s_rbt	*prev;
	struct s_rbt	*son[2];
}	t_rbt;

void	destroy_rb_tree(t_rbt **tree);

t_rbt	*create_rbt_node(int data);

t_rbt	*push_tree(t_rbt *root, t_rbt *new_node);

t_rbt	*simple_rotation(t_rbt *first_red, t_rbt *root, char side);

char	is_zig_zag_case(t_rbt *father, char side);

char	zig_zag_rotation(t_rbt **prev, t_rbt *son);

#endif
