/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 15:41:24 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/21 13:37:49 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		main(int ac, char **av)
{
	char	*str;
	char	**tab;

	if (ac != 2)
		return (0);
	tab = ft_strsplit(av[1], '=');
	if (strcmp(tab[0], av[1]) != 0 && ft_check(ft_strsplit(av[1], ' ')) == 1)
	{
		str = ft_no_space(av[1]);
		tab = ft_strsplit(str, '=');
		ft_resolve(tab[0], tab[1]);
	}
	else
		ft_putendl("Something wrong with the powers...");
	return (0);
}
