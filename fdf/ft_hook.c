/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 07:49:52 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 21:12:52 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_switch_bg(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	if (e->background == 0)
		e->background = 1;
	else
		e->background = 0;
	e->img_ptr = mlx_new_image(e->mlx, e->winx, e->winy);
	e->data->data_str = mlx_get_data_addr(e->img_ptr,
			&(e->data->bpp), &(e->data->sl), &(e->data->endian));
	ft_routine(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int		ft_reset(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	e->background = 0;
	e->h = 0;
	e->v = 0;
	e->z = 0.5;
	e->img_ptr = mlx_new_image(e->mlx, e->winx, e->winy);
	e->data->data_str = mlx_get_data_addr(e->img_ptr,
			&(e->data->bpp), &(e->data->sl), &(e->data->endian));
	ft_routine(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		keypress_hook(int keycode, t_env *e)
{
	if (keycode == 65362)
		ft_up(e);
	if (keycode == 65363)
		ft_right(e);
	if (keycode == 65364)
		ft_down(e);
	if (keycode == 65361)
		ft_left(e);
	if (keycode == 65451)
		ft_increase_z(e);
	if (keycode == 65453)
		ft_decrease_z(e);
	if (keycode == 65289)
		ft_switch_bg(e);
	if (keycode == 114)
		ft_reset(e);
	return (0);
}
