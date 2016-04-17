/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 07:39:14 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 21:13:24 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct	s_point
{
	int				x;
	int				y;
}				t_point;

typedef struct	s_data
{
	char			*data_str;
	int				bpp;
	int				sl;
	int				endian;
}				t_data;

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	t_data			*data;
	unsigned int	img_color;
	char			*open;
	int				winx;
	int				winy;
	int				background;
	int				fd;
	int				x;
	int				h;
	int				v;
	float			z;
	int				y;
	int				maxz;
	int				nbx;
	int				nby;
	int				dx;
	int				dy;
}				t_env;

int				ft_up(t_env *e);
int				ft_down(t_env *e);
int				ft_right(t_env *e);
int				ft_left(t_env *e);
int				ft_increase_z(t_env *e);
int				ft_decrease_z(t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode);
int				ft_routine(t_env *e);
int				keypress_hook(int keycode, t_env *e);
int				ft_count_nb(char *str);
int				ft_getnbr(char *str, int x);
int				ft_init_struct(t_env *e);
void			ft_get_color(t_env *e, int z);
void			ft_manage_color(char *line, char *line1, t_env *e, int x);
void			ft_manage_color1(char *line, t_env *e, int x);
void			ft_draw_lign(t_point *p1, t_point *p2, t_env *e);
void			ft_check_map(t_env *e);
void			ft_pixel_put_to_image(unsigned long img_color,
		t_env *e, int x, int y);
t_point			*ft_get_coord(int x, int y, int z, t_env *e);

#endif
