/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:16:41 by ireva             #+#    #+#             */
/*   Updated: 2017/03/09 16:22:03 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			type_x(uintmax_t x, t_flags flag, int size)
{
	int		f;
	char	*number;
	int		i;

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
		|| (flag.hash != 0 && flag.zero != 0))
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
	return (f);
}
