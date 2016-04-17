/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:09:30 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/22 18:23:16 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_side(t_piles *piles)
{
	t_pile		*crs;
	int			min;
	int			i;
	int			flag;

	i = 0;
	crs = piles->a;
	flag = 0;
	min = crs->nb;
	while (crs != NULL)
	{
		if (crs->nb < min)
		{
			min = crs->nb;
			flag = i;
		}
		crs = crs->next;
		i++;
	}
	return (flag);
}

void	ft_subforest(t_piles *piles)
{
	int		flag;
	int		i;

	i = -1;
	flag = ft_get_side(piles);
	if (flag >= ft_pile_size(piles->a) / 2)
	{
		while (++i < ft_pile_size(piles->a) - flag)
		{
			ft_putstr("rra ");
			ft_rra(piles);
		}
	}
	else
	{
		while (++i < flag)
		{
			ft_putstr("ra ");
			ft_ra(piles);
		}
	}
	ft_putstr("pb ");
	ft_pb(piles);
}

void	ft_forest(t_piles *piles)
{
	while (ft_pile_size(piles->a) != 1 && ft_pilea_is_sorted(piles) == 0)
		ft_subforest(piles);
	while (ft_pile_size(piles->b) != 1)
	{
		ft_putstr("pa ");
		ft_pa(piles);
	}
	ft_putendl("pa ");
	ft_pa(piles);
}
