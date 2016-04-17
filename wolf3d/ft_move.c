/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 06:12:20 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/16 01:34:29 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_up(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	mlx_destroy_image(e->mlx, e->gun);
	if (e->d->world_map[(int)(e->info->pos_x + e->info->dir_x *
				e->movespeed)][(int)(e->info->pos_y)] == 9)
	{
		e->info->pos_x = 19;
		e->info->pos_y = 20;
	}
	if (e->d->world_map[(int)(e->info->pos_x + e->info->dir_x *
				e->movespeed)][(int)(e->info->pos_y)] == 8)
	{
		e->info->pos_x = 25;
		e->info->pos_y = 22;
	}
	if (e->d->world_map[(int)(e->info->pos_x + e->info->dir_x *
				e->movespeed)][(int)(e->info->pos_y)] == 0)
		e->info->pos_x += (e->info->dir_x * e->movespeed);
	if (e->d->world_map[(int)(e->info->pos_x)][(int)(e->info->pos_y +
				e->info->dir_y * e->movespeed)] == 0)
		e->info->pos_y += (e->info->dir_y * e->movespeed);
	ft_routine(e, e->info, e->d);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->gun, 20, 60);
	return (0);
}

int		ft_down(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	mlx_destroy_image(e->mlx, e->gun);
	if (e->d->world_map[(int)(e->info->pos_x - e->info->dir_x *
				e->movespeed)][(int)(e->info->pos_y)] == 9)
	{
		e->info->pos_x = 19;
		e->info->pos_y = 20;
	}
	if (e->d->world_map[(int)(e->info->pos_x - e->info->dir_x *
				e->movespeed)][(int)(e->info->pos_y)] == 8)
	{
		e->info->pos_x = 25;
		e->info->pos_y = 22;
	}
	if (e->d->world_map[(int)(e->info->pos_x - e->info->dir_x *
				e->movespeed)][(int)(e->info->pos_y)] == 0)
		e->info->pos_x -= (e->info->dir_x * e->movespeed);
	if (e->d->world_map[(int)(e->info->pos_x)][(int)(e->info->pos_y -
				e->info->dir_y * e->movespeed)] == 0)
		e->info->pos_y -= (e->info->dir_y * e->movespeed);
	ft_routine(e, e->info, e->d);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->gun, 20, 60);
	return (0);
}

int		ft_left(t_env *e)
{
	double		olddir_x1;
	double		oldplane_x1;

	mlx_destroy_image(e->mlx, e->img_ptr);
	mlx_destroy_image(e->mlx, e->gun);
	olddir_x1 = e->info->dir_x;
	e->info->dir_x = (e->info->dir_x * cos(e->rotspeed)) -
		(e->info->dir_y * sin(e->rotspeed));
	e->info->dir_y = (olddir_x1 * sin(e->rotspeed)) +
		(e->info->dir_y * cos(e->rotspeed));
	oldplane_x1 = e->info->plane_x;
	e->info->plane_x = (e->info->plane_x * cos(e->rotspeed)) -
		(e->info->plane_y * sin(e->rotspeed));
	e->info->plane_y = (oldplane_x1 * sin(e->rotspeed)) +
		(e->info->plane_y * cos(e->rotspeed));
	ft_routine(e, e->info, e->d);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->gun, 20, 60);
	return (0);
}

int		ft_right(t_env *e)
{
	double		olddir_x2;
	double		oldplane_x2;

	mlx_destroy_image(e->mlx, e->img_ptr);
	mlx_destroy_image(e->mlx, e->gun);
	olddir_x2 = e->info->dir_x;
	e->info->dir_x = (e->info->dir_x * cos(-1 * e->rotspeed)) -
		(e->info->dir_y * sin(-1 * e->rotspeed));
	e->info->dir_y = (olddir_x2 * sin(-1 * e->rotspeed)) +
		(e->info->dir_y * cos(-1 * e->rotspeed));
	oldplane_x2 = e->info->plane_x;
	e->info->plane_x = (e->info->plane_x * cos(-1 * e->rotspeed)) -
		(e->info->plane_y * sin(-1 * e->rotspeed));
	e->info->plane_y = (oldplane_x2 * sin(-1 * e->rotspeed)) +
		(e->info->plane_y * cos(-1 * e->rotspeed));
	ft_routine(e, e->info, e->d);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->gun, 20, 60);
	return (0);
}
