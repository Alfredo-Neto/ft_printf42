/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:17:05 by azamario          #+#    #+#             */
/*   Updated: 2021/08/05 22:41:41 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_xX(t_flags fl, va_list args, int *len, const char c)
{
	verify_xX(fl, args, len, c);
    free(fl.strNum);
}

void verify_xX(t_flags fl, va_list args, int *len, const char c)
{
	int size;
	fl.ulli = va_arg(args, unsigned int);		
    if (c == 'X')
        fl.strNum = ft_ullitoa_base(fl.ulli, HEXAUPP);
    else if (c == 'x')
        fl.strNum = ft_ullitoa_base(fl.ulli, HEXALOW);
    size = (int)ft_strlen(fl.strNum);
	if (fl.ulli == 0 && fl.dot == 1 && fl.precision == 0)
		print_zero_corner_case(fl, len, size);
    else if ((fl.width == 0 || fl.width <= size) && (fl.precision == 0 || fl.precision <= size))
        ft_putstr_len(fl.strNum, len);
    else if ((fl.width == 0 || fl.width <= size) && (fl.precision  > size))
		print_precision_zero_number(fl, size, len);
    else if (fl.width > size && (fl.precision == 0 || fl.precision <= size))   
    {
        if (fl.minus == 1)
			print_number_space(fl, size, len);
		else if (fl.zero == 0 || (fl.zero == 1 && fl.dot == 1))
			print_space_number(fl, size, len);
      	else
			print_width_zero_number(fl, size, len);
	}
    else if (fl.width > size && fl.precision > size)
		print_xX_corner_cases(fl, size, len);
}

int	ft_len_hex(unsigned long int x)
{
	int	len;

	len = 0;
	while (x)
	{
		x = x / 16;
		len++;
	}
	return (len);
}
                         
char        *ft_ullitoa_base(unsigned long long int n, char *base)
{
    char                 	   *a;
    unsigned long long int 	   nbr;
    size_t                 	   size;
    int                        b_len;

    b_len = ft_strlen(base);
    nbr = n;
    size = 1;
    while (n /= b_len)
        size++;
    if (!(a = (char *)malloc(size + 1)))
        return (0);
    a[size--] = '\0';
    while (nbr > 0)
    {
        a[size--] = base[nbr % b_len];
        nbr /= b_len;
    }
    if (size == 0 && a[1] == '\0')
        a[0] = '0';
    return (a);
}
