/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:43:11 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 20:43:16 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_get_color(t_env *e, int z)
{
	if (z < (e->maxz / 5))
		e->img_color = RGB(0, 128, 0);
	else if (z < (2 * e->maxz / 5))
		e->img_color = RGB(57, 93, 51);
	else if (z < (3 * e->maxz / 5))
		e->img_color = RGB(100, 100, 10);
	else if (z < (4 * e->maxz / 5))
		e->img_color = RGB(101, 67, 33);
	else if (z < e->maxz)
		e->img_color = RGB(70, 19, 19);
	else
		e->img_color = RGB(51, 0, 25);
}
