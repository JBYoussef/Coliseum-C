/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:29:42 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/06 11:29:44 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{	
	size_t	source_sz;
	char	*dest;

	source_sz = ft_strlen(s);
	dest = (char *)ft_calloc(source_sz + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, source_sz + 1);
	return (dest);
}
