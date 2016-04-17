/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 08:23:33 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 21:12:54 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*ft_get_coord(int x, int y, int z, t_env *e)
{
	t_point	*o;
	t_point	*p;

	if (!(o = malloc(sizeof(t_point))))
		return (NULL);
	o->x = 60 + e->h;
	o->y = (e->winy / 2);
	if (!(p = malloc(sizeof(t_point))))
		return (NULL);
	p->x = o->x + x * (e->winx / (2 * e->nbx)) + y
		* 2 * (e->winy / (3 * e->nby));
	p->y = o->y + e->v + y * (e->winy - o->y) / (3 * e->nby) - x
		* o->y / (2 * e->nbx) - (e->z * z);
	free(o);
	o = NULL;
	return (p);
}
