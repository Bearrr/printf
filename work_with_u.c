/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:04:21 by ireva             #+#    #+#             */
/*   Updated: 2017/03/10 15:34:27 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			wr_uaccuracy(t_flags flag, uintmax_t i, int f)
{
	if (flag.minus == 0)
		f = uwidth_work(flag, i, 0) + f;
	if (flag.accuracy == 0 && i == 0)
		return (f);
	return (f);
}

int			uaccuracy_work(t_flags flag, int i)
{
	int		f;
	int		j;

	f = 0;
	j = int_lens(i, 10);
	if (flag.hash != 0 && flag.width != 0)
	{
		write(1, "0", 1);
		f++;
		j += 1;
	}
	if (flag.accuracy != 0)
	{
		if (flag.accuracy > j)
		{
			while (j < flag.accuracy)
			{
				write(1, "0", 1);
				j++;
				f++;
			}
		}
	}
	return (f);
}

int			uwidth_work(t_flags flag, uintmax_t i, int fleg)
{
	int		j;
	int		f;

	f = 0;
	fleg = 0;
	if (flag.minus != 0)
		flag.zero = 0;
	if (flag.accuracy == 0 || flag.accuracy < (int)int_lens(i, 10))
		j = int_lens(i, 10);
	else
		j = flag.accuracy;
	if (flag.width != 0)
		f = width_writter(flag, j, f);
	if (flag.hash != 0)
		write(1, "0", 1);
	return (f);
}

int			type_u(uintmax_t i, t_flags flag)
{
	int		f;
	char	*number;

	f = 0;
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
	number = ft_uitoa_base(i, 10, 2);
	f = number_writter(number, f);
	if (flag.minus != 0)
		f = uwidth_work(flag, i, 0) + f;
	if (number != NULL)
		free(number);
	return (f);
}

int			use_u_flags(t_flags flag, int f, va_list ap, int size)
{
	if (size == 1)
		f = ((type_u(va_arg(ap, long), flag)) + f);
	else if (ft_strcmp(flag.letter, "j") == 0)
		f = ((type_u(va_arg(ap, uintmax_t), flag)) + f);
	else if (ft_strcmp(flag.letter, "z") == 0)
		f = ((type_u(va_arg(ap, size_t), flag)) + f);
	else if (ft_strcmp(flag.letter, "ll") == 0)
		f = ((type_u(va_arg(ap, unsigned long long), flag)) + f);
	else if (ft_strcmp(flag.letter, "l") == 0)
		f = ((type_u(va_arg(ap, unsigned long), flag)) + f);
	else if (ft_strcmp(flag.letter, "h") == 0)
		f = (type_u((unsigned short)va_arg(ap, int), flag) + f);
	else if (ft_strcmp(flag.letter, "hh") == 0)
		f = (type_u((unsigned char)va_arg(ap, int), flag) + f);
	else
		f = (type_u(va_arg(ap, unsigned int), flag) + f);
	return (f);
}
