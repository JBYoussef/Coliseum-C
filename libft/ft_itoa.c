/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:05:21 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/22 15:05:24 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		n_copy;
	int		n_size;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_copy = n;
	if (n < 0)
		n_copy = -n;
	n_size = int_len(n);
	str = (char *)ft_calloc(n_size + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[n_size] = '\0';
	n_size--;
	if (n_copy == 0)
		str[n_size] = '0';
	while (n_copy > 0)
	{
		str[n_size--] = (n_copy % 10) + '0';
		n_copy /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
