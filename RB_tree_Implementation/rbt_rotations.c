/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:17:37 by jbofengo          #+#    #+#             */
/*   Updated: 2025/05/08 10:17:48 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbt.h"

// Realiza uma rotação simples (esquerda ou direita) para balancear a árvore
// @param first_red: Nó vermelho a ser promovido
// @param root: Raiz atual da árvore
// @param side: Lado da rotação (0 para esquerda, 1 para direita)
// @return: Nova raiz da árvore após a rotação
t_rbt	*simple_rotation(t_rbt *first_red, t_rbt *root, char side)
{
	t_rbt	*oposite_son;
	char	tmp_side;

	// Armazena o filho oposto ao lado da rotação
	oposite_son = first_red->son[side];

	// O pai de first_red torna-se seu filho no lado da rotação
	first_red->son[side] = first_red->prev;

	// O pai de first_red torna-se vermelho
	first_red->prev->color = RED;

	// O avô de first_red torna-se seu novo pai
	first_red->prev = first_red->prev->prev;
	
	// Se existe um avô, atualiza seu ponteiro para first_red
	if (first_red->prev)
	{
		//Acha qual é o filho do avô que é pai de first_red 
		tmp_side = first_red->prev->son[0] != first_red->son[side];
		//e esse filho passará a ser first_red
		first_red->prev->son[tmp_side] = first_red;
	}
	// Atualiza o filho do antigo pai para apontar para oposite_son
	tmp_side = first_red->son[side]->son[0] != first_red;
	first_red->son[side]->son[tmp_side] = oposite_son;

	// Define first_red como pai do antigo pai
	first_red->son[side]->prev = first_red;

	// O nó promovido torna-se preto
	first_red->color = BLACK;

	// Se first_red não tem pai, ele é a nova raiz
	if (!first_red->prev)
		return (first_red);

	// Caso contrário, mantém a raiz original
	return (root);
}

// Realiza uma rotação dupla (ziguezague) para balancear a árvore
// @param prev: Ponteiro para o pai do nó a ser rotacionado
// @param son: Nó filho envolvido na rotação
// @return: Lado do pai após a rotação (0 para esquerda, 1 para direita)
char	zig_zag_rotation(t_rbt **prev, t_rbt *son)
{
	t_rbt	*grand_father;
	t_rbt	*father;
	char	tmp_side;
	char	side;

	// Obtém o pai e o avô
	father = *prev;
	side = father->son[0] != son; // Determina o lado do filho
	grand_father = father->prev;

	// Atualiza o ponteiro do avô para o filho no lado da rotação
	tmp_side = grand_father->son[0] != father;
	grand_father->son[tmp_side] = father->son[side];

	// O filho torna-se filho do avô
	father->son[side]->prev = grand_father;

	// Determina o lado do pai em relação ao filho
	tmp_side = father->data > father->son[side]->data;
	father->son[side]->son[tmp_side] = father;

	// O filho torna-se pai do antigo pai
	father->prev = father->son[side];

	// Atualiza o outro filho do nó promovido
	father->son[side] = father->son[side]->son[!tmp_side];

	// Atualiza o ponteiro do pai
	*prev = father->prev;

	// Retorna o lado do pai na nova configuração
	return (father->prev->son[0] != father);
}

// Verifica se a configuração atual requer uma rotação em ziguezague
// @param father: Nó pai do nó vermelho
// @param side: Lado do filho vermelho (0 para esquerda, 1 para direita)
// @return: 1 se é um caso de ziguezague, 0 caso contrário
char	is_zig_zag_case(t_rbt *father, char side)
{
	t_rbt	*grand_father;

	// Obtém o avô
	grand_father = father->prev;
	// Verifica se o pai está em ziguezague com o avô e o filho
	if (father->data < grand_father->data && father->data < father->son[side]->data)
		return (1);
	else if (father->data > grand_father->data && father->data > father->son[side]->data)
		return (1);
	return (0);
}
