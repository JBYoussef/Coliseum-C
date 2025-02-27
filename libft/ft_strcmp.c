/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:57:22 by jbofengo          #+#    #+#             */
/*   Updated: 2025/02/13 07:58:35 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	cont;

	cont = 0;
	while (s1[cont] && s1[cont] == s2[cont])
		cont++;
	return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
}
