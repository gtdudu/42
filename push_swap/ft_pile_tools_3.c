/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 21:08:48 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/13 08:06:45 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*ft_pile_cpy(t_pile *a)
{
	t_pile		*new;

	new = ft_pile_new(a->nb);
	a = a->next;
	while (a != NULL)
	{
		new = ft_pile_add(&new, a->nb);
		a = a->next;
	}
	return (new);
}

void		ft_free(t_pile *pile)
{
	t_pile		*tmp;

	tmp = NULL;
	while (pile != NULL)
	{
		tmp = pile;
		pile = pile->next;
		free(tmp);
		tmp = NULL;
	}
	pile = NULL;
}

int			ft_ten(int *path, int len)
{
	int		i;

	i = 1;
	while (len - i >= 0)
	{
		if (path[len - i] != 10)
			return (len - i);
		i++;
	}
	return (-1);
}

void		ft_set_to_zero(int *path, int len, int start)
{
	int		i;

	i = start;
	while (i < len)
	{
		path[i] = 0;
		i++;
	}
}
