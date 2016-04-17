/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 19:06:59 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/19 16:35:26 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_secure_env(t_shell **shell)
{
	if (!((*shell)->env = (char **)malloc(sizeof(char*) * 4 + 1)))
		ft_putendl("Could not copy environnement variables");
	else
	{
		(*shell)->env[0] = ft_strjoin("PWD=", getcwd(NULL, 0));
		(*shell)->env[1] = ft_strdup("PATH=user/local/bin:/usr/bin:.");
		(*shell)->env[2] = ft_strdup("SHLVL=2");
		(*shell)->env[4] = NULL;
	}
}

void	ft_dup_env(t_shell **shell, char **environ)
{
	int		i;

	i = 0;
	if (environ != NULL && ft_ctab_len(environ) != 0)
	{
		while (environ[i])
			i++;
		if (!((*shell)->env = (char **)malloc(sizeof(char*) * i + 1)))
			ft_putendl("Could not copy environnement variables");
		else
		{
			i = -1;
			while (environ[++i])
				(*shell)->env[i] = ft_strdup(environ[i]);
			(*shell)->env[i] = NULL;
		}
		(*shell)->pwd = ft_getstr_env(environ, "PWD");
		(*shell)->oldpwd = ft_getstr_env(environ, "OLDPWD");
		(*shell)->home = ft_getstr_env(environ, "HOME");
		(*shell)->path = ft_getstr_env(environ, "PATH");
		if (ft_getstr_env((*shell)->env, "SHLVL") != NULL)
			(*shell)->lvl = 1 + ft_atoi(ft_getstr_env((*shell)->env, "SHLVL"));
	}
	else
		ft_secure_env(&(*shell));
}
