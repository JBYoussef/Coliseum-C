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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum	e_color
{
	BLACK,
	RED
}	t_color;

typedef struct	s_rbt
{
	int		data;
	char		color;
	struct s_rbt	*prev;
	struct s_rbt	*son[2];
}	t_rbt;

void	destroy_tree(t_rbt **tree)
{
	if (!*tree)
		return ;
	destroy_tree(&(*tree)->son[0]);
	destroy_tree(&(*tree)->son[1]);
	free(*tree);
	*tree = NULL;
}

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

t_rbt	*create_node(int data)
{
	t_rbt	*tree;

	tree = (t_rbt *)malloc(sizeof(t_rbt));
	if (!tree)
	{
		printf("Error: Allocation of tree node failed\n");
		return (NULL);
	}
	tree->data = data;
	tree->color = RED;
	tree->prev = NULL;
	tree->son[0] = NULL;
	tree->son[1] = NULL;
	return (tree);
}

t_rbt	*simple_rotation(t_rbt *first_red, t_rbt *root, int side)
{
	char	tmp_side;
	t_rbt	*oposite_son;

	//Guarda o endereço do irmão de sec_red
	oposite_son = first_red->son[side];

	//Oque era irmão de sec_red passará a ser o pai
	first_red->son[side] = first_red->prev;

	first_red->prev->color = RED; 
	//E o pai do first_red passará a ser o seu avô
	first_red->prev = first_red->prev->prev;
	
	//Se o Avô for diferente de NULL
	if (first_red->prev)
	{
		//Acha qual é o filho do avô que é pai de first_red 
		tmp_side = first_red->prev->son[0] != first_red->son[side];
		//e esse filho passará a ser first_red
		first_red->prev->son[tmp_side] = first_red;
	}
	//Acha o filho do pai que está a apontar para first_red
	tmp_side = first_red->son[side]->son[0] != first_red;

	//Esse flho deixará de ser first_red e será o irmão de "sec_red" filho de first_red
	first_red->son[side]->son[tmp_side] = oposite_son;

	//O que costumava ser pai de first_red agora é filho de first_red 
	first_red->son[side]->prev = first_red;

	first_red->color = BLACK;
	//Se first_red é o novo topo
	if (!first_red->prev)
		return (first_red);

	return (root);
}

char	zig_zag_rotation(t_rbt **prev, t_rbt *son)
{
	t_rbt	*grand_father;
	t_rbt	*father;
	t_rbt	*tmp_son;
	char	tmp_side;
	char	side;

	father = *prev;
	side = father->son[0] != son;

	grand_father = father->prev;

	tmp_side = grand_father->son[0] != father;

	grand_father->son[tmp_side] = father->son[side];

	father->son[side]->prev = grand_father;

	tmp_side = father->data > father->son[side]->data;

	father->son[side]->son[tmp_side] = father;

	father->prev = father->son[side];

	father->son[side] = father->son[side]->son[!tmp_side];

	*prev = father->prev;

	return (father->prev->son[0] != father);
}

int	is_zig_zag_case(t_rbt *father, int side)
{
	t_rbt	*grand_father;

	grand_father = father->prev;
	if (father->data < grand_father->data && father->data < father->son[side]->data)
		return (1);
	else if (father->data > grand_father->data && father->data > father->son[side]->data)
		return (1);
	return (0);
}

t_rbt	*handle_red_father(t_rbt *root, t_rbt **father, char side)
{
	t_rbt	*uncle;
	t_rbt	*son_node;
	char	brother_side;

	//Atribuição do nó filho vermelho
	son_node = (*father)->son[side];
	//Acha o index do irmão
	brother_side = (*father)->prev->son[0] == *father;
	//Atribui o endereço do irmão ao ponteiro uncle
	uncle = (*father)->prev->son[brother_side];
	//Se o irmão também for vermelho
	if (uncle && uncle->color == RED)
	{
		//O seu pai é reescrito para vermelho e os dois irmãos para preto
		uncle->color = BLACK;
		(*father)->color = BLACK;
		(*father)->prev->color = RED;
		return (root);
	}
	//Se está e o novo nó está em zig zag com o pai e o avô
	else if (is_zig_zag_case(*father, side))
	{
		side = zig_zag_rotation(father, son_node); //Função para rotacionar em zig zag
	}
	//Apply simple Rotation
	return (simple_rotation(*father, root, !side));
}

t_rbt	*push_tree(t_rbt *root, t_rbt *new_node)
{
	t_rbt	*current;
	t_rbt	*father;
	char	side;

	if (!new_node)
	{
		write(2, "Invalid pointer passed, as parameter\n", 38);
		return (NULL);
	}
	else if (!root)
	{
		new_node->color = BLACK;
		return (new_node);
	}
	current = root;
	father = NULL;
	while (current)
	{
		father = current;
		//Acha o filho para o qual devemos nos mover
		side = new_node->data > current->data;
		//e move-se para lá
		current = current->son[side];
	}
	//Atribuimos new_node ao filho na posição correcta
	father->son[side] = new_node;
	new_node->prev = father;

	//Se o pai de new_node for BLACK
	if (father->color == BLACK)
		return (root);
	root = handle_red_father(root, &father, side);
	while (father->prev)
	{
		side = father->prev->son[0] != father;
		father = father->prev;
		if (father->color == RED && father->son[side]->color == RED)
			root = handle_red_father(root, &father, side);
	}
	if (father->color == RED)
		father->color = BLACK;
	return (root);
}

int	get_tree_data(int data, t_rbt *tree);

int	main(void)
{
	t_rbt	*tree = NULL;
	
	for (int i = 1; i <= 2000; i++)
		tree = push_tree(tree, create_node(i));
	print_rbt("top", tree, 5);
	destroy_tree(&tree);
	return (0);
}
