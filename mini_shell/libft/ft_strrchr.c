/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:41:05 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/05 23:28:42 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	char	c2;

	c2 = (char)c;
	tmp = (char *)s;
	i = ft_strlen(tmp);
	while (i >= 0)
	{
		if (tmp[i] == c2)
			return (&tmp[i]);
		i--;
	}
	return (NULL);
}
