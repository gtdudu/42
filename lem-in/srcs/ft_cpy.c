/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 18:52:36 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/04 12:10:13 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*ft_cpy_path(t_path *path)
{
	t_path	*new;

	if ((new = malloc(sizeof(t_path))) == NULL)
		return (NULL);
	new->len = path->len;
	new->start = ft_cpy_rooms(path->start);
	new->current_id = path->current_id;
	new->next = NULL;
	return (new);
}

t_room		*ft_cpy_room(t_room *room)
{
	t_room *cpy;

	if ((cpy = malloc(sizeof(t_room))) != NULL)
	{
		cpy->id = room->id;
		cpy->name = ft_strdup(room->name);
		cpy->id_ant = room->id_ant;
		cpy->next = NULL;
	}
	return (cpy);
}

t_room		*ft_cpy_rooms(t_room *room)
{
	t_room *tmp_cpy;
	t_room *tmp;
	t_room *cpy;

	tmp = NULL;
	tmp_cpy = NULL;
	if (((cpy = malloc(sizeof(t_room))) != NULL) && room)
	{
		cpy->id = room->id;
		cpy->name = ft_strdup(room->name);
		cpy->id_ant = room->id_ant;
		cpy->next = room->next;
	}
	if (room)
		tmp = room->next;
	tmp_cpy = cpy;
	while (tmp)
	{
		tmp_cpy->next = ft_cpy_room(tmp);
		tmp_cpy = tmp_cpy->next;
		tmp = tmp->next;
	}
	return (cpy);
}
