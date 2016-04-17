/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_tiny.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:27:55 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 12:34:14 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_tiny		*ft_create_tiny_zone(void)
{
	long	i;
	t_tiny	*tiny;
	size_t	tot;
	size_t	map;

	tot = 0;
	map = (sizeof(t_tiny) + TINY_LIGN * TINY_BLOCKS);
	while ((map + tot) % getpagesize() != 0)
		tot++;
	map += tot;
	tiny = mmap(0, map,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	tiny->total_size = 0;
	tiny->next = NULL;
	tiny->ptr = (void *)tiny + sizeof(t_tiny);
	i = 0;
	while (i < TINY_LIGN)
	{
		tiny->tab[i][0] = (long)tiny->ptr + (TINY_BLOCKS * i);
		tiny->tab[i][1] = -1;
		i++;
	}
	return ((t_tiny *)tiny);
}

void		*ft_look_for_free_space_tiny(long tab[TINY_LIGN][2], size_t size)
{
	long		i;
	long		jump;

	i = 0;
	while (i < TINY_LIGN)
	{
		if (tab[i][1] == -1)
		{
			if ((jump = ft_does_it_fit_tiny(tab, i, size)) == 0)
			{
				ft_update_tab_tiny(tab, i, size);
				return ((void*)tab[i][0]);
			}
			i += jump / TINY_BLOCKS;
		}
		i++;
	}
	return (NULL);
}

long		ft_does_it_fit_tiny(long tab[TINY_LIGN][2], long start, size_t size)
{
	long		tmp;
	size_t		blocks_needed;

	if ((size % TINY_BLOCKS) == 0)
		blocks_needed = (size / TINY_BLOCKS);
	else
		blocks_needed = (size / TINY_BLOCKS) + 1;
	tmp = start + (long)blocks_needed;
	while (start < TINY_LIGN && start < tmp)
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

void		ft_update_tab_tiny(long tab[TINY_LIGN][2], long start, size_t size)
{
	long		tmp;
	size_t		blocks_needed;

	if ((size % TINY_BLOCKS) == 0)
		blocks_needed = (size / TINY_BLOCKS);
	else
		blocks_needed = (size / TINY_BLOCKS) + 1;
	tmp = start + (long)blocks_needed;
	tab[start][1] = (long)size;
	while (++start < tmp)
		tab[start][1] = 0;
	g_env.total_size += size;
}

void		*ft_add_tiny_zone(size_t size)
{
	t_tiny	*tmp;
	void	*ptr;

	ptr = NULL;
	tmp = g_env.head_tiny;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_create_tiny_zone();
	ptr = ft_malloc_tiny(size);
	return (ptr);
}
