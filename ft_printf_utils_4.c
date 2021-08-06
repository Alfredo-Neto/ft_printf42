/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:32:13 by ade-agui          #+#    #+#             */
/*   Updated: 2021/08/05 22:37:07 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_precision_zero_number(t_flags fl, int size, int *len)
{
	while (fl.precision - size > 0)
	{
		write(1, "0", 1);
		fl.precision--, (*len)++;
	}
	ft_putstr_len(fl.strNum, len);
}

void print_number_space(t_flags fl, int size, int *len)
{
	ft_putstr_len(fl.strNum, len);
	while (fl.width - size > 0)
	{
		write(1, " ", 1);
		fl.width--, (*len)++;
	}
}

void print_space_number(t_flags fl, int size, int *len)
{
	while (fl.width - size > 0)
	{
		write(1, " ", 1);
		fl.width--, (*len)++;
	}
	ft_putstr_len(fl.strNum, len);
}


void print_width_zero_number(t_flags fl, int size, int *len)
{
	while (fl.width - size > 0)
	{
		write(1, "0", 1);
		fl.width--, (*len)++;
	}
	ft_putstr_len(fl.strNum, len);   
}
	
void print_precision_zero_number(t_flags fl, int size, int *len)
{
	while (fl.precision - size > 0)
	{
		write(1, "0", 1);
		fl.precision--, (*len)++;
	}
	ft_putstr_len(fl.strNum, len);
}
 	  			
void print_precision_zero_number_space(t_flags fl, int size, int *len, int i)
{
	while (fl.precision - size > 0)
	{
		write(1, "0", 1);
		fl.precision--, (*len)++, i++;
	}
	ft_putstr_len(fl.strNum, len);
	while (fl.width - (fl.precision + i) > 0)
	{
		write(1, " ", 1);
		fl.width--, (*len)++;
	}
}	
	  			
void print_precision_zero_number_difference_width_precision(t_flags fl, int size, int *len)
{
	while (fl.precision - size > 0)
	{
	    write(1, "0", 1);
	    fl.precision--, (*len)++;
	}
	ft_putstr_len(fl.strNum, len);
	while (fl.width - fl.precision > 0)
	{
		write(1, " ", 1);
		fl.width--, (*len)++;
	}
}

void print_difference_width_precision_zero_number(t_flags fl, int size, int *len)
{
	while (fl.width - fl.precision > 0)
	{
		write(1, " ", 1);
		fl.width--, (*len)++;
	}
	while (fl.precision - size > 0)
	{
	    write(1, "0", 1);
	    fl.precision--, (*len)++;
	}
	ft_putstr_len(fl.strNum, len);
}

void print_xX_corner_cases(t_flags fl, int size, int *len)
{
	int i;

	i = 0;
	if (fl.minus == 1)
	{
		if (fl.width == fl.precision)
			print_precision_zero_number(fl, size, len);
		else if (fl.width > fl.precision)
			print_precision_zero_number_space(fl, size, len, i);
		else
			print_precision_zero_number_difference_width_precision(fl, size, len);
	}
	else
		print_difference_width_precision_zero_number(fl, size, len);

}