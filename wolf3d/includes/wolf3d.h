/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 21:22:14 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/23 18:34:02 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <time.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct		s_point
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				lineheight;
	int				drawstart;
	int				drawend;
}					t_point;

typedef struct		s_info
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
}					t_info;

typedef struct		s_data
{
	double			camera_x;
	double			raypos_x;
	double			raypos_y;
	double			raydir_x;
	double			raydir_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	double			step_x;
	double			step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			wall_x;
	double			floor_x_wall;
	double			floor_y_wall;
	int				hit;
	int				side;
	int				map_x;
	int				map_y;
	int				x;
	int				size_line;
	int				size_col;
	int				**world_map;
}					t_data;

typedef struct		s_dat
{
	char			*data_str;
	int				bpp;
	int				sl;
	int				endian;
}					t_dat;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	void		*gun;
	t_data		*d;
	t_info		*info;
	t_dat		*dat;
	int			fd;
	int			winx;
	int			winy;
	int			dx;
	int			dy;
	int			x;
	int			y;
	int			img_color;
	double		pos_x;
	double		dir_x;
	double		frametime;
	double		rotspeed;
	double		movespeed;
}					t_env;

t_env				*ft_check_input(t_env *e, char *av);
int					ft_getnbr(char *str, int x);
int					ft_up(t_env *e);
int					ft_down(t_env *e);
int					ft_left(t_env *e);
int					ft_right(t_env *e);
int					keypress_hook(int keycode, t_env *e);
int					expose_hook(t_env *e);
void				ft_data1(t_env *e, t_info *info, t_data *d, int x);
void				ft_data2(t_data *d);
void				ft_init_data(t_env *e, t_info *info, t_data *d, int x);
void				ft_init(t_env *e);
void				ft_draw_lign(t_point *p, t_env *e);
void				ft_pixel_put_to_image(unsigned long img_color,
		t_env *e, int x, int y);
void				ft_routine(t_env *e, t_info *info, t_data *d);

#endif
