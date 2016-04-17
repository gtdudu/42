/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:29:59 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/06 17:51:09 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_getsize(int n)
{
	int		counter;

	counter = 1;
	while (n > 9 || n < -9)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

static char		*getneg(char *s, int n, int size)
{
	n = -n;
	s[size + 1] = '\0';
	while (size >= 0)
	{
		s[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	s[0] = '-';
	return (s);
}

static char		*getpos(char *s, int n, int size)
{
	s[size] = '\0';
	while (size >= 0)
	{
		s[size - 1] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_getsize(n);
	if (n < 0)
	{
		if (!(s = malloc(sizeof(s) * size + 2)))
			return (NULL);
		s = getneg(s, n, size);
	}
	else
	{
		if (!(s = malloc(sizeof(s) * size + 1)))
			return (NULL);
		s = getpos(s, n, size);
	}
	return (s);
}
