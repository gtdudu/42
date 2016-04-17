/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 16:13:53 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/02 09:48:46 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

void	ft_rebuild(t_env *e)
{
	e->time++;
	if (e->time >= 2000000)
		e->time = 0;
	if ((e->time % 11) == 0)
	{
		if (ft_strcmp(e->str, "julia") == 0)
		{
			julia(e);
			mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
		}
		if (ft_strcmp(e->str, "mandel") == 0)
		{
			mandel(e);
			mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
		}
		if (ft_strcmp(e->str, "douady") == 0)
		{
			douady(e);
			mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
		}
	}
}

int		key_hook(int keycode, t_env *e)
{
	ft_iteration(keycode, e);
	if (keycode == 65307)
		exit(0);
	if (keycode == 108)
	{
		if (e->lock == 0)
			e->lock = 1;
		else if (e->lock == 1)
			e->lock = 0;
	}
	if (keycode == 65363)
		e->opt->movex -= 0.05 / e->opt->zoom;
	if (keycode == 65361)
		e->opt->movex += 0.05 / e->opt->zoom;
	if (keycode == 65364)
		e->opt->movey -= 0.05 / e->opt->zoom;
	if (keycode == 65362)
		e->opt->movey += 0.05 / e->opt->zoom;
	e->time = 10;
	ft_rebuild(e);
	return (0);
}

void	ft_initiate(t_env *e)
{
	e->winx = 400;
	e->winy = 400;
	e->time = 0;
	e->lock = 1;
	e->str = NULL;
	e->data->data_str = NULL;
	e->iter = 100;
	e->data->bpp = 0;
	e->data->sl = 0;
	e->data->endian = 0;
	e->opt->zoom = 1;
	e->opt->movex = 0;
	e->opt->movey = 0;
	e->opt->cre = -0.7;
	e->opt->cim = 0.25;
	e->opt->oldx = 200;
	e->opt->oldy = 200;
	e->img_ptr = mlx_new_image(e->mlx, e->winx, e->winy);
	e->data->data_str = mlx_get_data_addr(e->img_ptr, &(e->data->bpp),
			&(e->data->sl), &(e->data->endian));
}

void	ft_routine(t_env *e)
{
	if ((e->win = mlx_new_window(e->mlx, e->winx, e->winy, "Fractol")) != NULL)
	{
		mlx_loop_hook(e->win, loop_hook, e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_key_hook(e->win, key_hook, e);
		mlx_hook(e->win, 6, (1L << 6), motion_hook, e);
		mlx_hook(e->win, 4, (1L << 2), button_motion_hook, e);
		mlx_loop(e->mlx);
	}
	free(e->data);
	e->data = NULL;
	free(e->opt);
	e->opt = NULL;
	free(e);
	e = NULL;
}

int		main(int ac, char **av)
{
	t_env			*e;

	if (ac != 2)
		ft_putendl("mandel\njulia\ndouady");
	else
	{
		if (!(e = malloc(sizeof(t_env))))
			return (0);
		if (!(e->data = malloc(sizeof(t_data))))
			return (0);
		if (!(e->opt = malloc(sizeof(t_opt))))
			return (0);
		if ((e->mlx = mlx_init()) != NULL)
		{
			ft_initiate(e);
			if (ft_check_av(av, e) == 0)
				return (0);
			ft_routine(e);
		}
		else
			ft_putendl("Environment is disabled. End of Programm");
	}
	return (0);
}
