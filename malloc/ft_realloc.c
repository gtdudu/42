/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 16:57:36 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 12:33:27 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*ft_realloc_tiny(void *ptr, size_t size, t_tiny *tiny)
{
	long	i;
	void	*tmp;
	long	old_size;

	if ((i = ft_check_for_wrong_ptr_tiny(ptr, tiny) == -1))
		return (NULL);
	old_size = tiny->tab[i][1];
	ft_remove_from_tab_tiny(ptr, tiny);
	if (size == 0)
		ptr = malloc(1);
	else if ((long)size < TINY_LIMIT
			&& ft_does_it_fit_tiny(tiny->tab, i, size) == 0)
	{
		tiny->total_size -= (size_t)old_size + size;
		ft_update_tab_tiny(tiny->tab, i, size);
	}
	else
	{
		tmp = malloc(size);
		ft_memcpy(tmp, ptr, old_size);
		ptr = tmp;
	}
	if (tiny->total_size == 0)
		ft_delete_zone_tiny(tiny);
	return (ptr);
}

void		*ft_realloc_small(void *ptr, size_t size, t_small *small)
{
	long	i;
	void	*tmp;
	long	old_size;

	if ((i = ft_check_for_wrong_ptr_small(ptr, small) == -1))
		return (NULL);
	old_size = small->tab[i][1];
	ft_remove_from_tab_small(ptr, small);
	if (size == 0)
		ptr = malloc(1);
	else if ((long)size < SMALL_LIMIT &&
			ft_does_it_fit_small(small->tab, i, size) == 0)
	{
		small->total_size += size;
		ft_update_tab_small(small->tab, i, size);
	}
	else
	{
		tmp = malloc(size);
		ft_memcpy(tmp, ptr, old_size);
		ptr = tmp;
	}
	if (small->total_size == 0)
		ft_delete_zone_small(small);
	return (ptr);
}

void		*ft_realloc_large(void *ptr, size_t size, t_large *large)
{
	void	*tmp;

	if (size == 0)
	{
		tmp = malloc(1);
		free(ptr);
	}
	else
	{
		tmp = malloc(size);
		if (size <= large->size)
			ft_memcpy(tmp, ptr, size);
		else
			ft_memcpy(tmp, ptr, large->size);
		free(ptr);
	}
	ptr = tmp;
	return (ptr);
}

void		*ft_routine_realloc(void *ptr, size_t size)
{
	t_tiny	*tiny;
	t_small	*small;
	t_large	*large;

	tiny = ft_check_if_tiny(ptr);
	small = ft_check_if_small(ptr);
	large = ft_check_if_large(ptr);
	if (tiny != NULL)
		ptr = ft_realloc_tiny(ptr, size, tiny);
	else if (small != NULL)
		ptr = ft_realloc_small(ptr, size, small);
	else if (large != NULL)
		ptr = ft_realloc_large(ptr, size, large);
	else
	{
		ft_putendl_fd("\nError pointer was not allocated", 2);
		return (NULL);
	}
	return (ptr);
}

void		*realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
	{
		if (size == 0)
			return (NULL);
		ptr = malloc(size);
	}
	else
		ptr = ft_routine_realloc(ptr, size);
	return (ptr);
}
