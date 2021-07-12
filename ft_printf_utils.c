/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:44:20 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/12 19:17:50 by ade-agui         ###   ########.fr       */
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
}

void print_u(t_flags fl, va_list args, int *len)
{
	fl.strNum = ft_uitoa(va_arg(args, int));
	ft_putstr_len(fl.strNum, len);
}

//para imprimir integer:
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++))
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putstr_len(char *s, int *len)
{
	int i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
			ft_putchar_len(s[i++], len);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n <= 9 && n >= 0)
		ft_putchar(n + 48);
	else if (n > 0)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
}

int	ft_len(int num)
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

int	ft_to_positive(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*result;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_len(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (0);
	result[len] = '\0';
	len--;
	while (len >= 0)
	{
		result[len] = '0' + ft_to_positive(n % 10);
		n = ft_to_positive(n / 10);
		len--;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}

static int	tamanho(unsigned int n)
{
	int tamanho;

	tamanho = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		tamanho++;
	}
	return (tamanho);
}

static int	potencia(int tamanho)
{
	int	pot;

	pot = 1;
	while (tamanho > 0)
	{
		pot = pot * 10;
		tamanho--;
	}
	return (pot);
}

char		*ft_uitoa(unsigned int n)
{
	char	*ret;
	int		pot;
	int		i;

	if (!(ret = (char*)malloc((tamanho(n) + 2) * sizeof(char))))
		return (NULL);
	i = 0;
	pot = potencia(tamanho(n) - 1);
	while (pot > 0)
	{
		ret[i++] = (n / pot % 10 + 48);
		pot = pot / 10;
	}
	ret[i] = '\0';
	return (ret);
}

