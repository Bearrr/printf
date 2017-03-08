/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:31:54 by ireva             #+#    #+#             */
/*   Updated: 2017/03/06 16:22:16 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>


static	int	len(long int b)
{
	int		c;

	c = 0;
//	if (b < 0)
//		c++;
	if (b == 0)
		return (1);
	while (b != 0)
	{
		b = b / 10;
		c++;
	}
	return (c);
}

char		*my_ft_itoa(long int n, int flag)
{
	long int f;
	char	*mass;
	long	int	a;

	a = 0;
	f = len(n);
	if (flag != 0)
		f += 1;
	mass = ft_strnew(f);
	if (mass == NULL)
		return (NULL);
	if (flag == 1 && n < 0)
		mass[0] = '-';
	if (flag == 2 && n > 0)
		mass[0] = '+';
	if (n == 0)
		mass[f - 1] = n + '0';
	while (n != 0)
	{
		a = n % 10;
		if (a < 0)
			a = -a;
		n = n / 10;
		mass[f - 1] = a + '0';
		f--;
	}
	if (n < 10 && n > 0)
		mass[0] = n + '0';
	return (mass);
}