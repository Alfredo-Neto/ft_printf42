/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:43:08 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/12 15:27:24 by ade-agui         ###   ########.fr       */
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

static void handle_types(int *len, va_list args, t_flags fl)
{
    if (fl.type == 'c')
        print_c(va_arg(args, int), len);
    if (fl.type == 's')
        print_s(va_arg(args, char *), len);
    if (fl.type == 'i' || fl.type == 'd' || fl.type == 'u')
        print_int(fl, args, len);
    // if (fl.type == 'p')
    //    print_c  = va_arg(args, char *);
    // write(1, &print_c, 1);
    // if (fl.type == 'x')
    //    print_c  = va_arg(args, char *);
    // write(1, &print_c, 1);
    // if (fl.type == 'X')
    //    print_c  = va_arg(args, char *);
    // write(1, &print_c, 1);
    // if (fl.type == '%')
    //    print_c  = va_arg(args, char *);
    // write(1, &print_c, 1);
}

static void get_specs(const char *format, int  *i, int *len, va_list args) {
    t_flags fl;
    if (ft_strchr_01(CONVERSIONS, format[*i]))
    {
         fl.type = format[(*i)++];
         handle_types(len, args, fl);
    }    
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
            get_specs(format, &i, &len, args);
            if (len == -1)
				return (-1); // %[flags][width][.precision][size]type -> "hello" "    hello"
        }
    }
    va_end(args);
    return(len);
}

int main (void)
{
   
   int number1;
   int number2;
   int tamanho;
   
   number1 = 15;
   number2 = 16;
   tamanho = ft_printf("%i%i", number1, number2);
   ft_printf("\n");
   ft_printf("tamanho é: %i", tamanho);
   ft_printf("\n");


    // int tamanho;
   
    // tamanho = ft_printf("Hello %c - ", 'A');
    // printf("%d", tamanho);
    // printf("\n");

    // int tamanho;
   
    // tamanho = ft_printf("Hello %s - ", "Alexandre e Jorge");
    // printf("%d", tamanho);
    // printf("\n");
   
    return (0);
}



// 1 coisa: tratar e printar o char
// ao encontrar a flag, tratar e printar 
// começar com o char, depois string

// if (format[*i] != '%') // 

// gera_flags(format, &i, tamanho, args); //
