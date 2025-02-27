/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:40 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/20 13:05:01 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			cont;
	unsigned char	*str;

	cont = 0;
	str = (unsigned char *)s;
	while (cont < n)
		str[cont++] = (unsigned char)c;
	return (s);
}
