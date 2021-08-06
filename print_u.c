/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:11:44 by azamario          #+#    #+#             */
/*   Updated: 2021/08/04 13:44:41 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(t_flags fl, va_list args, int *len)
{
	int	size;
	unsigned int number;
	int count;

	count = 0;
	number = va_arg(args, unsigned int);
	fl.strNum = ft_uitoa(number);
	size = (int)ft_strlen(fl.strNum);
	if (number == 0 && fl.dot == 1 && fl.precision == 0)
		print_zero_corner_case(fl, len, size);
	else if (fl.zero == 1 && fl.width > size && fl.precision == 0)
		print_u_zero_string(fl, len, size);
	else if (fl.width > size && fl.precision <= size)
		print_u_space_string(fl, len, size);
	else if (fl.precision > size)
	{
		if (fl.width > size && fl.minus == 1)
		{
			while (fl.precision - size > 0)
			{
				write(1, "0", 1);
				fl.precision--, (*len)++, count++;
			}
			ft_putstr_len(fl.strNum, len);
			while (fl.width - (fl.precision + count) > 0)
			{
				write(1, " ", 1);
				fl.width--, (*len)++;
			}
		}
		else if (fl.minus == 0 && fl.width > fl.precision)
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
		else
		{
			while (fl.precision - size > 0)
			{
				write(1, "0", 1);
				fl.precision--, (*len)++;
			}
			ft_putstr_len(fl.strNum, len);
		}
	}
	else
		ft_putstr_len(fl.strNum, len);
	free(fl.strNum);
}

void	print_zero_corner_case(t_flags fl, int *len, int size)
{
	int count;

	count = 0;

	if (fl.width > fl.precision)
	{
		if (fl.minus == 1)
		{
			while (fl.precision > 0)
			{
				write(1, "0", 1);
				fl.precision--, (*len)++, count++;
			}
			while (fl.width - (fl.precision + count) > 0)
			{
				write(1, " ", 1);
				fl.width--, (*len)++;
			}
		}
		else if (fl.minus == 0)
		{
			while (fl.width > fl.precision)
			{
				write(1, " ", 1);
				fl.width--, (*len)++;
			}
			while (fl.precision > 0)
			{
				write(1, "0", 1);
				fl.precision--, (*len)++;	
			}
		}
	}
	else if (fl.precision > fl. width)
	{ 
		while (fl.precision > 0)
		{
			write(1, "0", 1);
			fl.precision--, (*len)++;
		}
	}
	else if (fl.width > size)
	{
		if (fl.dot == 1)
		{
			while (fl.width > 1)
			{
				write(1, " ", 1);
				fl.width--, (*len)++;		
			}
		}
		else if (fl.zero == 0 || fl.minus == 1)
		{
			while (fl.width > 1)
			{
				write(1, " ", 1);
				fl.width--, (*len)++;		
			}
			ft_putstr_len(fl.strNum, len);
		}
		else
		{
			while (fl.width > 1)
			{
				write(1, "0", 1);
				fl.width--, (*len)++;		
			}
			ft_putstr_len(fl.strNum, len);
		}
	}
	else if (fl.precision > size)
	{
		while (fl.precision > 1)
		{		
			write(1, "0", 1);
			fl.precision--, (*len)++;		
		}
		ft_putstr_len(fl.strNum, len);
	}	
	else
		write(1, " ", 0);
}


void	print_u_space_string(t_flags fl, int *len, int size)
{
	if (fl.minus == 1)
	{
		ft_putstr_len(fl.strNum, len);
		print_space(fl, size, len);
	}
	else
	{
		print_space(fl, size, len);
		ft_putstr_len(fl.strNum, len);
	}
}

void	print_u_zero_string(t_flags fl, int *len, int size)
{	
	if (fl.minus == 0)
	{
		while (fl.width - size > 0)
		{
			write(1, "0", 1);
			fl.width--, (*len)++;
		}
		ft_putstr_len(fl.strNum, len);
	}
	else if (fl.minus == 1)
	{
		ft_putstr_len(fl.strNum, len);
		print_space(fl, size, len);
	}
}

int	ft_ulen(unsigned int num)
{
	size_t	len;

	if (num <= 0)
		len = 1;
	else
		len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*result;

	len = ft_ulen(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (0);
	result[len] = '\0';
	len--;
	while (len >= 0)
	{
		result[len] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (result);
}
