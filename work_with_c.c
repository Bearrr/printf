/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:09:01 by ireva             #+#    #+#             */
/*   Updated: 2017/03/08 20:24:32 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wr_c_accuracy(t_flags flag, int f)
{
	if (flag.minus == 0)
		f = c_width_work(flag, 0) + f;
	return (f);
}

int		c_width_work(t_flags flag, int fleg)
{
	int j;
	int f;

	f = 0;
	j = 1;
	if (flag.minus != 0)
		flag.zero = 0;
	if (fleg == 1)
		j += 2;
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
