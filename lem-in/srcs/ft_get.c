/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 18:57:46 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/05 02:39:31 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant		*ft_double_linked_list(t_ant *ant)
{
	t_path		*tmp;
	t_room		*rtmp;
	t_room		*prev;

	tmp = ant->solution;
	while (tmp)
	{
		prev = tmp->start;
		prev->prev = NULL;
		rtmp = prev->next;
		rtmp->prev = prev;
		while (rtmp)
		{
			rtmp->prev = prev;
			prev = prev->next;
			rtmp = rtmp->next;
		}
		tmp = tmp->next;
	}
	return (ant);
}

int			ft_room_len(t_room *room)
{
	t_room		*tmp;
	int			i;

	tmp = room;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			ft_get_id(t_room *room, char *name)
{
	t_room	*tmp;

	tmp = room;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp->id);
		tmp = tmp->next;
	}
	return (0);
}

t_room		*ft_get_start(t_ant *ant)
{
	t_room	*tmp;

	tmp = ant->rooms;
	while (tmp)
	{
		if (ft_strcmp(ant->start, tmp->name) == 0)
			return (ft_cpy_room(tmp));
		tmp = tmp->next;
	}
	return (NULL);
}

t_room		*ft_get_room_from_id(t_room *room, int id)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->id == id)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
