/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:09:01 by ireva             #+#    #+#             */
/*   Updated: 2017/03/10 14:47:02 by ireva            ###   ########.fr       */
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
		f = width_writter(flag, j, f);
	return (f);
}

int		type_c(char c, t_flags flag)
{
	int f;

	f = 0;
	f = wr_c_accuracy(flag, f);
	ft_putchar(c);
	f++;
	if (flag.minus != 0)
		f = c_width_work(flag, c) + f;
	return (f);
}
