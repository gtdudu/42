/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:46:40 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/13 08:08:47 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_piles *piles)
{
	ft_swap(&(piles->a));
}

void	ft_sb(t_piles *piles)
{
	ft_swap(&(piles->b));
}

void	ft_ss(t_piles *piles)
{
	ft_swap(&(piles->a));
	ft_swap(&(piles->b));
}

void	ft_pa(t_piles *piles)
{
	ft_push(&(piles->a), &(piles->b));
}

void	ft_pb(t_piles *piles)
{
	ft_push(&(piles->b), &(piles->a));
}
