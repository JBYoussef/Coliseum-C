/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:57:41 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/15 15:58:26 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_condition(char big, char little, size_t count2, size_t len)
{
	return ((big == little) && (count2 < len) && big != '\0');
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	count2;
	size_t	count_lil;

	if (*little == '\0')
		return ((char *)big);
	count = 0;
	count2 = 0;
	while (count < len && big[count])
	{
		count_lil = 0;
		if (big[count] == little[count_lil])
		{
			count2 = count;
			while (ft_condition(big[count2], little[count_lil], count2, len))
			{
				count_lil++;
				count2++;
			}
			if (little[count_lil] == '\0')
				return ((char *)(big + count2 - count_lil));
		}
		count++;
	}
	return (NULL);
}
