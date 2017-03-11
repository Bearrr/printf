/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:21:41 by ireva             #+#    #+#             */
/*   Updated: 2017/03/11 13:21:37 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				check_ss_flag(char *format, int *c, t_flags *flag, int i)
{
	if (format[i] == 'l' && format[i + 1] == 'l'
		&& (*c) < 3)
	{
		flag->letter = "ll";
		(*c) = 3;
	}
	else if (format[i] == 'l'
		&& (format[i + 1] != 'l' && format[i - 1] != 'l') && (*c) < 2)
	{
		flag->letter = "l";
		(*c) = 2;
	}
	else if (format[i] == 'h' && (format[i + 1] != 'h'
								&& format[i - 1] != 'h') && (*c) < 1)
	{
		flag->letter = "h";
		(*c) = 1;
	}
	else if (format[i] == 'h' && format[i + 1] == 'h')
	{
		flag->letter = "hh";
		(*c) = 0;
	}
	else if ((*c) < 0)
		flag->letter = " ";
}

void				check_s_flags(char *format, int x, t_flags *flag)
{
	int				i;
	int				c;

	i = 0;
	c = -1;
	while (i < x && !ft_strchr("sSpdDioOuUxXcC", format[i]))
	{
		if (format[i] == 'j')
		{
			flag->letter = "j";
			c = 5;
		}
		else if (format[i] == 'z' && c < 4)
		{
			flag->letter = "z";
			c = 4;
		}
		else
			check_ss_flag(format, &c, &(*flag), i);
		i++;
	}
}

int					use_o_flags(t_flags flag, int f, va_list ap, int size)
{
	if (size == 1)
		f = ((type_o(va_arg(ap, long), flag)) + f);
	else if (ft_strcmp(flag.letter, "j") == 0)
		f = ((type_o(va_arg(ap, uintmax_t), flag)) + f);
	else if (ft_strcmp(flag.letter, "z") == 0)
		f = ((type_o(va_arg(ap, size_t), flag)) + f);
	else if (ft_strcmp(flag.letter, "ll") == 0)
		f = ((type_o(va_arg(ap, unsigned long long), flag)) + f);
	else if (ft_strcmp(flag.letter, "l") == 0)
		f = ((type_o(va_arg(ap, unsigned long), flag)) + f);
	else if (ft_strcmp(flag.letter, "h") == 0)
		f = (type_o((unsigned short)va_arg(ap, int), flag) + f);
	else if (ft_strcmp(flag.letter, "hh") == 0)
		f = (type_o((unsigned char)va_arg(ap, int), flag) + f);
	else
		f = (type_o(va_arg(ap, unsigned int), flag) + f);
	return (f);
}

int					use_s_flags(t_flags flag, int f, va_list ap, int size)
{
	size = 0;
	f = (type_s(va_arg(ap, char *), flag) + f);
	return (f);
}

int					use_p_flags(t_flags flag, int f, va_list ap)
{
	f = (type_p(va_arg(ap, void *), flag) + f);
	return (f);
}
