/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_call.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 02:04:17 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/12 05:04:10 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static char		*ft_add_last_slash(char *str)
{
	char	*res;

	res = NULL;
	if (str)
	{
		if (str[ft_strlen(str) - 1] != '/')
			res = ft_strjoin(str, "/");
		else
			res = ft_strdup(str);
	}
	return (res);
}

static int		ft_check_dot(t_shell **shell, char **tab, char *str)
{
	int			err;
	struct stat filestat;

	err = 0;
	if (stat(str, &filestat) == 0)
	{
		if (filestat.st_mode & S_IXUSR)
			execve(str, tab, (*shell)->env);
		else
			err = 1;
	}
	else
		err = 2;
	return (err);
}

static void		ft_error(t_shell **shell, char *str, int err)
{
	if (err == 1)
		ft_putendl((*shell)->err =
				ft_strjoin("myshell: permission denied: ", str));
	else
		ft_putendl((*shell)->err = ft_strjoin(str, ": command not found"));
}

int				ft_path_call(t_shell **shell, char **tab)
{
	char		*call;
	char		**path;
	int			i;
	int			err;

	err = 0;
	i = -1;
	if (tab[0][0] == '/' || tab[0][0] == '.')
		err = ft_check_dot(shell, tab, tab[0]);
	if ((*shell)->path == NULL)
	{
		ft_putendl((*shell)->err = ft_strjoin(tab[0], ": command not found"));
		exit (0);
	}
	path = ft_strsplit((*shell)->path, ':');
	while (path[++i])
	{
		call = ft_strjoin(ft_add_last_slash(path[i]), tab[0]);
		err = ft_check_dot(&(*shell), tab, call);
		ft_memdel((void*)&call);
	}
	ft_ctab_clear(path);
	ft_error(&(*shell), tab[0], err);
	exit (0);
	return (0);
}
