/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:20:41 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/23 12:20:43 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	args;
	t_flags	flags;

	va_start(args, str);
	flags.cont = 0;
	flags.p_chars = 0;
	flags.fd = fd;
	while (str[flags.cont])
	{
		if (str[flags.cont] == '%')
		{
			ft_print_porcent(str, &flags);
			ft_print_ptr(str, args, &flags);
			ft_print_chars(str, args, &flags);
			ft_print_char(str, args, &flags);
			ft_print_nums(str, args, &flags);
		}
		else
		{
			ft_print_car(fd, str[flags.cont++]);
			flags.p_chars++;
		}
	}
	va_end(args);
	return (flags.p_chars);
}
