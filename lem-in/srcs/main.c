/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:27:17 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/08 07:17:38 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant		*ft_print_move(t_ant *ant, t_room *rtmp, int i, int flag)
{
	if (flag == 1)
	{
		ant->total_ants--;
		ft_putstr("L");
		ft_putnbr(i);
		rtmp->next->id_ant = i;
		ft_putstr("-");
		ft_putstr(rtmp->next->name);
		ft_putstr(" ");
	}
	else if (flag == 2)
	{
		ft_putstr("L");
		ft_putnbr(rtmp->id_ant);
		ft_putstr("-");
		ft_putstr(rtmp->next->name);
		rtmp->next->id_ant = rtmp->id_ant;
		rtmp->id_ant = 0;
		ft_putstr(" ");
	}
	if (ft_strcmp(rtmp->next->name, ant->end) == 0)
		ant->arrived++;
	return (ant);
}

t_path		*ft_return_tmp(t_ant *ant, t_path *tmp, int total)
{
	if (tmp->next == NULL && total != ant->arrived)
	{
		tmp = ant->solution;
		ft_putendl("");
	}
	else
		tmp = tmp->next;
	return (tmp);
}

t_ant		*ft_logic(t_ant *ant, t_path *tmp, t_room *rtmp, int *i)
{
	int		min_len;

	min_len = ant->solution->len;
	if (ft_strcmp(rtmp->name, ant->start) == 0 && ant->total_ants > 0)
	{
		if (ant->total_ants <= min_len && tmp->len == min_len)
		{
			ant = ft_print_move(ant, rtmp, *i, 1);
			*i += 1;
		}
		else if (ant->total_ants > min_len)
		{
			ant = ft_print_move(ant, rtmp, *i, 1);
			*i += 1;
		}
	}
	else if (ft_strcmp(rtmp->name, ant->end) != 0 && rtmp->id_ant != 0)
		ant = ft_print_move(ant, rtmp, *i, 2);
	return (ant);
}

void		ft_print(t_ant *ant)
{
	t_path	*tmp;
	t_room	*rtmp;
	int		total;
	int		i;

	i = 1;
	ft_putendl("");
	total = ant->total_ants;
	tmp = ant->solution;
	while (tmp)
	{
		rtmp = tmp->start;
		while (rtmp->next)
			rtmp = rtmp->next;
		while (rtmp)
		{
			ant = ft_logic(ant, tmp, rtmp, &i);
			rtmp = rtmp->prev;
		}
		tmp = ft_return_tmp(ant, tmp, total);
	}
	ft_putendl("");
	ft_clear_all(ant);
}

int			main(int ac, char **av)
{
	t_ant	*ant;
	int		opt;

	opt = -1;
	if (ac == 2)
		opt = ft_check_opt(av[1]);
	if ((ant = ft_init_ant()) == NULL)
		return (0);
	if ((ant = ft_read_input(ant)) == NULL)
		return (0);
	if (ant->start == NULL || ant->end == NULL || ant->matrix == NULL
			|| ant->rooms == NULL || ant->total_ants == 0)
		ft_putendl_fd("ERROR", 2);
	else
	{
		ant->nb_room = ft_room_len(ant->rooms);
		ant = ft_process_paths(ant);
		ant = ft_double_linked_list(ant);
		ft_print_opt(ant, opt);
		ft_print(ant);
	}
	return (0);
}
