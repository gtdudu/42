/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:33:02 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/06 19:39:32 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(dst);
	i = 0;
	if (l >= size)
		return (size + ft_strlen(src));
	while (i < size - l - 1 && src[i])
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = '\0';
	return (ft_strlen(src) + l);
}
