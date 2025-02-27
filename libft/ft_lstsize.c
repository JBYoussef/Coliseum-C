/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:54:06 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/24 11:23:05 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		node_len;

	if (lst == NULL)
		return (0);
	node_len = 1;
	temp = lst->next;
	while (temp != NULL)
	{
		temp = temp->next;
		node_len++;
	}
	return (node_len);
}
