/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 06:16:10 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/16 00:34:09 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_data1(t_env *e, t_info *info, t_data *d, int x)
{
	d->camera_x = (2 * (x / (double)e->winx)) - 1;
	d->raypos_x = info->pos_x;
	d->raypos_y = info->pos_y;
	d->raydir_x = info->dir_x + info->plane_x * d->camera_x;
	d->raydir_y = info->dir_y + info->plane_y * d->camera_x;
	d->map_x = (int)d->raypos_x;
	d->map_y = (int)d->raypos_y;
	d->deltadist_x = sqrt(1 + (d->raydir_y * d->raydir_y) /
			(d->raydir_x * d->raydir_x));
	d->deltadist_y = sqrt(1 + (d->raydir_x * d->raydir_x) /
			(d->raydir_y * d->raydir_y));
	d->hit = 0;
}

void	ft_data2(t_data *d)
{
	if (d->raydir_x < 0)
	{
		d->step_x = -1;
		d->sidedist_x = (d->raypos_x - d->map_x) * d->deltadist_x;
	}
	else
	{
		d->step_x = 1;
		d->sidedist_x = (d->map_x + 1.0 - d->raypos_x) * d->deltadist_x;
	}
	if (d->raydir_y < 0)
	{
		d->step_y = -1;
		d->sidedist_y = (d->raypos_y - d->map_y) * d->deltadist_y;
	}
	else
	{
		d->step_y = 1;
		d->sidedist_y = (d->map_y + 1.0 - d->raypos_y) * d->deltadist_y;
	}
}

void	ft_init_data(t_env *e, t_info *info, t_data *d, int x)
{
	ft_data1(e, info, d, x);
	ft_data2(d);
}

void	ft_init(t_env *e)
{
	e->winx = 640;
	e->winy = 480;
	e->info->pos_x = 22;
	e->img_color = 0x000000;
	e->info->pos_y = 12;
	e->info->dir_x = -1;
	e->info->dir_y = 0;
	e->info->plane_x = 0;
	e->info->plane_y = 0.66;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->winx, e->winy, "wolf3d");
}
