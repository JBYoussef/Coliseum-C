/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:42:17 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/24 10:01:53 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count1;
	size_t	count2;
	char	*str;

	str = 0;
	if (s1 && set)
	{
		count1 = 0;
		count2 = ft_strlen(s1);
		while (s1[count1] && ft_strchr(set, s1[count1]))
			count1++;
		while (s1[count2 - 1] && ft_strchr(set, s1[count2 - 1])
			&& count2 > count1)
			count2--;
		str = (char *)malloc(sizeof(char) * (count2 - count1 + 1));
		if (str)
			ft_strlcpy(str, &s1[count1], count2 - count1 + 1);
	}
	return (str);
}
