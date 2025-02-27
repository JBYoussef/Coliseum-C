/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:57:33 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/24 12:57:47 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*map;

	if (lst == NULL)
		return (NULL);
	map = NULL;
	temp = lst;
	while (temp != NULL)
	{
		new = ft_lstnew(f(temp->content));
		if (new != NULL)
			ft_lstadd_back(&map, new);
		else
			ft_lstclear(&new, del);
		temp = temp->next;
	}
	return (map);
}
