/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 19:01:29 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/08 07:52:13 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant		*ft_add_to_sol(t_ant *ant, t_path *curr)
{
	t_path		*sol;

	sol = ant->solution;
	if (ant->solution == NULL)
	{
		ant->solution = ft_cpy_path(curr);
	}
	else
	{
		while (ant->solution->next)
			ant->solution = ant->solution->next;
		ant->solution->next = ft_cpy_path(curr);
		ant->solution = sol;
	}
	return (ant);
}

t_ant		*ft_add_paths(t_ant *ant, t_path *curr, int i)
{
	t_path	*ptmp;
	t_room	*tmp;

	ptmp = ant->paths;
	while (ptmp->next)
		ptmp = ptmp->next;
	ptmp->next = ft_cpy_path(curr);
	ptmp->next->id = i;
	ptmp->next->len++;
	tmp = ptmp->next->start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_cpy_room(ft_get_room_from_id(ant->rooms, i));
	ptmp->next->current_id = tmp->next->id;
	if (ft_strcmp(tmp->next->name, ant->end) == 0)
	{
		ant = ft_add_to_sol(ant, ptmp->next);
		ptmp->next->status = 2;
		ant->on = 0;
	}
	return (ant);
}

t_path		*ft_get_curr(t_ant *ant, int *dist)
{
	t_path	*tmp;

	tmp = ant->paths;
	while (tmp)
	{
		if (dist[tmp->id] == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_ant		*ft_sub_process(t_ant *ant)
{
	if (ant->paths != NULL)
	{
		ft_del_from_matrix(ant);
		ft_clear_paths(ant->paths);
		ant = ft_process_paths(ant);
	}
	return (ant);
}

t_ant		*ft_process_paths(t_ant *ant)
{
	int		i;
	int		*dist;
	t_path	*del;
	t_path	*curr;

	dist = ft_init_dist(ant->nb_room);
	ant->paths = ft_init_paths(ant);
	curr = ant->paths;
	ant->on = 1;
	while (ant->on == 1 && curr != NULL)
	{
		i = -1;
		while (ant->matrix[curr->current_id][++i])
			if (ant->matrix[curr->current_id][i] == '1' && dist[i] == 0)
				ant = ft_add_paths(ant, curr, i);
		dist[curr->id] = 1;
		curr->status = 0;
		del = ant->paths;
		ant->paths = ant->paths->next;
		ft_clear_rooms(del->start);
		free(del);
		curr = ft_get_curr(ant, dist);
	}
	ant = ft_sub_process(ant);
	return (ant);
}
