/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:44:49 by ireva             #+#    #+#             */
/*   Updated: 2017/03/10 22:08:11 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int				find_percent(char *format, int *i, int f)
{
	while (format[(*i)] != '\0')
	{
		if (format[(*i)] == '%')
			break ;
		write(1, &format[(*i)], 1);
		(*i)++;
		f++;
	}
	return (f);
}

int				find_types(char *format, va_list ap, int i, t_flags flag)
{
	int			x;
	int			f;

	f = 0;
	x = check_percent(&format[i]);
	flag = check_flags(&format[i], x);
	check_s_flags(&format[i], x, &flag);
	if ((my_ft_strchr(&format[i], 'd', x))
		|| (my_ft_strchr(&format[i], 'i', x)))
		f = use_d_flags(flag, f, ap, 0);
	(my_ft_strchr(&format[i], 's', x)) ? f = use_s_flags(flag, f, ap, 0) : 0;
	(my_ft_strchr(&format[i], 'S', x)) ? f = use_s_flags(flag, f, ap, 1) : 0;
	(my_ft_strchr(&format[i], 'u', x)) ? f = use_u_flags(flag, f, ap, 0) : 0;
	(my_ft_strchr(&format[i], 'x', x)) ? f = use_x_flags(flag, f, ap, 0) : 0;
	(my_ft_strchr(&format[i], 'X', x)) ? f = use_x_flags(flag, f, ap, 1) : 0;
	(my_ft_strchr(&format[i], 'o', x)) ? f = use_o_flags(flag, f, ap, 0) : 0;
	(my_ft_strchr(&format[i], 'O', x)) ? f = use_o_flags(flag, f, ap, 1) : 0;
	(my_ft_strchr(&format[i], 'c', x)) ? f = use_c_flags(flag, f, ap) : 0;
	(my_ft_strchr(&format[i], 'C', x)) ? f = use_c_flags(flag, f, ap) : 0;
	(my_ft_strchr(&format[i], 'D', x)) ? f = use_d_flags(flag, f, ap, 1) : 0;
	(my_ft_strchr(&format[i], 'U', x)) ? f = use_u_flags(flag, f, ap, 1) : 0;
	(my_ft_strchr(&format[i], 'p', x)) ? f = use_p_flags(flag, f, ap) : 0;
	return (f);
}

int				check_typee(char *format, int x)
{
	int			i;

	i = 0;
	while (x > i)
	{
		if (ft_strchr("sSpdDioOuUxXcC", format[i]))
			return (1);
		i++;
	}
	return (0);
}

int				if_percent(char *format, int i, va_list ap)
{
	int			x;
	int			f;
	t_flags		flag;

	x = 0;
	f = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			x = check_percent(&format[i]);
			flag = check_flags(&format[i], x);
			check_s_flags(&format[i], x, &flag);
			if (check_typee(&format[i], x))
				f = find_types(format, ap, i, flag) + f;
			else
			{
				if (!check_type(&format[(i + 1)], x))
					return (f);
				f = no_type(format, x, flag, &i) + f;
			}
		}
		f = wr_rest(&i, format, f, x);
	}
	return (f);
}

int				ft_printf(char *format, ...)
{
	va_list		ap;
	int			i;
	int			f;

	f = 0;
	i = 0;
	f = find_percent(format, &i, f);
	if (format[i] == '\0')
		return (f);
	va_start(ap, format);
	f = if_percent(format, i, ap) + f;
	va_end(ap);
	return (f);
}
