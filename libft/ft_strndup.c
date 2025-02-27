/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:48:29 by jbofengo          #+#    #+#             */
/*   Updated: 2025/02/12 12:48:38 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;

	dst = (char *)ft_calloc(n + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, n);
	dst[n] = '\0';
	return (dst);
}
