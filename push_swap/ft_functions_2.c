/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 08:08:59 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/13 08:09:23 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_piles *piles)
{
	ft_rotate(&(piles->a));
}

void	ft_rb(t_piles *piles)
{
	ft_rotate(&(piles->b));
}

void	ft_rr(t_piles *piles)
{
	ft_rotate(&(piles->a));
	ft_rotate(&(piles->b));
}

void	ft_rra(t_piles *piles)
{
	ft_rotate_rev(&(piles->a));
}

void	ft_rrb(t_piles *piles)
{
	ft_rotate_rev(&(piles->b));
}
