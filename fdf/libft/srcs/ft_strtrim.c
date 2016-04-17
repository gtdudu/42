/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:45:30 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/06 19:02:18 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_lws(const char *s)
{
	size_t		len;
	size_t		sp;
	size_t		i;

	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	sp = i;
	if (sp != len)
	{
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			sp++;
		}
	}
	return (len - sp);
}

char			*ft_strtrim(char const *s)
{
	size_t		l;
	char		*str;
	size_t		i;
	size_t		j;

	if (s)
	{
		l = ft_lws(s);
		str = (char *)malloc(sizeof(str) * l + 1);
		if (str)
		{
			i = 0;
			while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
				i++;
			j = 0;
			while (j < l)
				str[j++] = s[i++];
			str[j] = '\0';
			return (str);
		}
	}
	return (NULL);
}
