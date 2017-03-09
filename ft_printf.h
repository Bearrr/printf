/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:13:58 by ireva             #+#    #+#             */
/*   Updated: 2017/03/09 13:52:42 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_flags
{
	int hash;
	int zero;
	int plus;
	int minus;
	int space;
	int accuracy;
	int width;
	char *letter;
}				t_flags;

char    *ft_itoa_base(intmax_t nbr, int base, int flag);
char    *ft_itoa(int nbr);
char    *my_ft_itoa(long int n, int flag);
t_flags	check_flags(char *format, int x);
int		my_ft_strchr(const char *s, int c, int n);
int		width_work(t_flags flag, intmax_t i);
int		accuracy_work(t_flags flag, int i);
void	check_s_flags(char * format, int x, t_flags *flag);
int		use_d_flags(t_flags flag, int f, va_list ap, int size);
int		type_d(intmax_t i, t_flags flag);
int		use_u_flags(t_flags flag, int f, va_list ap, int size);
int		type_u(uintmax_t i, t_flags flag);
char	*ft_uitoa_base(uintmax_t nbr, int base, int flag);
int		type_x(uintmax_t x, t_flags flag, int size);
int		use_x_flags(t_flags flag, int f, va_list ap, int size);
int		type_o(uintmax_t i, t_flags flag);
int		use_o_flags(t_flags flag, int f, va_list ap, int size);
int		int_len(intmax_t nbr, int base);
int		use_s_flags(t_flags flag, int f, va_list ap, int size);
int		type_s(char *str, t_flags flag);
int		use_c_flags(t_flags flag, int f, va_list ap);
int		type_c(char c, t_flags flag);
int		use_p_flags(t_flags flag, int f, va_list ap);
int		type_p(void *x, t_flags flag);
int		wr_accuracy(t_flags flag, intmax_t i, int f, char **number);
int		wr_uaccuracy(t_flags flag, uintmax_t i, int f);
int		uaccuracy_work(t_flags flag, int i);
int		uwidth_work(t_flags flag, uintmax_t i, int fleg);
int		saccuracy_work(t_flags flag, char *number);
int		swidth_work(t_flags flag, char *number, int fleg);
int		wr_saccuracy(t_flags flag, uintmax_t i, int f, char *number);
int 	str_accuracy_work(t_flags flag, char *number);
int		wr_str_accuracy(t_flags flag, int f, char *number);
int		str_width_work(t_flags flag, char *number, int fleg);
int 	c_accuracy_work(t_flags flag, char number);
int		wr_c_accuracy(t_flags flag, int f);
int		c_width_work(t_flags flag, int fleg);
int 	o_uaccuracy_work(t_flags flag, char *number, char fleg);
int		wr_o_uaccuracy(t_flags flag, char *number, int f, char fleg);
int		o_uwidth_work(t_flags flag, char *number, char fleg);
int		int_lens(uintmax_t nbr, int base);
char	my_ft_isprint(char *str, int x);
int		ustr_width_work(t_flags flag, char *number, int fleg);

#endif
