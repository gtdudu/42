/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 18:50:29 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/08 02:20:03 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_room(t_room *room)
{
	t_room *tmp;

	tmp = room;
	while (tmp != NULL)
	{
		ft_putstr("id: ");
		ft_putnbr(tmp->id);
		ft_putstr("		|		name: ");
		ft_putstr(tmp->name);
		ft_putstr("		|		id_ant: ");
		ft_putnbr(tmp->id_ant);
		ft_putendl("");
		tmp = tmp->next;
	}
}

void		ft_debug(t_path *paths)
{
	int		i;
	t_path	*tmp;

	tmp = paths;
	i = 0;
	while (tmp)
	{
		ft_putstr("THIS IS PATH NB ");
		ft_putnbr(i);
		ft_putendl(":");
		ft_putstr("Len: ");
		ft_putnbr(tmp->len);
		ft_putendl("");
		ft_print_room(tmp->start);
		i++;
		tmp = tmp->next;
	}
}
