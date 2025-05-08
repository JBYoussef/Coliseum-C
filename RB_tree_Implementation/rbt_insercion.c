/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:58:27 by jbofengo          #+#    #+#             */
/*   Updated: 2025/05/08 09:58:36 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbt.h"

// Lida com violações causadas por um pai vermelho após inserção
// @param root: Raiz atual da árvore
// @param father: Ponteiro para o pai do nó vermelho
// @param side: Lado do filho vermelho (0 para esquerda, 1 para direita)
// @return: Nova raiz da árvore após correções
t_rbt	*handle_red_father(t_rbt *root, t_rbt **father, char side)
{
	t_rbt	*uncle;
	t_rbt	*son_node;
	char	brother_side;

	// Obtém o nó filho vermelho	
	son_node = (*father)->son[side];

	// Determina o lado do tio (irmão do pai)
	brother_side = (*father)->prev->son[0] == *father;
	uncle = (*father)->prev->son[brother_side];

	// Caso 1: Tio é vermelho
	if (uncle && uncle->color == RED)
	{
		// Recolore: tio e pai tornam-se pretos, avô torna-se vermelho
		uncle->color = BLACK;
		(*father)->color = BLACK;
		(*father)->prev->color = RED;
		return (root);
	}
	//Se está e o novo nó está em zig zag com o pai e o avô
	else if (is_zig_zag_case(*father, side))
	{
		// Realiza rotação dupla
		side = zig_zag_rotation(father, son_node);
	}
	// Caso 3: Realiza rotação simples
	return (simple_rotation(*father, root, !side));
}


// Analisa e resolve as violações da RBT
// @param father: pai vermelho do nó recém inserido
// @param root: Raiz atual da árvore
// @param side: Lado do filho vermelho (0 para esquerda, 1 para direita)
t_rbt	*fix_violations(t_rbt *father, t_rbt **root, char side)
{
	// Corrige violações se o pai é vermelho
	*root = handle_red_father(*root, &father, side);

	// Verifica violações adicionais subindo até a raiz
	while (father->prev)
	{
		side = father->prev->son[0] != father;
		father = father->prev;
		if (father->color == RED && father->son[side]->color == RED)
			*root = handle_red_father(*root, &father, side);
	}
	// Garante que a raiz seja preta
	if (father->color == RED)
		father->color = BLACK;
	return (*root);
}

// Insere um novo nó na Árvore Rubro-Negra e balanceia a árvore
// @param root: Raiz atual da árvore
// @param new_node: Nó a ser inserido
// @return: Nova raiz da árvore ou NULL em caso de erro
t_rbt	*push_tree(t_rbt *root, t_rbt *new_node)
{
	t_rbt	*current;
	t_rbt	*father;
	char	side;

	// Verifica se o novo nó é válido
	if (!new_node)
	{
		write(2, "Invalid pointer passed, as parameter\n", 38);
		return (NULL);
	}
	// Caso especial: Árvore vazia
	if (!root)
	{
		new_node->color = BLACK; // Raiz é sempre preta
		return (new_node);
	}
	// Procura a posição de inserção
	current = root;
	father = NULL;
	while (current)
	{
		father = current;
		side = new_node->data > current->data; // 0: esquerda, 1: direita
		current = current->son[side];
	}
	//Atribuimos new_node ao filho na posição correcta
	father->son[side] = new_node;
	new_node->prev = father;

	// Se o pai é preto, não há violações
	if (father->color == BLACK)
		return (root);
	
	return (fix_violations(father, &root, side));
}
