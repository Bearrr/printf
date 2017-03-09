/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:40:43 by ireva             #+#    #+#             */
/*   Updated: 2017/03/08 20:49:43 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char		my_ft_isprint(char *str, int x)
{
	int		j;

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
