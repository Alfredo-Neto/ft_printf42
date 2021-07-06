/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:33:05 by ade-agui          #+#    #+#             */
/*   Updated: 2021/07/06 20:37:06 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_handle_percent(void)
{
    return (1);
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
            write(1, &format[i], 1);
            i++;
            len++;
        }
        else
        {
            i++;
            ft_handle_percent();  // %[flags][width][.precision][size]type -> "hello" "    hello"
        }
    }
    va_end(args);
    return(len);
}

int main(void)
{
    ft_printf("Hello World!");
}