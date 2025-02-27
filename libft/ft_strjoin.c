/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:21:42 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/21 12:22:08 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		count;
	size_t	total_sz;

	count = 0;
	total_sz = ft_strlen(s2) + ft_strlen(s1);
	new_str = (char *)ft_calloc(total_sz + 1, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1 && *s1)
		new_str[count++] = *s1++;
	while (s2 && *s2)
		new_str[count++] = *s2++;
	new_str[count] = '\0';
	return (new_str);
}
