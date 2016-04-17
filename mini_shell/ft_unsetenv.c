/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctab_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 02:55:48 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/13 01:59:41 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static void		ft_else(t_shell **shell, char *str)
{
	if (strcmp(str, "HOME") == 0)
	{
		free((*shell)->home);
		(*shell)->home = NULL;
	}
}

void			ft_ctab_pop(t_shell **shell, char *str)
{
	int					i;
	int					j;
	char				**tmp;

	i = 0;
	j = 0;
	tmp = (char**)malloc(sizeof(char*) * ft_ctab_len((*shell)->env));
	if (tmp && str && ft_get_i((*shell)->env, str) >= 0)
	{
		while (i < ft_ctab_len((*shell)->env))
		{
			if (i == ft_get_i((*shell)->env, str))
				i++;
			if (i != ft_ctab_len((*shell)->env))
				tmp[j] = ft_strdup((*shell)->env[i]);
			else
				j--;
			i++;
			j++;
		}
		tmp[j] = NULL;
		ft_ctab_clear((*shell)->env);
		(*shell)->env = tmp;
		ft_else(&(*shell), str);
	}
}
