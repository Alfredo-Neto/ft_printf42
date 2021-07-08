/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:35:19 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/08 17:54:28 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "stdlib.h"
# include "string.h"


# define CONVERSIONS	"cspdiuxX%"
# define ALL_FLAGS "-0.*0123456789cspdiuxX%"

typedef struct {
    char type;
    int width;
    int precision;
} t_flags;

int ft_printf(const char *format, ...);
void	ft_putchar_len(char c, int *len);
int		ft_strchr_01(char *s, char c);
void		print_spec_c(char c, int len, va_list args);

#endif