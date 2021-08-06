/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-agui <ade-agui@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:24:14 by azamario          #+#    #+#             */
/*   Updated: 2021/08/05 22:41:59 by ade-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "stdlib.h"
# include "string.h"
# include <limits.h>

# define FLAGS			"-0.0123456789"
# define NUMBERS		"0123456789"
# define TYPES			"csidupxX%"


# define HEXALOW    "0123456789abcdef"
# define HEXAUPP    "0123456789ABCDEF" 

typedef struct t_flags
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	char	*strNum;

	unsigned long long int    ulli;
    long long int            lli;			// <--- ?
	
}	t_flags;

int	ft_printf(const char *format, ...);

// utils
void	ft_putchar_len(char c, int *len);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);

//utils_2
void	ft_putnbr(int n);
int		ft_len(int num);
//int		ft_to_positive(int num);
char	*ft_itoa(int n);

//utils_3
t_flags	ft_clean_flags(void);
void	ft_putstr_len(char *s, int *len);

//print_c
void	print_c(char c, int *len, t_flags fl);

//print_s
void	print_s(char *c, int *len, t_flags fl);
void	print_s_space_print(char *c, int *len, t_flags fl);
void	print_s_space_cut(char *c, int *len, t_flags fl);
void	print_s_space_cut_right(char *c, int *len, t_flags fl);
void	print_s_space_cut_left(char *c, int *len, t_flags fl);



//print_id
void	print_i_d(t_flags fl, va_list args, int *len);
void	print_space(t_flags fl, int size, int *len);
void	print_simple_space(t_flags fl, int size, int *len);							//<-----

void	print_i_d_zero(t_flags fl, int size, int *len);
void	print_width_zero(t_flags fl, int size, int *len);							//<-----
void	print_precision_zero(t_flags fl, int size, int *len);							//<-----
void	print_space_or_zero_number(t_flags fl, int size, int *len);
void	print_zero_number_space(t_flags fl, int size, int *len, int *i);			//<-----
void	print_corner_cases(t_flags fl, int size, int *len);


void	print_neg_zero_number(t_flags fl, int size, int *len);
void	print_space_neg_number(t_flags fl, int size, int *len);









//print_u
void	print_u(t_flags fl, va_list args, int *len);
void	print_u_space_string(t_flags fl, int *len, int size);
void	print_u_zero_string(t_flags fl, int *len, int size);
int		ft_ulen(unsigned int num);
char	*ft_uitoa(unsigned int n);
void	print_zero_corner_case(t_flags fl, int *len, int size);


//print_p
void	print_p(t_flags fl, va_list args, int *len, const char c);
void	print_p_no_zero(t_flags fl, int *len, int size);
void	print_p_zero(t_flags fl, int *len, int size);
void	ft_putstr_len_p(char *s, int *len);
char	*ft_int_to_hex_p(unsigned long int n, const char c);


void    print_xX(t_flags fl, va_list args, int *len, const char c);


void	print_xX_right_aligned(t_flags fl, int *len, int size);
int		ft_len_hex(unsigned long int x);
char	*ft_int_to_hex_pxX(unsigned long int n, const char c);

char    *ft_ullitoa_base(unsigned long long int n, char *base);

int	return_hex_len(int num);


void	print_id_positive(t_flags fl, int number, int *len);
void	print_id_negative(t_flags fl, int number, int *len);


// print_xX
void	print_precision_zero_number(t_flags fl, int size, int *len);
void 	print_number_space(t_flags fl, int size, int *len);
void 	print_space_number(t_flags fl, int size, int *len);
void	print_width_zero_number(t_flags fl, int size, int *len);
void	print_precision_zero_number(t_flags fl, int size, int *len);
void	print_precision_zero_number_space(t_flags fl, int size, int *len, int i);
void	print_precision_zero_number_difference_width_precision(t_flags fl, int size, int *len);
void	print_difference_width_precision_zero_number(t_flags fl, int size, int *len);
void	print_xX_corner_cases(t_flags fl, int size, int *len);
void	verify_xX(t_flags fl, va_list args, int *len, const char c);

#endif
