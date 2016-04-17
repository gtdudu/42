/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 21:20:41 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/16 19:49:18 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_free(t_env *e)
{
	free(e->dat);
	free(e->d->world_map);
	free(e->info);
	free(e->d);
	free(e);
	e = NULL;
}

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		return (0);
	if (!(e = malloc(sizeof(t_env))))
		return (0);
	if (!(e->dat = malloc(sizeof(t_data))))
		return (0);
	if (!(e->info = malloc(sizeof(t_info))))
		return (0);
	if (!(e->d = malloc(sizeof(t_data))))
		return (0);
	if (ft_check_input(e, av[1]) == NULL)
		return (0);
	ft_init(e);
	mlx_hook(e->win, 2, (1L << 0), keypress_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	ft_routine(e, e->info, e->d);
	ft_putstr("debug");
	mlx_loop(e->mlx);
	ft_free(e);
	return (0);
}
