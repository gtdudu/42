/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 06:14:19 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/16 01:02:20 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		keypress_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362)
		ft_up(e);
	if (keycode == 65364)
		ft_down(e);
	if (keycode == 65361)
		ft_left(e);
	if (keycode == 65363)
		ft_right(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->gun, 20, 60);
	return (0);
}
