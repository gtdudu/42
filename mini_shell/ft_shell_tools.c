/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 04:35:23 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/19 16:35:51 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void	ft_convert_tild(char **tab, t_shell **shell)
{
	int		i;
	char	*begin;

	i = 0;
	begin = NULL;
	while (tab[i])
	{
		if ((begin = ft_strstr(tab[i], "~")) != NULL)
		{
			if (ft_strcmp(tab[i], "~") == 0)
			{
				free(tab[i]);
				tab[i] = ft_strdup((*shell)->home);
			}
			else if (ft_strncmp(tab[i], "~", 1) == 0)
			{
				free(tab[i]);
				tab[i] = ft_strjoin((*shell)->home, &tab[i][1]);
			}
		}
		i++;
	}
}

void	ft_shell_init(t_shell **shell)
{
	if ((*shell) == NULL)
	{
		if (!(*shell = malloc(sizeof(t_shell))))
			ft_putendl("could not malloc shell struct");
		else
		{
			(*shell)->env = NULL;
			(*shell)->line = NULL;
			(*shell)->pwd = NULL;
			(*shell)->oldpwd = NULL;
			(*shell)->home = NULL;
			(*shell)->path = NULL;
			(*shell)->err = NULL;
			(*shell)->done = 1;
			(*shell)->lvl = 0;
		}
	}
}

void	ft_shell_clear(t_shell **shell)
{
	if ((*shell)->env != NULL)
		ft_ctab_clear((*shell)->env);
	if ((*shell)->line != NULL)
		ft_memdel((void*)&(*shell)->line);
	if ((*shell)->pwd != NULL)
		ft_memdel((void*)&(*shell)->pwd);
	if ((*shell)->oldpwd != NULL)
		ft_memdel((void*)&(*shell)->oldpwd);
	if ((*shell)->home != NULL)
		ft_memdel((void*)&(*shell)->home);
	if ((*shell)->path != NULL)
		ft_memdel((void*)&(*shell)->home);
	(*shell)->done = 0;
}
