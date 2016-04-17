/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 08:05:11 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/13 08:32:58 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*ft_inc(int *path, int *len)
{
	int		mod;
	int		*tmp;

	mod = 0;
	if ((mod = ft_ten(path, *len)) == -1)
	{
		*len += 1;
		if (!(tmp = (int *)malloc(sizeof(int) * *len)))
			return (NULL);
		ft_set_to_zero(tmp, *len, 0);
		free(path);
		path = NULL;
		return (tmp);
	}
	else
	{
		path[mod] += 1;
		if (path[mod] == 0 || path[mod] == 1 || path[mod] == 2)
			if (mod != 0 && path[mod] == path[mod - 1])
				path[mod] += 1;
		ft_set_to_zero(path, *len, mod + 1);
		return (path);
	}
	return (NULL);
}

int			ft_get_sizes(int *path, int *len, int a)
{
	int		i;
	int		sizea;
	int		sizeb;

	sizeb = 0;
	sizea = a;
	i = 0;
	while (i < *len)
	{
		if (sizeb > 0 && path[i] == 3)
		{
			sizea += 1;
			sizeb -= 1;
		}
		else if (sizea > 0 && path[i] == 4)
		{
			sizeb += 1;
			sizea -= 1;
		}
		i++;
	}
	return (sizeb);
}

int			ft_solve(t_piles *piles)
{
	int			flag;
	int			*path;
	int			len;

	len = 1;
	flag = 0;
	if (ft_pile_is_sorted(piles))
		flag = 1;
	if (!(path = (int *)malloc(sizeof(int) * len)))
		return (-1);
	path[len - 1] = 0;
	while (!flag)
	{
		if (ft_get_sizes(path, &len, ft_pile_size(piles->a)) == 0)
		{
			if (ft_apply_functions(piles, path, len) == 1)
				flag = 1;
		}
		path = ft_inc(path, &len);
	}
	return (0);
}
