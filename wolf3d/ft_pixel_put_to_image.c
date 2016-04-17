/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:07:50 by tdurand           #+#    #+#             */
/*   Updated: 2014/12/16 00:38:56 by 11180            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_pixel_put_to_image(unsigned long img_color, t_env *e, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (x <= e->winx && y <= e->winy)
	{
		r = (img_color & 0xFF0000) >> 16;
		g = (img_color & 0xFF00) >> 8;
		b = (img_color & 0xFF);
		if (e->dat->endian == 0)
		{
			e->dat->data_str[y * e->dat->sl + x * e->dat->bpp / 8] = b;
			e->dat->data_str[y * e->dat->sl + x * e->dat->bpp / 8 + 1] = g;
			e->dat->data_str[y * e->dat->sl + x * e->dat->bpp / 8 + 2] = r;
		}
		else
		{
			e->dat->data_str[y * e->dat->sl + x * e->dat->bpp / 8] = r;
			e->dat->data_str[y * e->dat->sl + x * e->dat->bpp / 8 + 1] = g;
			e->dat->data_str[y * e->dat->sl + x * e->dat->bpp / 8 + 2] = b;
		}
	}
}
