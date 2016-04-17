/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 07:37:06 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/02 09:45:48 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		return (0);
	if (!(e = malloc(sizeof(t_env))) || (ft_init_struct(e) != 1))
		return (0);
	if ((e->fd = open(av[1], O_RDONLY)) < 0)
		return (0);
	ft_check_map(e);
	close(e->fd);
	if (!(e->mlx = mlx_init()))
		return(0);
	if (!(e->open = ft_strdup(av[1])))
		return (0);
	ft_routine(e);
	e->win = mlx_new_window(e->mlx, e->winx, e->winy, "Fil de fer");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_hook(e->win, 2, (1L << 0), keypress_hook, e);
	mlx_loop(e->mlx);
	free(e->data);
	e->data = NULL;
	free(e);
	e = NULL;
	return (0);
}
