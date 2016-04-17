/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 16:32:46 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 12:50:14 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>
#include <errno.h>

t_large		*ft_check_if_large(void *ptr)
{
	t_large	*tmp;

	tmp = g_env.head_large;
	while (tmp && ptr != tmp->ptr)
		tmp = tmp->next;
	return (tmp);
}

size_t		ft_get_mun_large(size_t size)
{
	size_t	tot;
	size_t	mun;

	tot = 0;
	mun = sizeof(t_large) + size;
	while ((mun + tot) % getpagesize() != 0)
		tot++;
	mun += tot;
	return (mun);
}

t_large		*ft_subdelete_zone_large(t_large *large)
{
	t_large *tmp;
	t_large *prev;

	prev = g_env.head_large;
	tmp = prev->next;
	while (tmp && tmp != large)
	{
		prev = prev->next;
		tmp = prev->next;
	}
	prev->next = tmp->next;
	g_env.total_size -= tmp->size;
	munmap(tmp, ft_get_mun_large(tmp->size));
	return (g_env.head_large);
}

t_large		*ft_delete_zone_large(t_large *large)
{
	t_large *tmp;

	tmp = g_env.head_large;
	if (g_env.head_large == large)
	{
		if (tmp->next != NULL)
		{
			g_env.head_large = g_env.head_large->next;
			g_env.total_size -= tmp->size;
			munmap(tmp, ft_get_mun_large(tmp->size));
		}
		else
			g_env.head_large->status = 0;
	}
	else
		g_env.head_large = ft_subdelete_zone_large(large);
	return (g_env.head_large);
}
