/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:44:15 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/06 18:49:51 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	dest = (char*)malloc(sizeof(*s1) * (len + 1));
	if (dest)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	else
		return (0);
}
