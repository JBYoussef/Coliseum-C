/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:03 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/20 17:08:33 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		cont;

	cont = 0;
	while (cont < n)
	{
		if (*(unsigned char *)(s + cont) == (unsigned char)c)
			return ((void *)((unsigned char *)s + cont));
		cont++;
	}
	return (NULL);
}
