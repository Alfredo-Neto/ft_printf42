/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:42:54 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/14 18:52:13 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_int_to_hex_px(va_arg(args, unsigned long int), fl);
	ft_putstr_len(fl.strNum, len);
	free(fl.strNum);
}

void	print_X(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_int_to_hex_px(va_arg(args, unsigned long int), fl);
	ft_putstr_len(fl.strNum, len);
	free(fl.strNum);
}

void print_pct(int *len)
{
	ft_putstr_len("%", len);
}