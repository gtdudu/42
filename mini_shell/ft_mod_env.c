/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 01:29:50 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/13 02:27:20 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int				ft_get_i(char **tab, char *index)
{
	int	i;

	i = 0;
	if (tab && *tab && index)
	{
		while (tab[i])
		{
			if (ft_strncmp(tab[i], ft_strjoin(index, "="),
						ft_strlen(index) + 1) == 0)
				return (i);
			else
				i++;
		}
	}
	return (-1);
}

char			**ft_mod_env(char **tab, char *index, char *str)
{
	int	j;

	j = ft_get_i(tab, index);
	if (j == -1)
		return (NULL);
	free(tab[j]);
	tab[j] = ft_strdup(ft_strjoin(ft_strjoin(index, "="), str));
	return (tab);
}

char			*ft_getstr_env(char **tab, char *index)
{
	int		i;
	int		ltab;
	int		lindex;
	char	*copy;

	copy = NULL;
	i = ft_get_i(tab, index);
	if (i == -1)
		return (NULL);
	ltab = ft_strlen(tab[i]);
	lindex = ft_strlen(index) + 1;
	copy = ft_strsub(tab[i], lindex, ltab - lindex);
	return (copy);
}
