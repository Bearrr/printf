/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:23:54 by ireva             #+#    #+#             */
/*   Updated: 2017/03/09 17:47:57 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			my_ft_isprint(char *str, int x)
{
	int			j;

	j = 0;
	while (x > j)
	{
		while ((str[j] >= 48 && str[j] <= 57)
			|| str[j] == '.' || str[j] == '-' || ft_strchr("hljz", str[j]))
			j++;
		if (str[j] >= '!' && str[j] <= '~')
			return (str[j]);
		j++;
	}
	return (str[j]);
}

static int		len(long int b)
{
	int			c;

	c = 0;
	if (b == 0)
		return (1);
	while (b != 0)
	{
		b = b / 10;
		c++;
	}
	return (c);
}

char			*my_ft_itoa(long int n, int flag)
{
	int			f;
	char		*mass;
	long int	a;

	a = 0;
	f = len(n);
	if (flag != 0)
		f += 1;
	mass = ft_strnew(f);
	if (mass == NULL)
		return (NULL);
	(flag == 1 && n < 0) ? mass[0] = '-' : 0;
	if (flag == 2 && n > 0)
		mass[0] = '+';
	if (n == 0)
		mass[f - 1] = n + '0';
	while (n != 0)
	{
		a = n % 10;
		(a < 0) ? a = -a : 0;
		n = n / 10;
		mass[f - 1] = a + '0';
		f--;
	}
	return (mass);
}

int				my_ft_strchr(const char *s, int c, int n)
{
	int counter;

	counter = 1;
	if ((char)c == '\0')
		return (0);
	while (n != 0)
	{
		if (*s == (char)c)
			return (counter);
		s++;
		n--;
		counter++;
	}
	return (0);
}
