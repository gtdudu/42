/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 23:27:18 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/02 12:10:23 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				testmandel(double cre, double cim, t_env *e)
{
	int			i;
	double		oldre;
	double		oldim;
	double		newre;
	double		newim;

	i = 0;
	oldre = 0.0;
	oldim = 0.0;
	while (i < e->iter)
	{
		newre = oldre * oldre - oldim * oldim + cre;
		newim = 2 * oldre * oldim + cim;
		oldre = newre;
		oldim = newim;
		if ((newre * newre + newim * newim) > 4)
			return (i);
		i++;
	}
	return (-1);
}

static double	ft_get_rs(double rs)
{
	double newrs;

	newrs = 255 * 255 * 255 * sin(rs) + 255 *
		255 * sin(rs / 2) + 255 * sin(rs * 10);
	return (newrs);
}

void			mandel(t_env *e)
{
	double		x;
	double		y;
	double		cre;
	double		cim;
	int			res;

	x = 0;
	while (x < e->winx)
	{
		y = 0;
		while (y < e->winy)
		{
			cre = 1.5 * (x - e->winx / 2) /
				(0.5 * e->opt->zoom * e->winx) + e->opt->movex;
			cim = (y - e->winy / 2) /
				(0.5 * e->opt->zoom * e->winy) + e->opt->movey;
			res = ft_get_rs(testmandel(cre, cim, e));
			if (res == -1)
				ft_pixel_put_to_image(0x000000, e, x, y);
			else
				ft_pixel_put_to_image(res * 255 * res * res, e, x, y);
			y++;
		}
		x++;
	}
}
