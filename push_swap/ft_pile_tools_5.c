/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_tools_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 08:30:54 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/22 18:19:07 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_cpy(t_piles *cpy)
{
	ft_free(cpy->a);
	ft_free(cpy->b);
	free(cpy);
	cpy = NULL;
}

int			apply_functions_sub_sub(t_piles *piles,
		int *path, int size, void (**tab)(t_piles *piles))
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = path[i];
		if (j >= 0 && j <= 10)
			(*tab[j]) (piles);
		i++;
	}
	return (1);
}

int			apply_functions_sub(t_piles *piles,
		int *path, int size, void (**tab)(t_piles *piles))
{
	int			i;
	int			j;
	t_piles		*cpy;

	if (!(cpy = malloc(sizeof(piles))))
		return (0);
	cpy->a = ft_pile_cpy(piles->a);
	cpy->b = NULL;
	i = 0;
	while (i < size)
	{
		j = path[i];
		if (j >= 0 && j <= 10)
			(*tab[j]) (cpy);
		i++;
	}
	if (ft_pile_is_sorted(cpy))
	{
		ft_display_path(path, i);
		if (apply_functions_sub_sub(piles, path, size, tab) == 1)
			return (1);
	}
	else
		ft_free_cpy(cpy);
	return (0);
}

int			ft_apply_functions(t_piles *piles, int *path, int size)
{
	void		(*tab[11]) (t_piles *piles);

	tab[0] = ft_sa;
	tab[1] = ft_sb;
	tab[2] = ft_ss;
	tab[3] = ft_pa;
	tab[4] = ft_pb;
	tab[5] = ft_ra;
	tab[6] = ft_rb;
	tab[7] = ft_rr;
	tab[8] = ft_rra;
	tab[9] = ft_rrb;
	tab[10] = ft_rrr;
	if (apply_functions_sub(piles, path, size, tab) == 1)
		return (1);
	else
		return (0);
}
