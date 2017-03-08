/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:04:49 by ireva             #+#    #+#             */
/*   Updated: 2017/03/06 21:23:16 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     str_accuracy_work(t_flags flag, char *number)
{
    int f;
    int j;
	int i;

    f = 0;
	j  = 0;
	i = flag.accuracy;
	if (flag.accuracy > (int)ft_strlen(number))
        while (number[j])
        {
            write(1, &number[j], 1);
            j++;
            f++;
        }
    else
        while (i != 0)
        {
            write(1, &number[j], 1);
            i--;
            f++;
            j++;
        }
	if (flag.accuracy == 0)
        while (number[j])
        {
            write(1, &number[j], 1);
            j++;
            f++;
        }
/*    j = ft_strlen(number);
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
		}*/
    return (f);
}

int     wr_str_accuracy(t_flags flag,  int f, char *number)
{
/*    if (flag.zero != 0 && flag.accuracy == 0)
    {
        write(1, "0x", 2);
        f += 2;
		}*/
    if (flag.minus == 0)
        f = str_width_work(flag, number, 0) + f;
	// if (flag.accuracy == 0 && i == 0)
	//   return (f);
	/* if ((flag.width != 0 && flag.zero == 0) || (flag.width != 0 && flag.accuracy != 0))
    {
		write(1, "0x", 2);
		f += 2;
		}*/
    return (f);
}

int     str_width_work(t_flags flag, char *number, int fleg)
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

int     ustr_width_work(t_flags flag, char *number, int fleg)
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
