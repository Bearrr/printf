/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accuracy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:57:45 by ireva             #+#    #+#             */
/*   Updated: 2017/03/08 15:26:22 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wr_uaccuracy(t_flags flag, uintmax_t i, int f)
{
    if (flag.minus == 0)
        f = uwidth_work(flag, i, 0) + f;
    if (flag.accuracy == 0 && i == 0)
        return (f);
	return (f);
}

int		wr_accuracy(t_flags flag, intmax_t i, int f, char **number)
{
	int p;

	p = 0;
//	printf("YA tyt teper");
//	printf("F22 == %d\n", f);
    if (flag.minus == 0 && flag.plus != 0 && flag.zero == 0 && flag.accuracy == 0)
	{
        f = width_work(flag, i) + f;
		p = 1;
	}
	if (flag.zero != 0 && i < 0 && flag.accuracy == 0)
    {
        write(1, "-", 1);
        f++;
        *number = my_ft_itoa(i, 0);
//		printf("YA je tyt %d\n", f);
    }
    else if (flag.plus != 0 && flag.minus == 0 && flag.accuracy == 0 && i >= 0)
    {
        write(1, "+", 1);
        f++;
        *number = my_ft_itoa(i, 0);
    }
    else if (flag.plus != 0 && flag.minus != 0 && flag.zero == 0 && flag.accuracy == 0)
	{
		if (i > 0)
			*number = my_ft_itoa(i, 2);
		if (i < 0)
			*number = my_ft_itoa(i, 1);
	}
    else if (flag.accuracy != 0 && i < 0)
        *number = my_ft_itoa(i, 0);
    else
        *number = ft_itoa_base(i, 10, 2);
    if (flag.minus == 0 && p == 0)
	{
		if (flag.space == 0)
			f = width_work(flag, i) + f;
		if (flag.space != 0)
			f = width_work(flag, i);// + f;
	}
		//	printf("F2 == %d\n", f);
    if (flag.accuracy == 0 && i == 0)
        return (f);
//	printf("F2 == %d\n", f);
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
//	printf("F2 == %d\n", f);
	return (f);
}

int		accuracy_work(t_flags flag, int i)
{
	int f;
	int j;

	f = 0;
	j = int_len(i,10);
//	if (flag.plus != 0 && flag.accuracy > int_len(i, 10))
//		j += 1;
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


int		uaccuracy_work(t_flags flag, int i)
{
	int f;
	int j;

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

int		wr_saccuracy(t_flags flag, uintmax_t i, int f, char *number)
{
	if ((flag.zero != 0 && flag.accuracy == 0) || (flag.zero == 0 && flag.accuracy == 0 
												   && flag.width == 0 ))
	{
		write(1, "0x", 2);
		f += 2;
	}
    if (flag.minus == 0)
        f = swidth_work(flag, number, 1) + f;
    if (flag.accuracy == 0 && i == 0 && flag.width == 0)
        return (f);
	if ((flag.width != 0 && flag.zero == 0) || flag.accuracy != 0)
	{
			write(1, "0x", 2);
			f += 2;
	}
	return (f);
}

