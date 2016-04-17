/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 14:37:10 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 12:23:32 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		free(void *ptr)
{
	t_tiny	*tiny;
	t_small	*small;
	t_large	*large;

	if (ptr != NULL)
	{
		tiny = ft_check_if_tiny(ptr);
		small = ft_check_if_small(ptr);
		large = ft_check_if_large(ptr);
		if (tiny != NULL)
		{
			if (ft_remove_from_tab_tiny(ptr, tiny) == 1)
				g_env.head_tiny = ft_delete_zone_tiny(tiny);
		}
		else if (small != NULL)
		{
			if (ft_remove_from_tab_small(ptr, small) == 1)
				g_env.head_small = ft_delete_zone_small(small);
		}
		else if (large != NULL)
			g_env.head_large = ft_delete_zone_large(large);
	}
}
