/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:16:41 by ireva             #+#    #+#             */
/*   Updated: 2017/03/11 13:20:30 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			if_hash(int size, int f)
{
	(size == 0) ? write(1, "0x", 2) : 0;
	(size == 1) ? write(1, "0X", 2) : 0;
	f = f + 2;
	return (f);
}

int			neg_accuracy(t_flags flag, int f)
{
	if (flag.width == 0)
		return (f);
	else
	{
		f = ustr_width_work(flag, "\0", 0) + f;
		return (f);
	}
}

int			type_x(uintmax_t x, t_flags flag, int size)
{
	int		f;
	char	*number;

	f = 0;
	number = NULL;
	if (flag.accuracy == -1 && x == 0)
		return (neg_accuracy(flag, f));
	(size == 0) ? number = ft_uitoa_base(x, 16, 0) : 0;
	(size == 1) ? number = ft_uitoa_base(x, 16, 1) : 0;
	if ((flag.hash != 0 && x != 0 && flag.width == 0)
		|| (flag.hash != 0 && flag.zero != 0))
		f = if_hash(size, f);
	f = wr_o_uaccuracy(flag, number, f, 'x');
	f = o_uaccuracy_work(flag, number, 'x') + f;
	if (flag.hash != 0 && x != 0 && flag.width != 0 && flag.zero == 0)
		f = if_hash(size, f);
	f = number_writter(number, f);
	(flag.minus != 0) ? f = o_uwidth_work(flag, number, 'x') + f : 0;
	(number != NULL) ? free(number) : 0;
	return (f);
}

int			use_x_flags(t_flags flag, int f, va_list ap, int size)
{
	if (ft_strcmp(flag.letter, "j") == 0)
		f = ((type_x(va_arg(ap, uintmax_t), flag, size)) + f);
	else if (ft_strcmp(flag.letter, "z") == 0)
		f = ((type_x(va_arg(ap, size_t), flag, size)) + f);
	else if (ft_strcmp(flag.letter, "ll") == 0)
		f = ((type_x(va_arg(ap, unsigned long long), flag, size)) + f);
	else if (ft_strcmp(flag.letter, "l") == 0)
		f = ((type_x(va_arg(ap, unsigned long), flag, size)) + f);
	else if (ft_strcmp(flag.letter, "h") == 0)
		f = (type_x((unsigned short)va_arg(ap, int), flag, size) + f);
	else if (ft_strcmp(flag.letter, "hh") == 0)
		f = (type_x((unsigned char)va_arg(ap, int), flag, size) + f);
	else
		f = (type_x(va_arg(ap, unsigned int), flag, size) + f);
	return (f);
}

int			use_d_flags(t_flags flag, int f, va_list ap, int size)
{
	if (size == 1)
		f = ((type_d(va_arg(ap, long), flag)) + f);
	else if (ft_strcmp(flag.letter, "j") == 0)
		f = ((type_d(va_arg(ap, intmax_t), flag)) + f);
	else if (ft_strcmp(flag.letter, "z") == 0)
		f = ((type_d(va_arg(ap, size_t), flag)) + f);
	else if (ft_strcmp(flag.letter, "ll") == 0)
		f = ((type_d(va_arg(ap, long long), flag)) + f);
	else if (ft_strcmp(flag.letter, "l") == 0)
		f = ((type_d(va_arg(ap, long), flag)) + f);
	else if (ft_strcmp(flag.letter, "h") == 0)
		f = (type_d((short)va_arg(ap, int), flag) + f);
	else if (ft_strcmp(flag.letter, "hh") == 0)
		f = (type_d((signed char)va_arg(ap, int), flag) + f);
	else
		f = (type_d(va_arg(ap, int), flag) + f);
	return (f);
}
