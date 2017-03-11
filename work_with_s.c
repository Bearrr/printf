/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:04:49 by ireva             #+#    #+#             */
/*   Updated: 2017/03/10 15:29:21 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str_accuracy_work(t_flags flag, char *number)
{
	int f;
	int j;
	int i;

	f = 0;
	j = 0;
	i = flag.accuracy;
	if (flag.accuracy > (int)ft_strlen(number))
		f = number_writter(number, f);
	else
		while (i != 0)
		{
			write(1, &number[j], 1);
			i--;
			f++;
			j++;
		}
	if (flag.accuracy == 0)
		f = number_writter(number, f);
	return (f);
}

int		wr_str_accuracy(t_flags flag, int f, char *number)
{
	if (flag.minus == 0)
		f = str_width_work(flag, number, 0) + f;
	return (f);
}

int		str_width_work(t_flags flag, char *number, int fleg)
{
	int j;
	int f;

	f = 0;
	if (flag.minus != 0)
		flag.zero = 0;
	if (flag.accuracy == 0 || (int)ft_strlen(number) < flag.accuracy)
		j = ft_strlen(number);
	else
		j = flag.accuracy;
	if (fleg == 1)
		j += 2;
	if (flag.width != 0)
		f = width_writter(flag, j, f);
	return (f);
}

int		ustr_width_work(t_flags flag, char *number, int fleg)
{
	int j;
	int f;

	f = 0;
	if (flag.minus != 0)
		flag.zero = 0;
	if (flag.accuracy == 0 || !ft_strlen(number))
		j = ft_strlen(number);
	else
		j = flag.accuracy;
	if (fleg == 1)
		j += 2;
	if (flag.width != 0)
		f = width_writter(flag, j, f);
	return (f);
}

int		type_s(char *str, t_flags flag)
{
	int f;
	int i;
	int j;

	f = 0;
	i = 0;
	j = flag.accuracy;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	f = wr_str_accuracy(flag, f, str);
	f = str_accuracy_work(flag, str) + f;
	if (flag.minus != 0)
		f = str_width_work(flag, str, 0) + f;
	return (f);
}
