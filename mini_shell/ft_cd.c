/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 02:04:41 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/13 03:47:50 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static void		ft_update(t_shell **shell)
{
	(*shell)->oldpwd = ft_strdup((*shell)->pwd);
	(*shell)->pwd = ft_strdup(getcwd(NULL, 0));
	ft_mod_env((*shell)->env, "OLDPWD", (*shell)->oldpwd);
	ft_mod_env((*shell)->env, "PWD", getcwd(NULL, 0));
}

static void		ft_cd_2(t_shell **shell, char **tab)
{
	int		err;

	if (ft_strcmp(tab[1], "~") == 0)
	{
		err = ft_home(&(*shell));
		ft_errors(&(*shell), err, (*shell)->home);
	}
	else if (tab[1][0] == '~' && ft_strlen(tab[1]) > 1)
	{
		err = ft_from_home(&(*shell), tab[1]);
		ft_errors(&(*shell), err, tab[1]);
	}
	else if (ft_strcmp(tab[1], "-") == 0)
	{
		err = ft_minus(&(*shell));
		ft_errors(&(*shell), err, (*shell)->oldpwd);
	}
	else
	{
		err = ft_perm_r(tab[1]);
		ft_errors(&(*shell), err, tab[1]);
	}
	ft_update(&(*shell));
}

static void		ft_cd_3(t_shell **shell, char **tab)
{
	char	*begin;
	char	*replaced;
	int		ibegin;
	int		err;

	if ((begin = ft_strstr((*shell)->pwd, tab[1])) == NULL)
	{
		(*shell)->err = ft_strjoin("cd: string not in pwd: ", tab[1]);
		ft_putendl((*shell)->err);
	}
	else
	{
		ibegin = ft_strlen((*shell)->pwd) - ft_strlen(begin);
		replaced = ft_strjoin(ft_strjoin(ft_strsub((*shell)->pwd, 0, ibegin),
				tab[2]), ft_strsub((*shell)->pwd, ibegin + ft_strlen(tab[1]),
					ft_strlen(begin) - ft_strlen(tab[1])));
		err = ft_perm_r(replaced);
		if (err == 1)
		{
			ft_putendl(replaced);
			ft_update(&(*shell));
		}
		ft_errors(&(*shell), err, replaced);
	}
}

void			ft_cd(t_shell **shell, char **tab)
{
	int err;

	(*shell)->err = NULL;
	if (ft_ctab_len(tab) == 1)
	{
		err = ft_home(&(*shell));
		ft_errors(&(*shell), err, (*shell)->oldpwd);
	}
	else if (ft_ctab_len(tab) == 2)
		ft_cd_2(&(*shell), tab);
	else if (ft_ctab_len(tab) == 3)
		ft_cd_3(&(*shell), tab);
	else
		(*shell)->err = ft_strjoin("cd : string not in pwd: ", tab[1]);
}
