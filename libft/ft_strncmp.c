/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:18:13 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/20 17:43:15 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while (cont < n && s1[cont] && s2[cont] && (s1[cont] == s2[cont]))
		cont++;
	if (cont == n)
		return (0);
	else
		return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
}
