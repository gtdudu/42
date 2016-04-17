/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 07:59:15 by tdurand           #+#    #+#             */
/*   Updated: 2014/12/30 16:16:27 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_nb(char *str)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (ft_isdigit(str[i]) == 1 && ft_isdigit(str[i + 1]) == 0)
				nb += 1;
			else if (ft_isdigit(str[i]) == 1 && ft_isdigit(str[i + 1]) == '\0')
				nb += 1;
			i++;
		}
	}
	return (nb);
}
