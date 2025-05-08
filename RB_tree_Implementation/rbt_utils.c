/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_insercion_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:00:59 by jbofengo          #+#    #+#             */
/*   Updated: 2025/05/08 10:01:18 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbt.h"

t_rbt	*create_rbt_node(int data)
{
	t_rbt	*tree;

	// Aloca memória para o novo nó
	tree = (t_rbt *)malloc(sizeof(t_rbt));
	if (!tree)
	{
		write(2, "Erro: Falha na alocação de memória para o nó\n", 41);
		return (NULL);
	}
	// Inicializa os campos do nó
	tree->data = data;
	tree->color = RED;          // Novos nós são sempre vermelhos
	tree->prev = NULL;          // Sem pai inicialmente
	tree->son[0] = NULL;        // Filho à esquerda (menor)
	tree->son[1] = NULL;        // Filho à direita (maior)
	return (tree);
}

void	destroy_rb_tree(t_rbt **tree)
{
	if (!*tree)
		return ;
	destroy_rb_tree(&(*tree)->son[0]);
	destroy_rb_tree(&(*tree)->son[1]);
	free(*tree);
	*tree = NULL;
}
