/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:44:49 by ireva             #+#    #+#             */
/*   Updated: 2017/03/09 13:57:39 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int		check_type2(char *format, int x)
{
	int i;

	i = 0;
	while (x > i)
	{
		if (ft_strchr("hljz", format[i]) &&  format[i] != ' ')
			return(1);
		i++;
	}
	return (0);
}
int		check_type(char *format, int x)
{
	int i;

	i = 0;
	while (x > i)
	{
		if (ft_strchr("sSpdDioOuUxXcC", format[i]))
			return(1);
		i++;
	}
	i = 0;
	while (x > i)
	{
		if (!ft_strchr("hljz", format[i]) &&  format[i] != ' ')
			return(1);
		i++;
	}
	return (0);
}
	
int		check_format(char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			return(0);
		i++;
	}
	return (1);
}

int		check_percent(char *format)
{
	int j;
	int i;

	i = 0;
	if (format[i + 1] == '\0')
		return (1);
	j = 1;
	i++;
	while (ft_strchr("#0-+ .", format[i]) || ft_strchr("hljz", format[i]) 
		   || (format[i] >= 48 && format[i] <= 57))
	{
		if (format[i + 1] == '\0')
			break ;
		i++;
		j++;
	}
	if (ft_strchr("sSpdDioOuUxXcC", format[i]))
		j++;
	return (j);
}

int		type_p(void *x, t_flags flag)
{
	int f;
    char *number;
	long int i;
	int j;


	i = (long)x;
	f = 0;
	number = ft_uitoa_base(i, 16, 0);
	f = wr_saccuracy(flag, i, f, number);
	if (flag.accuracy == -1 && i == 0)
	{
		if (flag.width == 0)
			return (f);
		else
		{
			f = ustr_width_work(flag, "\0", 0) + f;
			return (f);
		}
	}
	f = saccuracy_work(flag, number) + f;
	j = 0;
	while (number[j])
    {
        write(1, &number[j], 1);
        j++;
        f++;
    }
	if (flag.minus != 0)
		f = swidth_work(flag, number, 1) + f;
	if (number != NULL)
		free(number);
    return(f);
}

int     type_c(char c, t_flags flag)
{
	int f;

	f = 0;
	f = wr_c_accuracy(flag, f);
//	f = c_accuracy_work(flag, c) + f;
    ft_putchar(c);
	f++;
	if (flag.minus != 0)
		f = c_width_work(flag, c) + f;
    return(f);
}

int     type_o(uintmax_t i, t_flags flag)
{
    int f;
    char *number;
	int j;


    f = 0;
	j = 0;
	number = NULL;
	if (flag.accuracy == -1 && i == 0 && flag.hash == 0)
	{
		if (flag.width == 0)
			return (f);
		else
		{
			f = ustr_width_work(flag, "\0", 0) + f;
			return (f);
		}
	}
	if (flag.hash != 0 || flag.accuracy != 0)
		flag.zero = 0;
    number = ft_uitoa_base(i, 8, 2);
	f = wr_o_uaccuracy(flag, number, f, 'o') + f;
	f = o_uaccuracy_work(flag, number, 'o') + f;
    while (number[j])
    {
        write(1, &number[j], 1);
        j++;
        f++;
    }
	if (flag.minus != 0)
		f = o_uwidth_work(flag, number, 'o') + f;
	if (number != NULL)
		free(number);
    return(f);
}
int		type_x(uintmax_t x, t_flags flag, int size)
{
	int f;
    char *number;
	int i;

    f = 0;
	i = 0;
	number = NULL;
	if (flag.accuracy == -1 && x == 0)
	{
		if (flag.width == 0)
			return (f);
		else
		{
			f = ustr_width_work(flag, "\0", 0) + f;
			return (f);
		}
	}
	if (size == 0)
		number = ft_uitoa_base(x, 16, 0);
	if (size == 1)
		number = ft_uitoa_base(x, 16, 1);
	if ((flag.hash != 0 && x != 0 && flag.width == 0) 
		|| (flag.hash != 0 && flag.zero !=  0))
	{
		if (size == 0)
			write(1, "0x", 2);
		if (size == 1)
			write(1, "0X", 2);
		f = f + 2;
	}
	f = wr_o_uaccuracy(flag, number, f, 'x');
	f = o_uaccuracy_work(flag, number, 'x') + f;
	if (flag.hash != 0 && x != 0 && flag.width != 0 && flag.zero == 0)
	{
		if (size == 0)
			write(1, "0x", 2);
		if (size == 1)
			write(1, "0X", 2);
		f = f + 2;
	}
    while (number[i])
    {
        write(1, &number[i], 1);
        i++;
        f++;
    }
	if (flag.minus != 0)
		f = o_uwidth_work(flag, number, 'x') + f;
	if (number != NULL)
		free(number);
    return(f);
}

int		type_u(uintmax_t i, t_flags flag)
{
	int f;
	int j;
    char *number;

    f = 0;
	j = 0;
	number = NULL;
	if (flag.accuracy == -1 && i == 0)
	{
		if (flag.width == 0)
			return (f);
		else
		{
			f = ustr_width_work(flag, "\0", 0) + f;
			return (f);
		}
	}
	f = wr_uaccuracy(flag, i, f) + f;
	f = uaccuracy_work(flag, i) + f;
    number = ft_uitoa_base(i, 10 , 2);
    while (number[j])
    {
        write(1, &number[j], 1);
        j++;
        f++;
    }
	if (flag.minus != 0)
		f = uwidth_work(flag, i, 0) + f;
	if (number != NULL)
		free(number);
    return(f);
}

int		type_s(char *str, t_flags flag)
{
	int f;
	int i;
	int j;

	f = 0;
	i = 0;
	j = flag.accuracy;
	if (str == NULL)
	{
		write(1,"(null)", 6);
		return(6);
	}
	f = wr_str_accuracy(flag, f, str);
	f = str_accuracy_work(flag, str) + f;
	if (flag.minus != 0)
		f = str_width_work(flag, str, 0) + f;
	return(f);
}

int		type_d(intmax_t i, t_flags flag)
{
	int f;
	char *number;
	int j;

	f = 0;
	j = 0;
	number = NULL;
	if (flag.minus != 0 || flag.accuracy != 0)
        flag.zero = 0;
	if (flag.plus != 0  || flag.minus != 0 || i < 0) 
		flag.space = 0;
	if (flag.accuracy == -1 && i == 0)
	{
		if (flag.width == 0)
			return (f);
		else
		{
			f = ustr_width_work(flag, "\0", 0) + f;
			return (f);
		}
	}
	if (flag.accuracy == -1 && i == 0)
		return (f);
	if (flag.space != 0 &&  flag.plus == 0 && flag.minus == 0)
	{
		write (1, " ", 1);
		f++;
	}
	f = wr_accuracy(flag, i, f, &number) + f;
	f = accuracy_work(flag, i) + f;
	while (number[j])
	{
 		write(1, &number[j], 1);
		j++;
		f++;
	}
	if (flag.minus != 0)
		f = width_work(flag, i) + f;
	if (number != NULL)
		free(number);
	return(f);
}

int		ft_printf(char *format, ...)
{
	va_list ap;
	int i;
	int f;
	int x;
	t_flags flag;

	f = 0;
	i = 0;
	x = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			break ;
		write(1, &format[i], 1);
		i++;
		f++;
	}
	if (format[i] == '\0')
		return (f);
	va_start(ap, format);
	while (format[i])
	{	
		if (format[i] == '%')
		{
			x = check_percent(&format[i]);
			flag = check_flags(&format[i], x);
			check_s_flags(&format[i], x, &flag);
			if ((my_ft_strchr(&format[i], 'd', x))
				|| (my_ft_strchr(&format[i], 'i', x)))
				f = use_d_flags(flag, f, ap, 0);
			else if ((my_ft_strchr(&format[i], 's', x)))
				f = use_s_flags(flag, f, ap, 0);
//			else if ((my_ft_strchr(&format[i], 'S', x)))
//				f = use_s_flags(flag, f, ap, 1);
			else if (my_ft_strchr(&format[i], 'u', x))
					f = use_u_flags(flag, f, ap, 0);
			else if (my_ft_strchr(&format[i], 'x', x))
				f = use_x_flags(flag, f, ap, 0);			
			else if (my_ft_strchr(&format[i], 'X', x))
				f = use_x_flags(flag, f, ap, 1);			
			else if (my_ft_strchr(&format[i], 'o', x))
				f = use_o_flags(flag, f, ap, 0);			
			else if (my_ft_strchr(&format[i], 'O', x))
				f = use_o_flags(flag, f, ap, 1);			
			else if (my_ft_strchr(&format[i], 'c', x))
				f = use_c_flags(flag, f, ap);
			else if (my_ft_strchr(&format[i], 'C', x))
				f = use_c_flags(flag, f, ap);						
			else if (my_ft_strchr(&format[i], 'D', x))
				f = use_d_flags(flag, f, ap, 1);			
			else if (my_ft_strchr(&format[i], 'U', x))
				f = use_u_flags(flag, f, ap, 1);
			else if (my_ft_strchr(&format[i], 'p', x))
				f = use_p_flags(flag, f, ap);
			else
			{
				if (!check_type(&format[i + 1], x))
					return (f);
				if (!check_format(&format[i + 1]) 
					|| (!check_type(&format[i + 1], x)))
				 {
					 f = type_c(my_ft_isprint(&format[i + 1], x), flag) + f;
					 i++;
				 }
			}
		}
		i = x + i;
		if (format[i] != '%' || format[i] != '\0')
		{
			while (format[i] != '%' && format[i] != '\0')
			{
				if (format[i] == '\n')
					write(1, "\n", 1);
				else
					write(1, &format[i], 1);
				f++;
				i++;
			}
		}
		
	}
	va_end(ap);
//	printf("%d\n", f);
	return (f);
}
/*
int main()
{
	int i;

	ft_printf("%c %d %i", 0, 44, 24);
	write (1, "\n", 1);
	i = printf("%c %d %i", 0, 44, 24);
	printf("%d\n", i);

	return(0);

}
*/
