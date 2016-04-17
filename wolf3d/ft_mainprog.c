/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mainprog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 06:34:29 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/19 16:38:36 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_dda(t_data *d)
{
	while (d->hit == 0)
	{
		if (d->sidedist_x < d->sidedist_y)
		{
			d->sidedist_x += d->deltadist_x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->sidedist_y += d->deltadist_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (d->world_map[d->map_x][d->map_y] > 0)
			d->hit = 1;
	}
	if (d->side == 0)
		d->perpwalldist = fabs((d->map_x - d->raypos_x +
					(1 - d->step_x) / 2) / d->raydir_x);
	else
		d->perpwalldist = fabs((d->map_y - d->raypos_y +
					(1 - d->step_y) / 2) / d->raydir_y);
}

void		ft_get_color(t_data *d, t_env *e)
{
	if (d->world_map[d->map_x][d->map_y] == 9)
		e->img_color = 0x000000;
	else if (d->world_map[d->map_x][d->map_y] == 8)
		e->img_color = 0x000000;
	else if (d->map_y < e->info->pos_y && d->side == 1)
		e->img_color = 0x79dd74;
	else if (d->map_y > e->info->pos_y && d->side == 1)
		e->img_color = 0x482E74;
	else if (d->map_x > e->info->pos_x && d->side == 0)
		e->img_color = 0xbfbf00;
	else
		e->img_color = 0xf65600;
}

void		ft_subdraw(t_env *e, t_point *p, int x)
{
	p->x1 = x;
	p->x2 = x;
	p->y1 = p->drawstart;
	p->y2 = p->drawend;
	ft_draw_lign(p, e);
	if (p->drawend < 0)
		p->drawend = e->winy;
	p->x1 = x;
	p->x2 = x;
	p->y1 = p->drawend;
	p->y2 = e->winy;
	e->img_color = 0x333333;
	ft_draw_lign(p, e);
}

void		ft_draw(t_env *e, t_data *d, int x)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->lineheight = abs((int)(e->winx / d->perpwalldist));
	p->drawstart = (-1 * p->lineheight / 2) + (e->winy / 2);
	if (p->drawstart < 0)
		p->drawstart = 0;
	p->drawend = (p->lineheight / 2) + (e->winy / 2);
	if (p->drawend >= e->winy)
		p->drawend = e->winy - 1;
	if (d->side == 1)
		d->wall_x = d->raypos_x + ((d->map_y - d->raypos_y +
					(1 - d->step_y) / 2) / d->raydir_y) * d->raydir_x;
	else
		d->wall_x = d->raypos_y + ((d->map_x - d->raypos_x +
					(1 - d->step_x) / 2) / d->raydir_x) * d->raydir_y;
	ft_get_color(d, e);
	ft_subdraw(e, p, x);
	free(p);
	p = NULL;
}

void		ft_routine(t_env *e, t_info *info, t_data *d)
{
	struct timeval	start;
	struct timeval	end;
	long			st;
	long			en;

	e->img_ptr = mlx_xpm_file_to_image(e->mlx, "b.xpm", &(e->winx), &(e->winy));
	e->gun = mlx_xpm_file_to_image(e->mlx, "image.xpm", &(e->winx), &(e->winy));
	e->dat->data_str = mlx_get_data_addr(e->img_ptr, &(e->dat->bpp),
			&(e->dat->sl), &(e->dat->endian));
	gettimeofday(&start, NULL);
	st = (start.tv_sec * 1000000 + start.tv_usec);
	d->x = -1;
	while (++d->x < e->winx)
	{
		ft_init_data(e, info, d, d->x);
		ft_dda(d);
		ft_draw(e, d, d->x);
	}
	gettimeofday(&end, NULL);
	en = (end.tv_sec * 1000000 + end.tv_usec);
	e->frametime = (double)(en - st) / 1000000;
	e->rotspeed = e->frametime * 30.0;
	e->movespeed = e->frametime * 100.0;
}
