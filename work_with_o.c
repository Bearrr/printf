/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:43:13 by ireva             #+#    #+#             */
/*   Updated: 2017/03/10 15:11:13 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			wr_o_uaccuracy(t_flags flag, char *number, int f, char fleg)
{
	if (flag.minus == 0)
		f = o_uwidth_work(flag, number, fleg) + f;
	if (flag.accuracy == 0 && !ft_strlen(number))
		return (f);
	return (f);
}

int			o_uaccuracy_work(t_flags flag, char *number, char fleg)
{
	int		f;
	int		j;

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

int			o_uwidth_work(t_flags flag, char *number, char fleg)
{
	int		j;
	int		f;

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
		f = width_writter(flag, j, f);
	return (f);
}

int			type_o(uintmax_t i, t_flags flag)
{
	int		f;
	char	*number;

	f = 0;
	number = NULL;
	if (flag.accuracy == -1 && i == 0 && flag.hash == 0)
	{
		if (flag.width == 0)
			return (f);
		else
		{
			f = ustr_width_work(flag, "\0", 0) + f;
			return (f);
		}
	}
	(flag.hash != 0 || flag.accuracy != 0) ? flag.zero = 0 : 0;
	number = ft_uitoa_base(i, 8, 2);
	f = wr_o_uaccuracy(flag, number, f, 'o') + f;
	f = o_uaccuracy_work(flag, number, 'o') + f;
	f = number_writter(number, f);
	if (flag.minus != 0)
		f = o_uwidth_work(flag, number, 'o') + f;
	if (number != NULL)
		free(number);
	return (f);
}

int			number_writter(char *number, int f)
{
	int		j;

	j = 0;
	while (number[j])
	{
		write(1, &number[j], 1);
		j++;
		f++;
	}
	return (f);
}
