/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:46:40 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/20 17:53:33 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n_bytes;

	n_bytes = nmemb * size;
	if (size && ((n_bytes / size) != nmemb))
		return (NULL);
	ptr = malloc(n_bytes);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, n_bytes);
	return (ptr);
}
