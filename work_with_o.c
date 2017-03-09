/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:43:13 by ireva             #+#    #+#             */
/*   Updated: 2017/03/08 20:33:01 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wr_o_uaccuracy(t_flags flag, char *number, int f, char fleg)
{
	if (flag.minus == 0)
		f = o_uwidth_work(flag, number, fleg) + f;
	if (flag.accuracy == 0 && !ft_strlen(number))
		return (f);
	return (f);
}

int		o_uaccuracy_work(t_flags flag, char *number, char fleg)
{
	int	f;
	int	j;

	f = 0;
	j = ft_strlen(number);
	if (flag.hash != 0 && number[0] != '0' && fleg == 'o')
	{
		write(1, "0", 1);
		f++;
		j += 1;
	}
	if (flag.accuracy != 0 && j != 0)
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

int		o_uwidth_work(t_flags flag, char *number, char fleg)
{
	int j;
	int f;

	f = 0;
	if (flag.minus != 0)
		flag.zero = 0;
	if (flag.accuracy == 0 || flag.accuracy < (int)ft_strlen(number))
		j = ft_strlen(number);
	else
		j = flag.accuracy;
	if (flag.hash != 0 && flag.width != 0 && flag.accuracy == 0)
	{
		if (fleg == 'o')
			j += 1;
		else if (fleg == 'x')
			j += 2;
	}
	if (flag.width != 0)
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
	}
	return (f);
}
