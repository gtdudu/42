/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:30:56 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 13:22:46 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_small		*ft_create_small_zone(void)
{
	long		i;
	t_small		*small;
	size_t		tot;
	size_t		map;

	tot = 0;
	map = (sizeof(t_small) + SMALL_LIGN * SMALL_BLOCKS);
	while ((map + tot) % getpagesize() != 0)
		tot++;
	map += tot;
	small = mmap(0, map,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	small->total_size = 0;
	small->next = NULL;
	small->ptr = (void *)small + sizeof(t_small);
	i = 0;
	while (i < SMALL_LIGN)
	{
		small->tab[i][0] = (long)small->ptr + (SMALL_BLOCKS * i);
		small->tab[i][1] = -1;
		i++;
	}
	return ((t_small *)small);
}

void		*ft_look_for_free_space_small(long tab[SMALL_LIGN][2], size_t size)
{
	long		i;
	long		jump;

	i = 0;
	while (i < SMALL_LIGN)
	{
		if (tab[i][1] == -1)
		{
			if ((jump = ft_does_it_fit_small(tab, i, size)) == 0)
			{
				ft_update_tab_small(tab, i, size);
				return ((void *)tab[i][0]);
			}
			i += jump / SMALL_BLOCKS;
		}
		i++;
	}
	return (NULL);
}

long		ft_does_it_fit_small(long tab[SMALL_LIGN][2],
		long start, size_t size)
{
	long		tmp;
	size_t		blocks_needed;

	if ((size % SMALL_BLOCKS) == 0)
		blocks_needed = (size / SMALL_BLOCKS);
	else
		blocks_needed = (size / SMALL_BLOCKS) + 1;
	tmp = start + (long)blocks_needed;
	while (start < SMALL_LIGN && start < tmp)
	{
		if (tab[start][1] == -1)
			start++;
		else
			break ;
	}
	if (start == tmp)
		return (0);
	else
		return (tab[start][1]);
}

void		ft_update_tab_small(long tab[SMALL_LIGN][2],
		long start, size_t size)
{
	long		tmp;
	size_t		blocks_needed;

	if ((size % SMALL_BLOCKS) == 0)
		blocks_needed = (size / SMALL_BLOCKS);
	else
		blocks_needed = (size / SMALL_BLOCKS) + 1;
	tmp = start + (long)blocks_needed;
	tab[start][1] = (long)size;
	start++;
	while (start++ < tmp)
		tab[start][1] = 0;
	g_env.total_size += size;
}

void		*ft_add_small_zone(size_t size)
{
	t_small	*tmp;
	void	*ptr;

	ptr = NULL;
	tmp = g_env.head_small;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_create_small_zone();
	ptr = ft_malloc_small(size);
	return (ptr);
}
