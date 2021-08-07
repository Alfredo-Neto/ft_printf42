/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:03:26 by azamario          #+#    #+#             */
/*   Updated: 2021/08/07 11:11:29 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(t_flags fl, int size, int *len)
{
	if (fl.precision > 0 && fl.width > size)
	{
		while (fl.width - size > 0)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
	}
	else if (fl.precision > 0)
		print_simple_space_precision_i_d(fl, size, len);
	else
	{
		while (fl.width - size > 0)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
	}
}

void	print_simple_space_width_i_d(t_flags fl, int size, int *len)
{
	while (fl.width - size > 0)
	{
		write(1, " ", 1);
		fl.width--;
		(*len)++;
	}
}

void	print_space_or_zero_number_i_d(t_flags fl, int size, int *len)
{
	if (fl.minus == 1)
	{
		check_for_plus_and_space_i_d(fl, len);
		ft_putstr_len(fl.strNum, len);
		print_simple_space_width_i_d(fl, size, len);
	}
	else if (fl.zero == 0 || (fl.zero == 1 && fl.dot == 1))
	{
		print_simple_space_width_i_d(fl, size, len);
		check_for_plus_and_space_i_d(fl, len);
		ft_putstr_len(fl.strNum, len);
	}
	else
		print_width_zero_i_d(fl, size, len);
}

void	print_space_neg_number_i_d(t_flags fl, int size, int *len)
{
	print_space(fl, size, len);
	ft_putchar_len('-', len);
	ft_putstr_len(fl.strNum, len);
}

void	print_simple_space_width_precision_i_d(t_flags fl, int *len)
{
	while (fl.width - fl.precision > 0)
	{
		write(1, " ", 1);
		fl.width--;
		(*len)++;
	}
}
