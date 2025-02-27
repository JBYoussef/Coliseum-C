/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:15:07 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/22 09:39:44 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destin;

	if ((src == NULL && dest == NULL))
		return (dest);
	if (dest > src)
	{
		destin = (unsigned char *)dest + n - 1;
		source = (const unsigned char *)src + n - 1;
		while (n--)
			*destin-- = *source--;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
