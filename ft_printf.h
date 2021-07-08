/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:35:19 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/07 23:30:27 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define CONVERSIONS	"cspdiuxX%"
# define FLAGS_AND_TYPES "-0.*0123456789cspdiuxX%"
# define NUMBERS "123456789"

typedef struct {
    char type;
    int width;
    int precision;
} Tipo;

int ft_printf(const char *format, ...);

#endif