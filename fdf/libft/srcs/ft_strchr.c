/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:19:13 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/23 18:21:01 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*tmp;
	char			c2;

	if (s)
	{
		c2 = (char)c;
		i = 0;
		tmp = (char *)s;
		while (i <= ft_strlen(tmp))
		{
			if (tmp[i] == c2)
				return (&tmp[i]);
			i++;
		}
	}
	return (NULL);
}
