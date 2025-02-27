/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:25:48 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/20 13:13:20 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		cont;
	const unsigned char	*source;
	unsigned char		*destiny;

	destiny = (unsigned char *)dest;
	source = (const unsigned char *)src;
	cont = 0;
	while (cont < n)
	{
		destiny[cont] = source[cont];
		cont++;
	}
	return (dest);
}
