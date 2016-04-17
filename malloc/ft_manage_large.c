/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:36:41 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 12:51:34 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*ft_mod_large(size_t size)
{
	size_t		tot;
	size_t		map;

	tot = 0;
	map = (sizeof(t_large) + size);
	while ((map + tot) % getpagesize() != 0)
		tot++;
	map += tot;
	if (size > g_env.head_large->size)
	{
		munmap(g_env.head_large, map);
		g_env.head_large = ft_create_large_zone(size);
	}
	return (g_env.head_large->ptr);
}

t_large		*ft_create_large_zone(size_t size)
{
	t_large		*large;
	size_t		tot;
	size_t		map;

	tot = 0;
	map = (sizeof(t_large) + size);
	while ((map + tot) % getpagesize() != 0)
		tot++;
	map += tot;
	large = mmap(0, map,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	large->size = size;
	large->next = NULL;
	large->status = 1;
	large->ptr = large + sizeof(t_large);
	g_env.total_size += size;
	return ((t_large *)large);
}

void		*ft_add_large_zone(size_t size)
{
	t_large	*tmp;
	void	*ptr;

	tmp = g_env.head_large;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_create_large_zone(size);
	ptr = tmp->next->ptr;
	return (ptr);
}
