/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_imput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 18:59:49 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/08 07:14:09 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_str_digit(t_ant *ant, char *str)
{
	int		i;
	int		flag;

	i = 0;
	if (str == NULL)
		ant->on = 0;
	else
	{
		flag = 1;
		while (flag && str[i])
		{
			if (ft_isdigit(str[i]) == 1)
				i++;
			else
			{
				ant->on = 0;
				flag = 0;
			}
		}
		if (flag)
			ant->total_ants = ft_atoi(str);
	}
}

t_ant		*ft_get_tubes(t_ant *ant, char **tab)
{
	char	**r;
	int		l;
	int		id1;
	int		id2;

	if (ant->gtg == 0)
	{
		ant = ft_correct_id(ant);
		ant->gtg++;
	}
	l = ft_room_len(ant->rooms);
	if (ant->matrix == NULL)
		ant->matrix = ft_init_matrix(l);
	r = ft_strsplit(tab[0], '-');
	id1 = ft_get_id(ant->rooms, r[0]);
	id2 = ft_get_id(ant->rooms, r[1]);
	if (id1 >= 0 && id1 < l && id2 >= 0 && id2 < l)
	{
		ant->matrix[id1][id2] = '1';
		ant->matrix[id2][id1] = '1';
	}
	else
		ant->on = 0;
	free(r);
	return (ant);
}

t_ant		*ft_manage_intel(int *tag, t_ant *ant, char **tab)
{
	t_room	*tmp;

	if (ft_ctab_len(tab) == 3)
	{
		tmp = ant->rooms;
		if (tmp == NULL)
			ant->rooms = ft_init_room(*tag, tab);
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = ft_init_room(*tag, tab);
		}
	}
	else if (ft_ctab_len(tab) == 1)
		ant = ft_get_tubes(ant, tab);
	else
		ant->on = 0;
	return (ant);
}

t_ant		*ft_manage_cmd(t_ant *ant, char *line, char **tab)
{
	if (ant->on == 2 && ft_ctab_len(tab) != 0)
		ant->start = ft_strdup(tab[0]);
	else if (ant->on == 3 && ft_ctab_len(tab) != 0)
		ant->end = ft_strdup(tab[0]);
	ant->on = 1;
	if (ft_strncmp(line, "##", 2) == 0)
	{
		if (ft_strcmp(line, "##start") == 0)
			ant->on = 2;
		else if (ft_strcmp(line, "##end") == 0)
			ant->on = 3;
		else
			ant->on = 0;
	}
	return (ant);
}

t_ant		*ft_read_input(t_ant *ant)
{
	int				tag;
	char			*line;
	char			**tab;

	tag = 0;
	line = NULL;
	ant = ft_first_line(ant, line);
	while (ant->on >= 1 && get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		if (line != NULL)
		{
			tab = ft_strsplit(line, ' ');
			ant = ft_manage_cmd(ant, line, tab);
			if (ft_strncmp(line, "#", 1) != 0 && ft_strncmp(line, "L", 1) != 0)
			{
				ant = ft_manage_intel(&tag, ant, tab);
				tag++;
			}
			free(tab);
		}
		else
			ant->on = 0;
	}
	return (ant);
}
