/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:31:41 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 12:49:29 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_env	g_env;

void	ft_init_g_env(void)
{
	g_env.head_tiny = NULL;
	g_env.head_small = NULL;
	g_env.head_large = NULL;
	g_env.total_size = 0;
}

void	*ft_malloc_tiny(size_t size)
{
	void	*ptr;
	t_tiny	*cursor;

	ptr = NULL;
	cursor = g_env.head_tiny;
	while (cursor != NULL)
	{
		ptr = ft_look_for_free_space_tiny(cursor->tab, size);
		if (ptr != NULL)
		{
			cursor->total_size += size;
			return (ptr);
		}
		cursor = cursor->next;
	}
	return (ptr);
}

void	*ft_malloc_small(size_t size)
{
	void	*ptr;
	t_small	*cursor;

	ptr = NULL;
	cursor = g_env.head_small;
	while (cursor != NULL)
	{
		ptr = ft_look_for_free_space_small(cursor->tab, size);
		if (ptr != NULL)
		{
			cursor->total_size += size;
			return (ptr);
		}
		cursor = cursor->next;
	}
	return (ptr);
}

void	*submalloc(size_t size)
{
	void		*ptr;

	ptr = NULL;
	if (g_env.head_large == NULL)
	{
		g_env.head_large = ft_create_large_zone(size);
		ptr = g_env.head_large->ptr;
	}
	else if (g_env.head_large != NULL && g_env.head_large->status == 0)
		ptr = ft_mod_large(size);
	else
		ptr = ft_add_large_zone(size);
	return (ptr);
}

void	*malloc(size_t size)
{
	void		*ptr;

	ptr = NULL;
	if (!g_env.head_small && !g_env.head_tiny && !g_env.head_large)
		ft_init_g_env();
	if (size < TINY_LIMIT)
	{
		if (g_env.head_tiny == NULL)
			g_env.head_tiny = ft_create_tiny_zone();
		ptr = ft_malloc_tiny(size);
		if (ptr == NULL)
			ptr = ft_add_tiny_zone(size);
	}
	else if (size < SMALL_LIMIT)
	{
		if (g_env.head_small == NULL)
			g_env.head_small = ft_create_small_zone();
		ptr = ft_malloc_small(size);
		if (ptr == NULL)
			ptr = ft_add_small_zone(size);
	}
	else
		ptr = submalloc(size);
	return (ptr);
}
