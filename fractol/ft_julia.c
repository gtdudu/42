/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 22:30:08 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/02 12:07:28 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				testjulia(double newre, double newim, t_env *e)
{
	int		i;
	double	oldre;
	double	oldim;
	double	res;

	i = 0;
	while (i < e->iter)
	{
		oldre = newre;
		oldim = newim;
		newre = oldre * oldre - oldim * oldim + e->opt->cre;
		newim = 2 * oldre * oldim + e->opt->cim;
		res = newre * newre + newim * newim;
		if (res > 4)
			return (i);
		i++;
	}
	return (-1);
}

static double	ft_get_rs(double rs)
{
	double newrs;

	newrs = 255 * 255 * 255 * sin(rs / 2) + 255 *
		255 * sin(rs / 3) + 255 * sin(rs / 5);
	return (newrs);
}

void			julia(t_env *e)
{
	double	x;
	double	y;
	double	newre;
	double	newim;
	double	rs;

	x = -1;
	while (++x < e->winx)
	{
		y = 0;
		while (y < e->winy)
		{
			newre = 1.5 * (x - e->winx / 2) /
				(0.5 * e->opt->zoom * e->winx) + e->opt->movex;
			newim = (y - e->winy / 2) /
				(0.5 * e->opt->zoom * e->winy) + e->opt->movey;
			rs = testjulia(newre, newim, e);
			rs = ft_get_rs(rs);
			if (rs == -1)
				ft_pixel_put_to_image(0x000000, e, x, y);
			else
				ft_pixel_put_to_image(rs, e, x, y);
			y++;
		}
	}
}
