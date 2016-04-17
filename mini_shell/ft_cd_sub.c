/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 05:11:40 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/12 05:04:08 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int			ft_perm_r(char *tab)
{
	struct stat		filestat;

	if (stat(tab, &filestat) == 0)
	{
		if (!S_ISDIR(filestat.st_mode))
			return (-1);
		if (!(filestat.st_mode & S_IRUSR))
			return (-2);
		if (chdir(tab) != 0)
			return (-3);
	}
	else
		return (0);
	return (1);
}

int			ft_home(t_shell **shell)
{
	struct stat		filestat;

	if (stat((*shell)->home, &filestat) == 0)
	{
		if (!S_ISDIR(filestat.st_mode))
			return (-1);
		if (!(filestat.st_mode & S_IRUSR))
			return (-2);
		if (chdir((*shell)->home) == -1)
			return (-3);
	}
	else
		return (0);
	return (1);
}

int			ft_from_home(t_shell **shell, char *str)
{
	struct stat		filestat;

	if (stat(ft_strjoin((*shell)->home, &str[1]), &filestat) == 0)
	{
		if (!S_ISDIR(filestat.st_mode))
			return (-1);
		if (!(filestat.st_mode & S_IRUSR))
			return (-2);
		if (chdir(ft_strjoin((*shell)->home, &str[1])) == -1)
			return (-3);
	}
	else
	{
		return (0);
	}
	return (1);
}

int			ft_minus(t_shell **shell)
{
	struct stat		filestat;

	if (stat((*shell)->oldpwd, &filestat) == 0)
	{
		if (!S_ISDIR(filestat.st_mode))
			return (-1);
		if (!(filestat.st_mode & S_IRUSR))
			return (-2);
		if (chdir((*shell)->oldpwd) == -1)
			return (-3);
	}
	else
		return (0);
	return (1);
}

void		ft_errors(t_shell **shell, int err, char *str)
{
	if (err == 0)
		(*shell)->err = ft_strjoin("cd: no such file or directory: ", str);
	else if (err == -1)
		(*shell)->err = ft_strjoin("cd: not a directory: ", str);
	else if (err == -2)
		(*shell)->err = ft_strjoin("cd: permission denied: ", str);
	else if (err == -3)
		(*shell)->err = ft_strdup("chdir not working");
	if (err != 1)
	{
		ft_putendl((*shell)->err);
		ft_memdel((void*)&((*shell)->err));
	}
}
