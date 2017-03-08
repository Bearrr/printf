/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:09:01 by ireva             #+#    #+#             */
/*   Updated: 2017/03/03 19:44:55 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int     c_accuracy_work(t_flags flag, char number)
{
    int f;
    int j;

    f = 0;
    j = 1;
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
/*/
int     wr_c_accuracy(t_flags flag,  int f)
{
/*    if (flag.zero != 0 && flag.accuracy == 0)
    {
        write(1, "0x", 2);
        f += 2;
        }*/
    if (flag.minus == 0)
        f = c_width_work(flag, 0) + f;
    // if (flag.accuracy == 0 && i == 0)
    //   return (f);
    /* if ((flag.width != 0 && flag.zero == 0) || (flag.width != 0 && flag.accuracy != 0))
    {
        write(1, "0x", 2);
        f += 2;
        }*/
    return (f);
}

int     c_width_work(t_flags flag,  int fleg)
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
