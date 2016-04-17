/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 18:14:35 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/02 09:14:11 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int		ft_check_av(char **av, t_env *e)
{
	if (ft_strcmp(av[1], "mandel") == 0)
	{
		e->opt->movex = -0.5;
		e->str = ft_strdup("mandel");
		mandel(e);
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		e->str = ft_strdup("julia");
		julia(e);
	}
	else if (ft_strcmp(av[1], "douady") == 0)
	{
		e->str = ft_strdup("douady");
		douady(e);
	}
	else
	{
		ft_putstr("mandel\njulia\ndouady\n");
		return (0);
	}
	return (1);
}

void	ft_iteration(int keycode, t_env *e)
{
	if (keycode == 65451)
	{
		e->iter += 5;
		if (e->iter >= 200)
			e->iter = 200;
	}
	if (keycode == 65453)
	{
		e->iter -= 5;
		if (e->iter <= 5)
			e->iter = 5;
	}
}
