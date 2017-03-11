/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:54:06 by ireva             #+#    #+#             */
/*   Updated: 2017/03/10 22:05:35 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				type_p(void *x, t_flags flag)
{
	int			f;
	char		*number;
	long int	i;

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
	f = number_writter(number, f);
	if (flag.minus != 0)
		f = swidth_work(flag, number, 1) + f;
	if (number != NULL)
		free(number);
	return (f);
}

int				wr_saccuracy(t_flags flag, uintmax_t i, int f, char *number)
{
	if ((flag.zero != 0 && flag.accuracy == 0)
		|| (flag.zero == 0 && flag.accuracy == 0 && flag.width == 0))
	{
		write(1, "0x", 2);
		f += 2;
	}
	if (flag.minus == 0)
		f = swidth_work(flag, number, 1) + f;
	if (flag.accuracy == 0 && i == 0 && flag.width == 0)
		return (f);
	if ((flag.width != 0 && flag.zero == 0) || flag.accuracy != 0)
	{
		write(1, "0x", 2);
		f += 2;
	}
	return (f);
}

int				type_d(intmax_t i, t_flags flag)
{
	int			f;
	char		*number;

	f = 0;
	number = NULL;
	if (flag.minus != 0 || flag.accuracy != 0)
		flag.zero = 0;
	if (flag.plus != 0 || flag.minus != 0 || i < 0)
		flag.space = 0;
	if (flag.accuracy == -1 && i == 0)
		return (neg_accuracy(flag, f));
	if (flag.space != 0 && flag.plus == 0 && flag.minus == 0)
	{
		write(1, " ", 1);
		f++;
	}
	f = wr_accuracy(flag, i, f, &number) + f;
	f = accuracy_work(flag, i) + f;
	f = number_writter(number, f);
	if (flag.minus != 0)
		f = width_work(flag, i) + f;
	if (number != NULL)
		free(number);
	return (f);
}

int				no_type(char *format, int x, t_flags flag, int *i)
{
	int			f;

	f = 0;
	if (!check_format(&format[(*i) + 1])
		|| (!check_type(&format[(*i) + 1], x)))
	{
		f = type_c(my_ft_isprint(&format[(*i) + 1], x), flag) + f;
		(*i)++;
	}
	return (f);
}

int				wr_rest(int *i, char *format, int f, int x)
{
	(*i) = x + (*i);
	if (format[(*i)] != '%' || format[(*i)] != '\0')
	{
		while (format[(*i)] != '%' && format[(*i)] != '\0')
		{
			if (format[(*i)] == '\n')
				write(1, "\n", 1);
			else
				write(1, &format[(*i)], 1);
			f++;
			(*i)++;
		}
	}
	return (f);
}
