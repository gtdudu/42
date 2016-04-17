/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 12:45:15 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/21 14:59:30 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

float	*ft_reduced(float *f1, float *f2, int max1, int max2)
{
	float	*tmp;
	int		i;
	float	tmp1;
	float	tmp2;
	int		max;

	if (max1 >= max2)
		max = max1;
	else
		max = max2;
	tmp = (float *)malloc(sizeof(float) * max + 1);
	i = 0;
	while (i <= max)
	{
		tmp1 = 0;
		tmp2 = 0;
		if (i <= max1)
			tmp1 = f1[i];
		if (i <= max2)
			tmp2 = f2[i];
		tmp[i] = tmp1 - tmp2;
		i++;
	}
	return (tmp);
}

float	*routine(char *left, char *right)
{
	int		max_power_l;
	int		max_power_r;
	float	*fleft;
	float	*fright;
	float	*reduced;

	max_power_l = ft_get_max_power(left);
	max_power_r = ft_get_max_power(right);
	fleft = ft_fill_left(left, max_power_l);
	fright = ft_fill_right(right, max_power_r);
	reduced = ft_reduced(fleft, fright, max_power_l, max_power_r);
	ft_print(max_power_l, max_power_r, reduced);
	return (reduced);
}

int		ft_aredigits(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_check(char **tab)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '=')
			j = 0;
		if (tab[i][0] == 'X')
		{
			str = ft_strsub(tab[i], 2, ft_strlen(tab[i]));
			if (ft_aredigits(str) != 1)
				return (0);
			if (ft_atoi(str) != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
