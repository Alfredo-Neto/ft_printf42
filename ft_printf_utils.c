/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 00:56:42 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/08 01:28:12 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

int		ft_strchr_01(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}
void		print_spec_c(char c)
{
	ft_putchar_len(c);
}