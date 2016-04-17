/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:49:46 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/06 19:00:04 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			tmp = i;
			j = 0;
			while (s1[tmp] == s2[j])
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
