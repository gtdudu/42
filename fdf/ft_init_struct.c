/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 07:50:10 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 21:13:23 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_struct(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->img_ptr = NULL;
	if (!(e->data = malloc(sizeof(t_data))))
		return (0);
	e->img_color = 0xff2525;
	e->open = NULL;
	e->winx = 1700;
	e->winy = 1200;
	e->background = 0;
	e->h = 0;
	e->v = 0;
	e->z = 0.5;
	e->fd = 0;
	e->x = 0;
	e->y = 0;
	e->nbx = 0;
	e->nby = 0;
	e->maxz = 1;
	e->dx = 0;
	e->dy = 0;
	return (1);
}
