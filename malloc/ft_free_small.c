/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 16:32:11 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 13:22:48 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_small		*ft_check_if_small(void *ptr)
{
	t_small	*tmp;

	tmp = g_env.head_small;
	while (tmp != NULL)
	{
		if ((long)ptr >= (long)tmp->ptr && (long)ptr
				< ((long)tmp->ptr + (SMALL_LIGN * SMALL_BLOCKS)))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

long		ft_check_for_wrong_ptr_small(void *ptr, t_small *small)
{
	long	i;

	if (((long)ptr - (long)small->ptr) % SMALL_BLOCKS != 0)
		return (-1);
	i = ((long)ptr - (long)small->ptr) / SMALL_BLOCKS;
	if (small->tab[i][1] == 0)
		return (-1);
	return (i);
}

long		ft_remove_from_tab_small(void *ptr, t_small *small)
{
	long	i;
	long	j;
	size_t	blocks_to_remove;

	if ((i = ft_check_for_wrong_ptr_small(ptr, small)) == -1)
		return (0);
	if (small->tab[i][1] % SMALL_BLOCKS == 0)
		blocks_to_remove = (size_t)(small->tab[i][1] / SMALL_BLOCKS);
	else
		blocks_to_remove = (size_t)((small->tab[i][1] / SMALL_BLOCKS) + 1);
	small->total_size -= (size_t)small->tab[i][1];
	g_env.total_size -= (size_t)small->tab[i][1];
	j = -1;
	while (++j < (long)blocks_to_remove)
		small->tab[i + j][1] = -1;
	if (small->total_size != 0)
		return (0);
	else
		return (1);
}

size_t		ft_get_mun_small(void)
{
	size_t	tot;
	size_t	mun;

	tot = 0;
	mun = (sizeof(t_small) + SMALL_BLOCKS * SMALL_LIGN);
	while ((mun + tot) % getpagesize() != 0)
		tot++;
	mun += tot;
	return (mun);
}

t_small		*ft_delete_zone_small(t_small *small)
{
	t_small *tmp;
	t_small *prev;

	tmp = g_env.head_small;
	if (g_env.head_small == small)
	{
		if (tmp->next != NULL)
		{
			g_env.head_small = g_env.head_small->next;
			munmap(tmp, ft_get_mun_small());
		}
	}
	else
	{
		prev = g_env.head_small;
		tmp = prev->next;
		while (tmp && tmp != small)
		{
			prev = prev->next;
			tmp = prev->next;
		}
		prev->next = tmp->next;
		munmap(tmp, ft_get_mun_small());
	}
	return (g_env.head_small);
}
