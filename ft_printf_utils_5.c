/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:58:17 by ade-agui          #+#    #+#             */
/*   Updated: 2021/08/05 22:58:28 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
