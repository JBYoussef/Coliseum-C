/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:17:11 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/24 10:35:28 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*next_node;

	next_node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!next_node)
		return (NULL);
	next_node->content = content;
	next_node->next = NULL;
	return (next_node);
}
