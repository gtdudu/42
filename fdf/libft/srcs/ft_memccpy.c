/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:20:47 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/03 18:40:24 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*tmpdst;
	char	*tmpsrc;
	size_t	i;
	int		flag;

	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	i = 0;
	flag = 0;
	while (i < n && flag == 0)
	{
		if (tmpsrc[i] == c)
			flag = 1;
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	dst = tmpdst;
	if (flag == 0)
		return (NULL);
	else
		return (dst + i);
}
