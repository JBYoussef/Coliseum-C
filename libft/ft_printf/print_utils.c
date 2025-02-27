/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_car.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:10:34 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/23 12:10:49 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_car(int fd, char c)
{
	write (fd, &c, 1);
}

void	ft_print_str(int fd, char *str)
{
	if (str == NULL)
		ft_fprintf(fd, "(null)");
	while (str && *str)
		ft_print_car(fd, *str++);
}

void	ft_print_num_s(int fd, int nb)
{
	if (nb == -2147483648)
	{
		ft_print_str(fd, "-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_print_car(fd, '-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_print_num_s(fd, nb / 10);
		ft_print_num_s(fd, nb % 10);
	}
	else
		ft_print_car(fd, nb + 48);
}

void	ft_print_uns(int fd, unsigned int nb)
{
	if (nb >= 10)
	{
		ft_print_num_s(fd, nb / 10);
		ft_print_num_s(fd, nb % 10);
	}
	else
		ft_print_car(fd, nb + 48);
}

void	ft_print_hex(int fd, uintptr_t numb, char c)
{
	char		*num;
	char		*hexa;
	char		temp;
	int			cont;

	cont = 0;
	num = (char *)malloc(17);
	hexa = "0123456789abcdef";
	if (numb == 0)
	{
		ft_print_car(fd, '0');
		free(num);
		return ;
	}
	while (numb)
	{
		temp = hexa[numb % 16];
		if (c == 'X' && (temp >= 'a' && temp <= 'z'))
			temp -= 32;
		num[cont++] = temp;
		numb /= 16;
	}
	while (cont > 0)
		ft_print_car(fd, num[--cont]);
	free(num);
}
