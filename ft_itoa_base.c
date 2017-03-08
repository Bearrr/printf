/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:43:39 by ireva             #+#    #+#             */
/*   Updated: 2017/02/20 18:08:33 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		check_flag(int a, int flag)
{
	if (flag == 0)
		a = a + 39;
	else if (flag == 1)
		a = a + 7;
	return (a);
}

int			int_len(intmax_t nbr, int base)
{
	int i;

	i = 0;
	if (nbr < 0 && base == 10)
		i++;
	if (nbr == 0)
		return(1);
	while (nbr != 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(intmax_t nbr, int base, int flag)
{
	intmax_t a;
	int f;
	char *mass;

	f = int_len(nbr, base);
	mass = (char*)malloc(sizeof(char) * (f + 1));
	mass[f] = '\0';
	if (nbr == 0)
		mass[f - 1] = nbr + '0';
	if (nbr < 0 && base == 10)
		mass[0] = '-';
	while (nbr != 0)
	{
		a = nbr % base;
		if (a < 0)
			a = -a;
		if (a > 9)
			a = check_flag(a, flag);
		nbr = nbr / base;
		mass[f - 1] = a + '0';
		f--;
	}
	return(mass);
}

