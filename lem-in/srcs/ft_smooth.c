/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smooth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 02:00:06 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/08 07:14:24 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_check_opt(char *str)
{
	if (str && ft_strcmp(str, "-h") == 0)
		return (1);
	else if (str && ft_strcmp(str, "-s") == 0)
		return (2);
	else if (str && ft_strcmp(str, "-r") == 0)
		return (3);
	else
		return (0);
}

void		ft_print_opt(t_ant *ant, int opt)
{
	if (opt != -1)
		ft_putendl("");
	if (opt == 0)
		ft_putendl("usage: ./lem-in -[h/s/r/m] < [map]");
	else if (opt == 1)
	{
		ft_putendl("-h to get help but you know that already");
		ft_putendl("-s to print the fastest paths");
		ft_putendl("-r to print all rooms");
	}
	else if (opt == 2)
		ft_debug(ant->solution);
	else if (opt == 3)
		ft_print_room(ant->rooms);
}

t_ant		*ft_first_line(t_ant *ant, char *line)
{
	get_next_line(0, &line);
	ft_putendl(line);
	ft_str_digit(ant, line);
	return (ant);
}

t_ant		*ft_switch_id(t_ant *ant, int new_id, int old_id)
{
	t_room	*tmp;

	tmp = ant->rooms;
	while (tmp)
	{
		if (tmp->id == old_id)
			tmp->id = new_id;
		tmp = tmp->next;
	}
	return (ant);
}

t_ant		*ft_correct_id(t_ant *ant)
{
	t_room	*tmp;
	int		l;

	l = ft_room_len(ant->rooms);
	tmp = ant->rooms;
	if (ant->start != NULL && ant->end != NULL)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->name, ant->start) == 0 && tmp->id != 0)
			{
				ant = ft_switch_id(ant, tmp->id, 0);
				tmp->id = 0;
			}
			else if (ft_strcmp(tmp->name, ant->end) == 0 && tmp->id != l - 1)
			{
				ant = ft_switch_id(ant, tmp->id, l - 1);
				tmp->id = l - 1;
			}
			tmp = tmp->next;
		}
	}
	else
		ant->on = 0;
	return (ant);
}
