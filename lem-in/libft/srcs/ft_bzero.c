/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:58:35 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/06 18:32:42 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*tmp;

	if (n > 0)
	{
		tmp = (char *)s;
		i = 0;
		while (i < n)
		{
			tmp[i] = 0;
			i++;
		}
	}
}