/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:33:05 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/07 23:40:20 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_flags_and_types(const char *format, int *i, int len)
{
    // se format for '-' -> alinhar à esquerda
    if (format[*i] == '-')
        ft_strtrim(format[*i], ' '); //hello
    else if (format[*i] == '0' && NUMBERS) // -0.*cspdiuxX%
    {
        
    }
}

static int trata_tipo(Tipo opcao, char character)
{
    if (opcao.type == 's')
        character = handle_types(opcao.type);
}

static int flags_and_types_identifier(const char *format, int *i, int len)
{
    // conta todos os tipos e flags e retorna a impressão correta e o len
    if (format[*i] != '%')
    {
       while (ft_strchr(FLAGS_AND_TYPES, format[*i]))
        {
            // chama funcao para tratar as flags
            len = handle_flags_and_types(format[*i], &i, len);
        }
    }
    return (len);
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
        {
            ft_putchar_len(format[i], len); // tamanho = hello %-s, name // 7
            i++;
            len++;
        }
        else
        {
            i++;
            flags_and_types_identifier(format, &i, len);  // %[flags][width][.precision][size]type -> "hello" "    hello"
        }
    }
    va_end(args);
    return(len);
}

// 1 coisa: tratar e printar o char
// ao encontrar a flag, tratar e printar 
// começar com o char, depois string

// if (format[*i] != '%') // 

// gera_flags(format, &i, tamanho, args); //

