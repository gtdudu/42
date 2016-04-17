/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 19:37:11 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/08 07:20:13 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*ft_init_dist(int len)
{
	int		*dist;
	int		i;

	dist = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (i == 0)
			dist[i] = 1;
		else
			dist[i] = 0;
		i++;
	}
	return (dist);
}

t_path		*ft_init_paths(t_ant *ant)
{
	t_path	*paths;

	if ((paths = malloc(sizeof(t_path))) == NULL)
		return (NULL);
	paths->status = 1;
	paths->id = 0;
	paths->len = 0;
	paths->next = NULL;
	paths->start = ft_get_start(ant);
	paths->current_id = paths->start->id;
	return (paths);
}

t_room		*ft_init_room(int id, char **tab)
{
	t_room *room;

	if ((room = malloc(sizeof(t_room))) != NULL)
	{
		room->id = id;
		room->name = ft_strdup(tab[0]);
		room->id_ant = 0;
		room->prev = NULL;
		room->next = NULL;
	}
	return (room);
}

t_ant		*ft_init_ant(void)
{
	t_ant	*ant;

	if ((ant = malloc(sizeof(t_ant))) != NULL)
	{
		ant->gtg = 0;
		ant->total_ants = 0;
		ant->arrived = 0;
		ant->nb_room = 0;
		ant->on = 1;
		ant->start = NULL;
		ant->end = NULL;
		ant->matrix = NULL;
		ant->rooms = NULL;
		ant->paths = NULL;
		ant->solution = NULL;
	}
	return (ant);
}

char		**ft_init_matrix(int l)
{
	int		i;
	char	**matrix;

	if ((matrix = (char**)malloc(sizeof(char*) * l + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		if ((matrix[i] = (char*)malloc(sizeof(char) * l)) == NULL)
			return (NULL);
		ft_memset(matrix[i], '0', l);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
