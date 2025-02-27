/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:54:21 by jbofengo          #+#    #+#             */
/*   Updated: 2024/06/07 13:54:35 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num_i(int fd, va_list args, int *p_chars, int *cont)
{
	int	next_int;
	int	num_len;
	int	temp;

	num_len = 0;
	next_int = va_arg(args, int);
	ft_print_num_s(fd, next_int);
	if (next_int == 0)
		num_len = 1;
	else
	{
		temp = next_int;
		if (temp < 0)
		{
			num_len++;
			temp = -temp;
		}
		while (temp)
		{
			num_len++;
			temp /= 10;
		}
	}
	(*p_chars) += num_len;
	(*cont) += 2;
}

void	ft_print_num_u(int fd, va_list args, int *p_chars, int *cont)
{
	unsigned int	next_uns;
	int				num_len;
	unsigned int	temp;

	num_len = 0;
	next_uns = va_arg(args, unsigned int);
	ft_print_uns(fd, next_uns);
	if (next_uns == 0)
		num_len = 1;
	else
	{
		temp = next_uns;
		while (temp)
		{
			num_len++;
			temp /= 10;
		}
	}
	(*p_chars) += num_len;
	(*cont) += 2;
}

void	ft_print_num_x(int c, va_list args, t_flags **flags)
{
	int				num_len;
	unsigned int	next_uns;

	num_len = 0;
	next_uns = va_arg(args, unsigned int);
	ft_print_hex((*flags)->fd, next_uns, c);
	if (next_uns == 0)
		num_len = 1;
	while (next_uns)
	{
		num_len++;
		next_uns /= 16;
	}
	(*flags)->p_chars += num_len;
	(*flags)->cont += 2;
}

void	ft_print_char(const char *str, va_list args, t_flags *flags)
{
	char	next_car;

	if (str && str[flags->cont + 1] == 'c')
	{
		next_car = (char)va_arg(args, int);
		ft_print_car(flags->fd, next_car);
		flags->p_chars++;
		flags->cont += 2;
	}
}
