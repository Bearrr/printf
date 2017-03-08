/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:40:43 by ireva             #+#    #+#             */
/*   Updated: 2017/03/06 15:44:27 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char		my_ft_isprint(char *str, int x)
{
	int j;

	j = 0;
//	printf(" I tyt %d\n", *i);
	while(x > j)
	{
		while ((str[j] >= 48 && str[j] <= 57) || str[j] == '.' || str[j] == '-' ||
			   ft_strchr("hljz", str[j]))
		{
			j++;
//			(*i)++;
//			printf("I == %d\n", *i);
		}
//		printf("I == %d\n", *i);
		if (str[j] >= '!' && str[j] <= '~')
			return (str[j]);
//		(*i)++;
		j++;
//		printf("%d\n", *i);
	}
	return (str[j]);
}
