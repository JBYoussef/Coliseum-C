/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:38:58 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/24 10:39:16 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*for_now;

	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	for_now = new;
	for_now->next = *lst;
	*lst = for_now;
}
