/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:40:04 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 21:13:11 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_up(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	e->v -= 5;
	e->img_ptr = mlx_new_image(e->mlx, e->winx, e->winy);
	e->data->data_str = mlx_get_data_addr(e->img_ptr,
			&(e->data->bpp), &(e->data->sl), &(e->data->endian));
	ft_routine(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int		ft_down(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	e->v += 5;
	e->img_ptr = mlx_new_image(e->mlx, e->winx, e->winy);
	e->data->data_str = mlx_get_data_addr(e->img_ptr,
			&(e->data->bpp), &(e->data->sl), &(e->data->endian));
	ft_routine(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int		ft_right(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	e->h += 5;
	e->img_ptr = mlx_new_image(e->mlx, e->winx, e->winy);
	e->data->data_str = mlx_get_data_addr(e->img_ptr,
			&(e->data->bpp), &(e->data->sl), &(e->data->endian));
	ft_routine(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int		ft_left(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_ptr);
	e->h -= 5;
	e->img_ptr = mlx_new_image(e->mlx, e->winx, e->winy);
	e->data->data_str = mlx_get_data_addr(e->img_ptr,
			&(e->data->bpp), &(e->data->sl), &(e->data->endian));
	ft_routine(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}
