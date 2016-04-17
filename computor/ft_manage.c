/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 12:40:22 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/21 13:33:15 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		ft_nb_spaces(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str && str[i])
	{
		if (str[i] == ' ')
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_no_space(char *str)
{
	int		i;
	int		j;
	int		len;
	int		spaces;
	char	*new;

	len = ft_strlen(str);
	spaces = ft_nb_spaces(str);
	new = (char *)malloc(sizeof(char) * len - spaces + 1);
	i = 0;
	j = 0;
	while (str && str[i])
	{
		if (str[i] != ' ')
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}

int		ft_get_max_power(char *str)
{
	int		i;
	int		nb;
	int		tmp;
	int		l;

	i = 0;
	nb = -1;
	tmp = 0;
	l = (int)ft_strlen(str);
	while (str && str[i] && i < l)
	{
		if (str[i] == '^')
		{
			tmp = ft_atoi(&str[i + 1]);
			if (tmp > nb)
				nb = tmp;
		}
		i++;
	}
	return (nb);
}

float	*ft_fill_left(char *str, int max)
{
	float	*tmp;
	int		i;
	int		j;
	int		k;

	tmp = (float *)malloc(sizeof(float) * max + 1);
	i = 0;
	j = 0;
	while (str && str[i])
	{
		tmp[j] = atof(&str[i]);
		k = i + 1;
		while (str && str[k] != '^')
			k++;
		i = k + 1;
		j++;
		i++;
	}
	return (tmp);
}

float	*ft_fill_right(char *str, int max)
{
	float	*tmp;
	int		i;
	int		j;
	int		k;

	tmp = (float *)malloc(sizeof(float) * max);
	i = 0;
	j = 0;
	while (str && str[i])
	{
		tmp[j] = atof(&str[i]);
		k = i + 1;
		while (str && str[k] != '^')
			k++;
		i = k + 1;
		j++;
		i++;
	}
	return (tmp);
}
