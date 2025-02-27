/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:29:05 by jbofengo          #+#    #+#             */
/*   Updated: 2024/06/06 14:30:13 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_adress(int fd, void *address)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)address;
	ft_print_hex(fd, ptr, 'x');
}

void	ft_print_ptr(const char *str, va_list args, t_flags *flags)
{
	uintptr_t	temp;
	void		*next_ptr;

	if (str[flags->cont + 1] == 'p')
	{
		next_ptr = va_arg(args, void *);
		if (next_ptr == NULL)
		{
			ft_print_str(flags->fd, "(nil)");
			flags->p_chars += 5;
		}
		else
		{
			ft_print_str(flags->fd, "0x");
			flags->p_chars += 2;
			ft_print_adress(flags->fd, next_ptr);
			temp = (uintptr_t)next_ptr;
			while (temp)
			{
				flags->p_chars++;
				temp /= 16;
			}
		}
		flags->cont += 2;
	}
}

void	ft_print_chars(const char *str, va_list args, t_flags *flags)
{
	char	*next_str;
	int		counter;

	counter = 0;
	if (str[flags->cont + 1] == 's')
	{
		next_str = va_arg(args, char *);
		if (!next_str)
		{
			ft_print_str(flags->fd, "(null)");
			flags->p_chars += 6;
		}
		else
		{
			ft_print_str(flags->fd, next_str);
			while (next_str[counter])
				counter++;
			flags->p_chars += counter;
		}
		flags->cont += 2;
	}
}

void	ft_print_nums(const char *str, va_list args, t_flags *flags)
{	
	if (str[flags->cont + 1] == 'x' || str[flags->cont + 1] == 'X')
	{
		ft_print_num_x(str[flags->cont + 1], args, &flags);
	}
	else if (str[flags->cont + 1] == 'i' || str[flags->cont + 1] == 'd')
	{
		ft_print_num_i(flags->fd, args, &flags->p_chars, &flags->cont);
	}
	else if (str[flags->cont + 1] == 'u')
	{
		ft_print_num_u(flags->fd, args, &flags->p_chars, &flags->cont);
	}
}

void	ft_print_porcent(const char *str, t_flags *flags)
{
	if (str[flags->cont + 1] == '%')
	{
		flags->p_chars++;
		ft_print_car(flags->fd, '%');
		flags->cont += 2;
	}
}
