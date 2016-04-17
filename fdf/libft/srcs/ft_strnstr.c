/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:23:29 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/06 18:51:38 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		tmp;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[0])
		{
			tmp = i;
			j = 0;
			while (s1[tmp] == s2[j] && tmp < n)
			{
				j++;
				tmp++;
				if (s2[j] == '\0')
					return (((char *)s1 + i));
			}
		}
		i++;
	}
	return (NULL);
}
