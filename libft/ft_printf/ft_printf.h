/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:03:17 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/23 12:09:59 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_flags
{
	int	p_chars;
	int	fd;
	int	cont;
}	t_flags;

int		ft_fprintf(int fd, const char *str, ...);

void	ft_print_car(int fd, char c);

void	ft_print_str(int fd, char *str);

void	ft_print_adress(int fd, void *address);

void	ft_print_num_s(int fd, int nb);

void	ft_print_uns(int fd, unsigned int nb);

void	ft_print_hex(int fd, uintptr_t numb, char c);

void	ft_print_chars(const char *str, va_list args, t_flags *flags);

void	ft_print_char(const char *str, va_list args, t_flags *flags);

void	ft_print_nums(const char *str, va_list args, t_flags *flags);

void	ft_print_porcent(const char *str, t_flags *flags);

void	ft_print_ptr(const char *str, va_list args, t_flags *flags);

void	ft_print_num_i(int fd, va_list args, int *p_chars, int *cont);

void	ft_print_num_u(int fd, va_list args, int *p_chars, int *cont);

void	ft_print_num_x(int c, va_list args, t_flags **flags);

#endif
