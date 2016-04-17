/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 22:02:32 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/02 16:08:12 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct		s_square
{
	double			x;
	double			y;
	double			w;
	double			h;
}					t_square;

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

typedef struct		s_opt
{
	double		zoom;
	double		movex;
	double		movey;
	double		cre;
	double		cim;
	double		oldx;
	double		oldy;
}					t_opt;

typedef struct		s_data
{
	char			*data_str;
	int				bpp;
	int				sl;
	int				endian;
}					t_data;

typedef struct		s_env
{
	int			time;
	void		*mlx;
	double		iter;
	void		*win;
	void		*img_ptr;
	t_data		*data;
	t_opt		*opt;
	int			img_color;
	int			winx;
	int			winy;
	char		*str;
	int			lock;
}					t_env;

void				ft_iteration(int keycode, t_env *e);
int					loop_hook(t_env *e);
int					expose_hook(t_env *e);
int					button_motion_hook(int button, int x, int y, t_env *e);
int					motion_hook(int x, int y, t_env *e);
void				ft_rebuild(t_env *e);
int					ft_check_av(char **av, t_env *e);
void				ft_draw_lign(t_point *p1, t_point *p2, t_env *e);
void				julia(t_env *e);
void				douady(t_env *e);
int					testjulia(double newre, double newim, t_env *e);
int					testdouady(double newre, double newim, t_env *e);
int					testmandel(double cre, double cimi, t_env *e);
void				mandel(t_env *e);
void				ft_draw_rect(int x, int y, int a, int b, t_env *e);
void				tapis(double x, double y, double a,
		double b, int n, t_env *e);
void				sierpinski(t_env *e);
void				ft_pixel_put_to_image(int img_color,
		t_env *e, int x, int y);

#endif
