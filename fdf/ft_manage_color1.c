/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_color1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:13:55 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 20:43:36 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_manage_color1(char *line, t_env *e, int x)
{
	if (ft_getnbr(line, x) > 0 || ft_getnbr(line, x + 1) > 0)
	{
		if (ft_getnbr(line, x) > ft_getnbr(line, x + 1))
			ft_get_color(e, ft_getnbr(line, x));
		else
			ft_get_color(e, ft_getnbr(line, x + 1));
	}
	else
		e->img_color = RGB(28, 107, 160);
}
