/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 07:55:02 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/12 20:24:20 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_map(t_env *e)
{
	int		ret;
	int		x;
	char	*line;

	while ((ret = get_next_line(e->fd, &line)) > 0)
	{
		if (ft_count_nb(line) > e->nbx)
			e->nbx = ft_count_nb(line);
		e->nby++;
		x = 0;
		while (line[x] != '\0')
		{
			if (ft_getnbr(line, x) > e->maxz)
				e->maxz = ft_getnbr(line, x);
			x++;
		}
	}
}
