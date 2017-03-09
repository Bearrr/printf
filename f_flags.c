/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:01:46 by ireva             #+#    #+#             */
/*   Updated: 2017/03/09 13:55:01 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		check_zero(char *format, t_flags *flag)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '0')
		{
			if ((format[i - 1] >= 48 && format[i - 1] <= 57)
				|| format[i - 1] == '.')
				flag->zero = 0;
			else
			{
				flag->zero = 1;
				break ;
			}
		}
		i++;
	}
}

int			int_lenth(char *str)
{
	int		i;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	return (i);
}

void		check_width(char *format, t_flags *flag, int x)
{
	int		i;
	char	*arr;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (x > i)
	{
		if (format[i] >= 48 && format[i] <= 57)
		{
			if (format[i] != '0')
			{
				if (format[i - 1] != '.')
				{
					j = int_lenth(&format[i]);
					arr = ft_strnew(j);
					while (j > 0)
					{
						arr[k] = format[i];
						k++;
						i++;
						j--;
					}
					flag->width = ft_atoi(arr);
					free(arr);
				}
				else
				{
					while (format[i] >= 48 && format[i] <= 57)
						i++;
				}
			}
		}
		k = 0;
		i++;
	}
}

void		check_accuracy(char *format, t_flags *flag)
{
	int		i;
	int		j;
	char	*arr;
	int		k;

	i = 0;
	k = 0;
	while (format[i] != '.')
		i++;
	i++;
	j = int_lenth(&format[i]);
	arr = ft_strnew(j);
	while (j > 0)
	{
		arr[k] = format[i];
		k++;
		i++;
		j--;
	}
	if (arr[0] == '0' || arr[0] == '\0')
		flag->accuracy = -1;
	else
		flag->accuracy = ft_atoi(arr);
	free(arr);
}

void		flags_zero(t_flags *flag)
{
	flag->hash = 0;
	flag->zero = 0;
	flag->plus = 0;
	flag->minus = 0;
	flag->space = 0;
	flag->accuracy = 0;
	flag->width = 0;
}

t_flags		check_flags(char *format, int x)
{
	t_flags flag;

	flags_zero(&flag);
	if (my_ft_strchr(format, '#', x))
		flag.hash = 1;
	if (my_ft_strchr(format, '+', x))
		flag.plus = 1;
	if (my_ft_strchr(format, '-', x))
		flag.minus = 1;
	if (my_ft_strchr(format, ' ', x))
		flag.space = 1;
	if (my_ft_strchr(format, '.', x))
		check_accuracy(format, &flag);
	check_width(format, &flag, x);
	check_zero(format, &flag);
	return (flag);
}
