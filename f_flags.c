/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:01:46 by ireva             #+#    #+#             */
/*   Updated: 2017/03/10 16:03:05 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			int_lenth(char *str, int *i, t_flags *flag, char *format)
{
	int		j;
	int		k;
	char	*arr;

	j = 0;
	k = 0;
	while (str[j] >= 48 && str[j] <= 57)
		j++;
	arr = ft_strnew(j);
	while (j > 0)
	{
		arr[k] = format[(*i)];
		k++;
		(*i)++;
		j--;
	}
	flag->width = ft_atoi(arr);
	free(arr);
	return (j);
}

void		check_width(char *format, t_flags *flag, int x)
{
	int		i;

	i = 0;
	while (x > i)
	{
		if (format[i] >= 48 && format[i] <= 57)
		{
			if (format[i] != '0')
			{
				if (format[i - 1] != '.')
					int_lenth(&format[i], &i, flag, format);
				else
				{
					while (format[i] >= 48 && format[i] <= 57)
						i++;
				}
			}
		}
		i++;
	}
}

int			int_acc_len(char *str)
{
	int		j;

	j = 0;
	while (str[j] >= 48 && str[j] <= 57)
		j++;
	return (j);
}

void		check_accuracy(char *format, t_flags *flag)
{
	int		i;
	char	*arr;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (format[i] != '.')
		i++;
	i++;
	j = int_acc_len(&format[i]);
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

t_flags		check_flags(char *format, int x)
{
	t_flags flag;

	flag.hash = 0;
	flag.zero = 0;
	flag.plus = 0;
	flag.minus = 0;
	flag.space = 0;
	flag.accuracy = 0;
	flag.width = 0;
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
