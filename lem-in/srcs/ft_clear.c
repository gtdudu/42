/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 18:42:46 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/08 07:14:45 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_clear_paths(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
		ft_clear_rooms(tmp->start);
		tmp->start = NULL;
		free(tmp);
		tmp = NULL;
	}
	path = NULL;
}

void		ft_clear_rooms(t_room *room)
{
	t_room	*tmp;
	t_room	*tofree;

	tmp = room;
	while (tmp)
	{
		tofree = tmp;
		tmp = tmp->next;
		free(tofree->name);
		free(tofree);
		tofree = NULL;
	}
}

void		ft_del_from_matrix_2(t_ant *ant, t_room *rtmp)
{
	int		i;

	while (rtmp != NULL)
	{
		if (ft_strcmp(rtmp->name, ant->start) != 0
				&& ft_strcmp(rtmp->name, ant->end) != 0)
		{
			i = -1;
			while (++i < ant->nb_room)
				ant->matrix[i][rtmp->id] = '0';
			i = -1;
			while (++i < ant->nb_room)
				ant->matrix[rtmp->id][i] = '0';
		}
		else
		{
			ant->matrix[0][rtmp->id] = '0';
			ant->matrix[rtmp->id][0] = '0';
		}
		rtmp = rtmp->next;
	}
}

void		ft_del_from_matrix(t_ant *ant)
{
	t_path	*ptmp;
	t_room	*rtmp;

	ptmp = ant->paths;
	if (ptmp != NULL)
	{
		while (ptmp->next != NULL)
			ptmp = ptmp->next;
		rtmp = ptmp->start;
		ft_del_from_matrix_2(ant, rtmp);
	}
}

void		ft_clear_all(t_ant *ant)
{
	ft_clear_paths(ant->solution);
	ft_ctab_clear(ant->matrix);
	ft_clear_rooms(ant->rooms);
	ant->solution = NULL;
	ant->matrix = NULL;
	ant->rooms = NULL;
	free(ant->start);
	free(ant->end);
	ant->start = NULL;
	ant->end = NULL;
}
