/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 08:18:52 by tdurand           #+#    #+#             */
/*   Updated: 2014/12/30 17:21:53 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getnbr(char *str, int x)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i] && nb != x)
	{
		if (ft_isdigit(str[i]) == 1 && ft_isdigit(str[i + 1]) == 0)
		{
			nb++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (ft_atoi(&str[i]));
}
