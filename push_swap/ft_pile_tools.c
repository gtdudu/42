/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 07:26:10 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/13 07:57:12 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_pile_display(t_pile *pile)
{
	t_pile		*tmp;

	if (pile)
	{
		tmp = pile;
		while (tmp->next)
			tmp = tmp->next;
		while (tmp)
		{
			ft_putnbr(tmp->nb);
			ft_putstr("  ");
			tmp = tmp->prev;
		}
		ft_putendl("");
	}
	return (0);
}

t_pile		*ft_pile_push(t_pile **alst, int nb)
{
	t_pile	*new;

	new = ft_pile_new(nb);
	if (alst && new && (*alst))
	{
		new->next = (*alst);
		(*alst)->prev = new;
		(*alst) = new;
	}
	return ((*alst));
}

t_pile		*ft_pile_add(t_pile **alst, int nb)
{
	t_pile		*begin;
	t_pile		*new;

	new = ft_pile_new(nb);
	if (alst && new && (*alst))
	{
		begin = (*alst);
		if (begin == NULL)
			(*alst) = new;
		else
		{
			while (begin->next)
				begin = begin->next;
			begin->next = new;
			new->prev = begin;
		}
	}
	return ((*alst));
}

t_pile		*ft_pile_new(int nb)
{
	t_pile		*pile;

	if (!(pile = (t_pile *)malloc(sizeof(t_pile))))
		return (NULL);
	else
	{
		pile->nb = nb;
		pile->next = NULL;
		pile->prev = NULL;
	}
	return (pile);
}

int			ft_pile_size(t_pile *pile)
{
	t_pile		*tmp;
	int			i;

	i = 0;
	if (pile)
	{
		tmp = pile;
		while (tmp)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}
