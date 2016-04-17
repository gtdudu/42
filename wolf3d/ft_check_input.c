/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:17:28 by tdurand           #+#    #+#             */
/*   Updated: 2015/01/14 05:39:53 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_clear_tab(char **tab, int size)
{
	int		i;

	if (tab && (*tab))
	{
		i = -1;
		while (++i < size)
		{
			free(tab[i]);
		}
		free(tab);
	}
}

int		ft_size_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab && (*tab))
	{
		while (tab[i])
			i++;
	}
	return (i);
}

t_env	*ft_tab_to_int(char **tab, t_env *e, int size)
{
	char	**tmp;
	int		**final_tab;
	int		i;
	int		j;

	i = -1;
	if (!(final_tab = (int **)malloc(sizeof(int *) * size)))
		return (NULL);
	while (++i < size)
	{
		tmp = ft_strsplit(tab[i], ' ');
		if (!(final_tab[i] = (int *)malloc(sizeof(int) * ft_size_tab(tmp))))
			return (NULL);
		e->d->size_line = ft_size_tab(tmp);
		j = -1;
		while (++j < ft_size_tab(tmp))
			final_tab[i][j] = ft_atoi(tmp[j]);
		ft_clear_tab(tmp, ft_size_tab(tmp));
	}
	e->d->world_map = final_tab;
	e->d->size_col = size;
	ft_clear_tab(tab, size);
	return (e);
}

t_env	*ft_check_input(t_env *e, char *av)
{
	char	*line;
	char	**tab;
	int		fd;
	int		cpt;
	int		i;

	cpt = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
		cpt++;
	i = -1;
	if (!(tab = (char **)malloc(sizeof(char *) * cpt)))
		return (0);
	while (++i < cpt)
		if (!(tab[i] = (char *)malloc(ft_strlen(line))))
			return (0);
	close(fd);
	fd = open(av, O_RDONLY);
	i = -1;
	while (get_next_line(fd, &line) > 0)
		tab[++i] = line;
	i = -1;
	e = ft_tab_to_int(tab, e, cpt);
	return (e);
}
