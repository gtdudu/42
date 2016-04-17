/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:50:53 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/05 21:20:15 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 && s2)
	{
		while (i < n)
		{
			if (s1[i] == '\0' && s2[i] == '\0')
				return (1);
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
	}
	return (1);
}
