/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:33:05 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/08 17:57:36 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int handle_types(const char *format, int *i, int len)
// {
//     // se format for '-' -> alinhar à esquerda
//     if (format[*i] == '-')
//         ft_strtrim(format[*i], ' '); //hello
//     else if (format[*i] == '0' && NUMBERS) // -0.*cspdiuxX%
//     {
        
//     }
// }

// static int trata_tipo(Tipo opcao, char character)
// {
//     if (opcao.type == 's')
//         character = handle_types(opcao.type);
// }

static void types_identifier(const char *format, int *i, int *len, va_list args)
{
    char *print_c;
    t_flags fl;
    if (format[*i] != '%')
    {
       if (ft_strchr_01(CONVERSIONS, format[*i]))
       {
            fl.type = format[(*i)++]; // 'A' // "%c"
            if (fl.type == 'c')
               print_c  = va_arg(args, char *);
            write(1, &print_c, 1);
            if (fl.type == 's')
               print_c  = va_arg(args, char *);
            write(1, &print_c, 1);
            if (fl.type == 'p')
               print_c  = va_arg(args, char *);
            write(1, &print_c, 1);
            if (fl.type == 'd')
               print_c  = va_arg(args, char *);
            write(1, &print_c, 1);
            if (fl.type == 'u')
               print_c  = va_arg(args, char *);
            write(1, &print_c, 1);
            if (fl.type == 'x')
               print_c  = va_arg(args, char *);
            write(1, &print_c, 1);
            if (fl.type == 'X')
               print_c  = va_arg(args, char *);
            write(1, &print_c, 1);
            if (fl.type == '%')
               print_c  = va_arg(args, char *);
            write(1, &print_c, 1);
       }
    }
    else
		(*len) = -1;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int len;
    int i;

    va_start(args, format);
    len = 0;
    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] != '%')
            ft_putchar_len(format[i++], &len); // tamanho = hello %-s, name // 7
        else
        {
            i++;
            types_identifier(format, &i, &len, args);
            if (len == -1)
				return (-1);  // %[flags][width][.precision][size]type -> "hello" "    hello"
        }
    }
    va_end(args);
    return(len);
}

int main (void)
{

    ft_printf("Hello %s", "Jorge e Alexandre");
    ft_printf("\n");
    return (0);
}
// 1 coisa: tratar e printar o char
// ao encontrar a flag, tratar e printar 
// começar com o char, depois string

// if (format[*i] != '%') // 

// gera_flags(format, &i, tamanho, args); //

