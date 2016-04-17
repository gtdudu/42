/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_tools_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 09:29:23 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/01 21:05:34 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_pile **pile)
{
	int		tmp;

	if ((*pile))
	{
		if (ft_pile_size((*pile)) >= 2)
		{
			tmp = (*pile)->nb;
			(*pile)->nb = (*pile)->next->nb;
			(*pile)->next->nb = tmp;
		}
	}
}

void	ft_push(t_pile **pilea, t_pile **pileb)
{
	t_pile		*tmp;

	if (ft_pile_size((*pileb)) != 0)
	{
		if ((*pilea) == NULL)
			(*pilea) = ft_pile_new((*pileb)->nb);
		else
			(*pilea) = ft_pile_push(&(*pilea), (*pileb)->nb);
		tmp = (*pileb);
		(*pileb) = (*pileb)->next;
		free(tmp);
		tmp = NULL;
		if (*pileb)
			(*pileb)->prev = NULL;
	}
}

void	ft_rotate(t_pile **pile)
{
	if (ft_pile_size((*pile)) > 1)
	{
		ft_pile_add(&(*pile), (*pile)->nb);
		(*pile) = (*pile)->next;
		free((*pile)->prev);
		(*pile)->prev = NULL;
	}
}

void	ft_rotate_rev(t_pile **pile)
{
	t_pile	*tmp;

	if (ft_pile_size((*pile)) > 1)
	{
		tmp = (*pile);
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		(*pile) = ft_pile_push(&(*pile), tmp->nb);
		free(tmp);
	}
}

void	ft_pile_display_all(t_piles *piles)
{
	ft_putendl("");
	ft_putstr("a: ");
	ft_pile_display(piles->a);
	ft_putstr("b: ");
	ft_pile_display(piles->b);
	ft_putendl("");
}
