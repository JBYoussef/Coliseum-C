/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:08:39 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/20 14:15:02 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	tam;
	size_t	tam_src;

	tam = ft_strlen(dest);
	tam_src = ft_strlen(src);
	if (size == 0 || size <= tam)
		return (size + tam_src);
	count = 0;
	while (src[count] != '\0' && count != size - tam - 1)
	{
		dest[tam + count] = src[count];
		count++;
	}
	dest[tam + count] = '\0';
	return (tam + tam_src);
}
