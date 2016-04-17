/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:14:56 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/07 16:14:59 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	c2;

	c2 = (unsigned char)c;
	if (s && n)
	{
		tmp = (unsigned char *)s;
		i = 0;
		while (i < n)
		{
			if (tmp[i] == c2)
				return (&tmp[i]);
			i++;
		}
	}
	return (NULL);
}
