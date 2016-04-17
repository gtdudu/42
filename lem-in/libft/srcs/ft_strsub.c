/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:54:33 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/08 18:43:21 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*scpy;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	scpy = (char *)malloc(sizeof(s) * len + 1);
	if (scpy == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < len)
		{
			scpy[i] = s[start + i];
			i++;
		}
		scpy[i] = '\0';
		return (scpy);
	}
}
