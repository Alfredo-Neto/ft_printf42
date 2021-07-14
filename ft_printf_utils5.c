/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:53:22 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/14 18:53:29 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int        len_hex(unsigned long int x)
{
    int len;
    
    len  = 0;
    while (x)
    {
        x = x / 16;
        len++;
    }
    return (len);
}

void	ft_putstr_len_p(char *s, int *len)
{
	int i;

	write(1, "0", 1);
	write(1, "x", 1);
	if (s != NULL)
	{
		i = 0;
		while (s[i])
			ft_putchar_len(s[i++], len);
	}
}

char    *ft_int_to_hex_px(unsigned long int n, t_flags fl)
{ 
    int len;
    char *result;

    len = len_hex(n);
    result = (char *)malloc(len + 1);
    if (result == NULL)
        return (0);
    result[len--] = '\0';
    while (len >= 0)
    {
        int temp;

        temp = n % 16;
        if (temp < 10) 
            result[len--] = temp + 48;
        else 
		{
			if (fl.type == 'x' || fl.type == 'p')
            	result[len--] = temp + 87;
			else
				result[len--] = temp + 55; // maiusculo
		}
        n = n / 16;
    }
    return (result);    
}