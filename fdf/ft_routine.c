/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 08:02:37 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 21:01:06 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_destroy(t_point *p1, t_point *p2)
{
	if (p1)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2)
	{
		free(p2);
		p2 = NULL;
	}
}

static void	ft_background(t_env *e)
{
	int				x;
	int				y;
	unsigned long	color;

	if (e->background == 1)
	{
		color = RGB(255, 255, 255);
		y = 0;
		while (y < e->winy)
		{
			x = 0;
			while (x < e->winx)
			{
				ft_pixel_put_to_image(color, e, x, y);
				x++;
			}
			y++;
		}
	}
}

static void	ft_subroutine(char *line, char *tmp, int i, t_env *e)
{
	int			x;
	t_point		*p1;
	t_point		*p2;

	x = 0;
	while (x < ft_count_nb(line))
	{
		if (tmp)
		{
			p1 = ft_get_coord(x, i - 1, ft_getnbr(tmp, x), e);
			p2 = ft_get_coord(x, i, ft_getnbr(line, x), e);
			ft_manage_color(line, tmp, e, x);
			if (x < ft_count_nb(tmp))
				ft_draw_lign(p1, p2, e);
		}
		p1 = ft_get_coord(x, i, ft_getnbr(line, x), e);
		p2 = ft_get_coord(x + 1, i, ft_getnbr(line, x + 1), e);
		ft_manage_color1(line, e, x);
		if (x < ft_count_nb(line) - 1)
			ft_draw_lign(p1, p2, e);
		x++;
		ft_destroy(p1, p2);
	}
}

int			ft_routine(t_env *e)
{
	int		i;
	char	*tmp;
	int		ret;
	char	*line;

	line = NULL;
	tmp = NULL;
	i = 0;
	if ((e->fd = open(e->open, O_RDONLY)) < 0)
		return (0);
	e->img_ptr = mlx_new_image(e->mlx, e->winx, e->winy);
	e->data->data_str = mlx_get_data_addr(e->img_ptr, &(e->data->bpp),
			&(e->data->sl), &(e->data->endian));
	ft_background(e);
	while ((ret = get_next_line(e->fd, &line)) > 0)
	{
		ft_subroutine(line, tmp, i, e);
		if (tmp)
			free(tmp);
		tmp = NULL;
		tmp = ft_strdup(line);
		i++;
	}
	close(e->fd);
	return (0);
}
