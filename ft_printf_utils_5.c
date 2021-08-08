/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 21:45:52 by ade-agui          #+#    #+#             */
/*   Updated: 2021/08/07 21:45:53 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_precision_neg_zero_number_i_d(t_flags fl, int size, int *len)
{
	ft_putchar_len('-', len);
	while (fl.precision - (size - 1) > 0)
	{
		write(1, "0", 1);
		fl.precision--;
		(*len)++;
	}
	ft_putstr_len(fl.strNum, len);
}

void	print_width_neg_zero_number_i_d(t_flags fl, int size, int *len)
{
	ft_putchar_len('-', len);
	while (fl.width - (size - 1) > 0)
	{
		write(1, "0", 1);
		fl.width--;
		(*len)++;
	}
	ft_putstr_len(fl.strNum, len);
}

void	print_neg_precision_zero_number_i_d(t_flags fl, int size, int *len)
{
	ft_putchar_len('-', len);
	while (fl.precision > size - 1)
	{
		write(1, "0", 1);
		fl.precision--;
		(*len)++;
	}
	ft_putstr_len(fl.strNum, len);
}

void	print_neg_prec_zero_number_space_i_d(t_flags fl, int size, int *len)
{
	print_neg_precision_zero_number_i_d(fl, size, len);
	while (fl.width - (size - 1) > 0)
	{
		write(1, " ", 1);
		fl.width--;
		(*len)++;
	}
}

void	print_neg_number_space_i_d(t_flags fl, int size, int *len)
{
	print_neg_number_i_d(fl, len);
	print_space(fl, size, len);
}
