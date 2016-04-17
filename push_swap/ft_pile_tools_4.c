/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_tools_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 07:58:38 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/13 08:40:32 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_display_path_sub(int *path, int i)
{
	if (path[i] == 0)
		ft_putstr("sa");
	if (path[i] == 1)
		ft_putstr("sb");
	if (path[i] == 2)
		ft_putstr("ss");
	if (path[i] == 3)
		ft_putstr("pa");
	if (path[i] == 4)
		ft_putstr("pb");
	if (path[i] == 5)
		ft_putstr("ra");
	if (path[i] == 6)
		ft_putstr("rb");
	if (path[i] == 7)
		ft_putstr("rr");
	if (path[i] == 8)
		ft_putstr("rra");
	if (path[i] == 9)
		ft_putstr("rrb");
	if (path[i] == 10)
		ft_putstr("rrr");
}

void		ft_display_path(int *path, int len)
{
	int		i;

	i = 0;
	if (path && len != 0)
	{
		while (i < len)
		{
			ft_display_path_sub(path, i);
			if (i != len - 1)
				ft_putstr(" ");
			i++;
		}
		ft_putendl("");
	}
}
