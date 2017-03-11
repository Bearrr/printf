/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:44:31 by ireva             #+#    #+#             */
/*   Updated: 2017/03/11 13:22:12 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_work(t_flags flag, intmax_t i)
{
	int j;
	int f;

	f = 0;
	if (flag.accuracy == 0 || flag.accuracy < (int)int_len(i, 10))
		j = int_len(i, 10);
	else
	{
		if (i >= 0)
			j = flag.accuracy;
		else
			j = flag.accuracy + 1;
	}
	if ((flag.plus != 0 && i >= 0) || flag.space != 0)
		j = j + 1;
	if (flag.width != 0)
		f = width_writter(flag, j, f);
	return (f);
}

int		swidth_work(t_flags flag, char *number, int fleg)
{
	int j;
	int f;

	f = 0;
	(flag.minus != 0 || flag.accuracy != 0) ? flag.zero = 0 : 0;
	if (flag.accuracy == 0 || flag.accuracy < (int)ft_strlen(number))
		j = ft_strlen(number);
	else
		j = flag.accuracy;
	(fleg == 1) ? j += 2 : 0;
	if (flag.width != 0)
		f = width_writter(flag, j, f);
	return (f);
}

int		width_writter(t_flags flag, int j, int f)
{
	if (flag.width > j)
	{
		while (j < flag.width)
		{
			if (flag.zero != 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			f++;
			j++;
		}
	}
	return (f);
}
