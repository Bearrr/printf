/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accuracy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:57:45 by ireva             #+#    #+#             */
/*   Updated: 2017/03/10 16:58:54 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pl_mn_accuracy(char **number, int f, intmax_t i, int fleg)
{
	if (fleg == 0)
	{
		write(1, "-", 1);
		f++;
		*number = my_ft_itoa(i, 0);
	}
	if (fleg == 1)
	{
		write(1, "+", 1);
		f++;
		*number = my_ft_itoa(i, 0);
	}
	return (f);
}

int		wrs_accuracy(t_flags flag, intmax_t i, int p, int f)
{
	if (flag.minus == 0 && p == 0)
	{
		(flag.space == 0) ? f = width_work(flag, i) + f : 0;
		(flag.space != 0) ? f = width_work(flag, i) : 0;
	}
	if (flag.accuracy == 0 && i == 0)
		return (f);
	if (flag.accuracy != 0 && flag.plus != 0 && i > 0)
	{
		write(1, "+", 1);
		f++;
	}
	if (flag.accuracy != 0 && i < 0)
	{
		write(1, "-", 1);
		f++;
	}
	return (f);
}

int		wr_accuracy(t_flags flag, intmax_t i, int f, char **number)
{
	int p;

	p = 0;
	if (flag.minus == 0 && flag.plus != 0
		&& flag.zero == 0 && flag.accuracy == 0)
	{
		f = width_work(flag, i) + f;
		p = 1;
	}
	if (flag.zero != 0 && i < 0 && flag.accuracy == 0)
		f = pl_mn_accuracy(number, f, i, 0);
	else if (flag.plus != 0 && flag.minus == 0 && flag.accuracy == 0 && i >= 0)
		f = pl_mn_accuracy(number, f, i, 1);
	else if (flag.plus != 0 && flag.minus != 0
			&& flag.zero == 0 && flag.accuracy == 0)
	{
		(i > 0) ? *number = my_ft_itoa(i, 2) : 0;
		(i < 0) ? *number = my_ft_itoa(i, 1) : 0;
	}
	else if (flag.accuracy != 0 && i < 0)
		*number = my_ft_itoa(i, 0);
	else
		*number = ft_itoa_base(i, 10, 2);
	f = wrs_accuracy(flag, i, p, f);
	return (f);
}

int		accuracy_work(t_flags flag, int i)
{
	int f;
	int j;

	f = 0;
	j = int_len(i, 10);
	if (flag.plus != 0 && i < 0)
		j = j - 1;
	if (i < 0)
		flag.accuracy += 1;
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

int		saccuracy_work(t_flags flag, char *number)
{
	int f;
	int j;

	f = 0;
	j = ft_strlen(number);
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
