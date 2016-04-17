/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 19:59:59 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/23 20:03:57 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int		loop_hook(t_env *e)
{
	ft_pixel_put_to_image(0x000000, e, 20, 20);
	return (0);
}

void	ft_zoom(int x, int y, t_env *e)
{
	if (x > 0 && x <= 90)
		e->opt->movex -= 0.2 / e->opt->zoom;
	else if (x > 90 && x <= 180)
		e->opt->movex -= 0.1 / e->opt->zoom;
	else if (x >= 220 && x < 310)
		e->opt->movex += 0.1 / e->opt->zoom;
	else if (x >= 310)
		e->opt->movex += 0.2 / e->opt->zoom;
	if (y > 0 && y <= 90)
		e->opt->movey -= 0.2 / e->opt->zoom;
	else if (y > 90 && y <= 180)
		e->opt->movey -= 0.1 / e->opt->zoom;
	else if (y >= 220 && y < 310)
		e->opt->movey += 0.1 / e->opt->zoom;
	else if (y >= 310)
		e->opt->movey += 0.2 / e->opt->zoom;
}

int		button_motion_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->opt->cre = -0.7;
		e->opt->cim = 0.254;
		e->opt->movex = 0;
		e->opt->movey = 0;
		e->opt->zoom = 1;
	}
	if ((e->time % 9) == 0)
	{
		if (button == 5)
		{
			ft_zoom(x, y, e);
			e->opt->zoom /= 1.1;
			if (((int)e->opt->zoom % 10) == 0)
				e->iter *= 1.1;
		}
		if (button == 4)
		{
			ft_zoom(x, y, e);
			e->opt->zoom *= 1.1;
		}
	}
	ft_rebuild(e);
	return (0);
}

int		motion_hook(int x, int y, t_env *e)
{
	if (abs(e->opt->oldx - x) > 5 && abs(e->opt->oldy - y) > 5 && e->lock == 0)
	{
		e->opt->cim = 0.005 * (x - (e->winx / 2));
		e->opt->cre = 0.005 * (y - (e->winy / 2));
		e->opt->oldx = x;
		e->opt->oldy = y;
	}
	ft_rebuild(e);
	return (0);
}
