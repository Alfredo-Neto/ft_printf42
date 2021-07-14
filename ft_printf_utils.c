/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:44:20 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/14 19:22:49 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_c(char c, int *len)
{
	ft_putchar_len(c, len);
}

void		print_s(char *c, int *len)
{
	ft_putstr_len(c, len);
}

void print_i_d(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_itoa(va_arg(args, int));
	ft_putstr_len(fl.strNum, len);
	free(fl.strNum);
}

void print_u(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_uitoa(va_arg(args, int));
	ft_putstr_len(fl.strNum, len);
	free(fl.strNum);
}

void print_p(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_int_to_hex_px(va_arg(args, unsigned long int), fl);
	ft_putstr_len_p(fl.strNum, len);
	free(fl.strNum);
}
