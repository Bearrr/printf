/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:48:35 by ireva             #+#    #+#             */
/*   Updated: 2017/02/10 17:52:58 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	 my_ft_strchr(const char *s, int c, int n, int counter)
{
	counter += 1;
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
