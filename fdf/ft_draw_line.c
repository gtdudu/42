/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:52:29 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 21:01:05 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_case1(int xinc, int yinc, int color, t_env *e)
{
	int		i;
	int		cumul;

	i = 1;
	cumul = e->dx / 2;
	while (i <= e->dx)
	{
		e->x += xinc;
		cumul += e->dy;
		if (cumul >= e->dx)
		{
			cumul -= e->dx;
			e->y += yinc;
		}
		ft_pixel_put_to_image(color, e, e->x, e->y);
		i++;
	}
}

static void		ft_case2(int xinc, int yinc, int color, t_env *e)
{
	int		i;
	int		cumul;

	i = 1;
	cumul = e->dy / 2;
	i = 1;
	while (i <= e->dy)
	{
		e->y += yinc;
		cumul += e->dx;
		if (cumul >= e->dy)
		{
			cumul -= e->dy;
			e->x += xinc;
		}
		ft_pixel_put_to_image(color, e, e->x, e->y);
		i++;
	}
}

void			ft_draw_lign(t_point *p1, t_point *p2, t_env *e)
{
	int		xinc;
	int		yinc;

	e->x = p1->x;
	e->y = p1->y;
	e->dx = p2->x - p1->x;
	e->dy = p2->y - p1->y;
	if (e->dx > 0)
		xinc = 1;
	else
		xinc = -1;
	if (e->dy > 0)
		yinc = 1;
	else
		yinc = -1;
	e->dx = abs(e->dx);
	e->dy = abs(e->dy);
	ft_pixel_put_to_image(e->img_color, e, e->x, e->y);
	if (e->dx > e->dy)
		ft_case1(xinc, yinc, e->img_color, e);
	else
		ft_case2(xinc, yinc, e->img_color, e);
}
