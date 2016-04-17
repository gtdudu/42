/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 17:23:05 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/22 17:23:48 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_pile_is_sorted(t_piles *piles)
{
	t_pile		*tmp;

	if (piles)
	{
		if (piles->b != NULL)
			return (0);
		tmp = piles->a;
		while (tmp->next != NULL)
		{
			if (tmp->nb <= tmp->next->nb)
				tmp = tmp->next;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

int			ft_pilea_is_sorted(t_piles *piles)
{
	t_pile		*tmp;

	if (piles)
	{
		tmp = piles->a;
		while (tmp->next != NULL)
		{
			if (tmp->nb <= tmp->next->nb)
				tmp = tmp->next;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
