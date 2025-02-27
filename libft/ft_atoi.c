/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:54:18 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/21 11:03:31 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	count;
	int	numb;
	int	low;

	count = 0;
	low = 1;
	numb = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || (nptr[count] == 32))
		count++;
	if (nptr[count] == '+' || nptr[count] == '-')
	{
		if (nptr[count] == '-')
			low = -1;
		count++;
	}
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		numb = (10 * numb) + (nptr[count] - 48);
		count++;
	}
	return (numb * low);
}
