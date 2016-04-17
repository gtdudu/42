/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tiny.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 16:31:14 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 12:39:18 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_tiny		*ft_check_if_tiny(void *ptr)
{
	t_tiny	*tmp;

	tmp = g_env.head_tiny;
	while (tmp != NULL)
	{
		if (((long)ptr >= (long)tmp->ptr) && ((long)ptr
					< ((long)tmp->ptr + (TINY_LIGN * TINY_BLOCKS) - 1)))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

long		ft_check_for_wrong_ptr_tiny(void *ptr, t_tiny *tiny)
{
	long		i;

	if (((long)ptr - (long)tiny->ptr) % TINY_BLOCKS != 0)
		return (-1);
	i = ((long)ptr - (long)tiny->ptr) / TINY_BLOCKS;
	if (tiny->tab[i][1] == 0)
		return (-1);
	return (i);
}

long		ft_remove_from_tab_tiny(void *ptr, t_tiny *tiny)
{
	long	i;
	long	j;
	size_t	blocks_to_remove;

	if ((i = ft_check_for_wrong_ptr_tiny(ptr, tiny)) == -1)
		return (0);
	if (tiny->tab[i][1] % TINY_BLOCKS == 0)
		blocks_to_remove = (size_t)(tiny->tab[i][1] / TINY_BLOCKS);
	else
		blocks_to_remove = (size_t)((tiny->tab[i][1] / TINY_BLOCKS) + 1);
	tiny->total_size -= (size_t)tiny->tab[i][1];
	g_env.total_size -= (size_t)tiny->tab[i][1];
	j = -1;
	while (++j < (long)blocks_to_remove)
		tiny->tab[i + j][1] = -1;
	if (tiny->total_size != 0)
		return (0);
	else
		return (1);
}

size_t		ft_get_mun_tiny(void)
{
	size_t	tot;
	size_t	mun;

	tot = 0;
	mun = (sizeof(t_tiny) + TINY_LIGN * TINY_BLOCKS);
	while ((mun + tot) % getpagesize() != 0)
		tot++;
	mun += tot;
	return (mun);
}

t_tiny		*ft_delete_zone_tiny(t_tiny *tiny)
{
	t_tiny *tmp;
	t_tiny *prev;

	tmp = g_env.head_tiny;
	if (tmp == tiny && tmp->next != NULL)
	{
		g_env.head_tiny = g_env.head_tiny->next;
		munmap(tmp, ft_get_mun_tiny());
	}
	else
	{
		prev = g_env.head_tiny;
		tmp = prev->next;
		while (tmp && tmp != tiny)
		{
			prev = prev->next;
			tmp = prev->next;
		}
		prev->next = tmp->next;
		munmap(tmp, ft_get_mun_tiny());
	}
	return (g_env.head_tiny);
}
