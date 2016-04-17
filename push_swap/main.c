/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 07:02:01 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/22 18:11:00 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_routine(char **av, t_piles *piles)
{
	int		i;
	int		size;

	i = 1;
	while (av[i])
	{
		if (piles->a == NULL)
			piles->a = ft_pile_new(ft_atoi(av[i]));
		else
			piles->a = ft_pile_add(&(piles->a), ft_atoi(av[i]));
		i++;
	}
	size = ft_pile_size(piles->a);
	if (size <= 5)
		ft_solve(piles);
	else
		ft_forest(piles);
	if (piles->a)
		ft_free(piles->a);
	free(piles);
	piles = NULL;
}

int		ft_check_doublon(char **av, int ac)
{
	int		i;
	int		j;
	char	*tmp;
	int		flag;

	j = 1;
	while (j < ac)
	{
		flag = 0;
		i = 1;
		tmp = ft_strdup(av[j]);
		while (av[i])
		{
			if (ft_strcmp(av[i], tmp) == 0)
				flag++;
			i++;
		}
		if (flag != 1)
			return (0);
		j++;
	}
	return (1);
}

int		ft_check_int(char **av, int ac)
{
	int		i;
	long	nb;

	i = 0;
	while (i < ac)
	{
		nb = ft_custom_atoi(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (0);
		else
			i++;
	}
	return (1);
}

int		ft_check_ifnb(char **av, int ac)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == 43 || av[i][j] == 45)
			j++;
		while (av[i][j])
		{
			if (av[i][j] >= 48 && av[i][j] <= 57)
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_piles	*piles;

	if (ac == 1)
		return (0);
	if (!(piles = malloc(sizeof(t_piles))))
		return (0);
	piles->a = NULL;
	piles->b = NULL;
	if (ft_check_doublon(av, ac) == 1 && ft_check_ifnb(av, ac) == 1
			&& ft_check_int(av, ac) == 1)
		ft_routine(av, piles);
	else
		ft_putendl("Error");
	return (0);
}
