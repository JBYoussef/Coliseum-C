/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:09:32 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/20 17:26:04 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				cont;

	cont = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (cont < n)
	{
		if (str1[cont] != str2[cont])
			return (str1[cont] - str2[cont]);
		cont++;
	}
	return (0);
}
