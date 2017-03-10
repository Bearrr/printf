/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:44:49 by ireva             #+#    #+#             */
/*   Updated: 2017/03/09 19:45:14 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int				type_p(void *x, t_flags flag)
{
	int			f;
	char		*number;
	long int	i;
	int			j;

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
	return (f);
}

int				type_d(intmax_t i, t_flags flag)
{
	int			f;
	char		*number;
	int			j;

	f = 0;
	j = 0;
	number = NULL;
	if (flag.minus != 0 || flag.accuracy != 0)
		flag.zero = 0;
	if (flag.plus != 0 || flag.minus != 0 || i < 0)
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
	if (flag.space != 0 && flag.plus == 0 && flag.minus == 0)
	{
		write(1, " ", 1);
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
	return (f);
}

int				ft_printf(char *format, ...)
{
	va_list		ap;
	int			i;
	int			f;
	int			x;
	t_flags		flag;

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

	ft_printf("%-15x", 542);
	write (1, "\n", 1);
	i = printf("%-15x", 542);
	printf("%d\n", i);


	int n;
	printf("123456%n", &n);
	return(0);

}

*/
