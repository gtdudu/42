/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctab_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 02:46:02 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/19 16:02:04 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static void		ft_else(t_shell **shell, char *index, char *str)
{
	if (strcmp(index, "HOME") == 0)
	{
		free((*shell)->home);
		(*shell)->home = ft_strdup(str);
	}
	else if (strcmp(index, "PWD") == 0)
	{
		free((*shell)->pwd);
		(*shell)->pwd = ft_strdup(str);
	}
	else if (strcmp(index, "OLDPWD") == 0)
	{
		free((*shell)->oldpwd);
		(*shell)->oldpwd = ft_strdup(str);
	}
	else if (strcmp(index, "PATH") == 0)
	{
		free((*shell)->path);
		(*shell)->path = ft_strdup(str);
	}
}

static void		ft_ctab_mod(t_shell **shell, char *index, char *str, int i)
{
	(*shell)->env[i] = 0;
	(*shell)->env[i] = ft_strjoin(ft_strjoin(index, "="), str);
}

void			ft_ctab_push(t_shell **shell, char *index, char *str)
{
	int		i;
	char	**new;

	i = 0;
	new = NULL;
	if (!(new = (char **)malloc(sizeof(char*) *
					ft_ctab_len((*shell)->env) + 2)))
		ft_putendl("Could not malloc modified environnement");
	else
	{
		while ((*shell)->env[i])
		{
			new[i] = ft_strdup((*shell)->env[i]);
			i++;
		}
		new[i] = ft_strdup(new[i - 1]);
		new[i - 1] = ft_strjoin(ft_strjoin(index, "="), str);
		new[0] = ft_strdup((*shell)->env[0]);
		new[i + 1] = NULL;
		ft_ctab_clear((*shell)->env);
		(*shell)->env = new;
	}
}

void			ft_setenv(t_shell **shell, char *index, char *s)
{
	int		i;
	int		flag;
	char	*str;

	i = -1;
	flag = -1;
	if (s == NULL)
		str = "";
	else
		str = s;
	if (index != NULL)
	{
		while ((*shell)->env[++i] && flag == -1)
			if (ft_strncmp((*shell)->env[i],
						ft_strjoin(index, "="), ft_strlen(index) + 1) == 0)
				flag = i;
		if (flag == -1)
			ft_ctab_push(&(*shell), index, str);
		else
			ft_ctab_mod(&(*shell), index, str, flag);
		ft_else(&(*shell), index, str);
	}
}
