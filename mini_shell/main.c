/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 01:33:38 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/19 16:07:37 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static void		ft_manage_call(t_shell **shell, char **tab)
{
	pid_t		pid;

	pid = 4 * 2;
	pid = fork();
	if (pid != -1)
	{
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			ft_path_call(&(*shell), tab);
		}
		else
		{
			signal(SIGINT, ft_sig_handler_2);
			waitpid(pid, NULL, 0);
			signal(SIGINT, ft_sig_handler);
		}
	}
	else
		ft_putendl("Error while forking");
}

static void		ft_parse(t_shell **shell, char **tab)
{
	int		k;

	k = 0;
	ft_convert_tild(tab, &(*shell));
	if (strcmp(tab[0], "exit") == 0)
		(*shell)->done = 0;
	else if ((*shell)->env != NULL)
	{
		if (strcmp(tab[0], "unsetenv") == 0)
			while (tab[++k])
				ft_ctab_pop(&(*shell), tab[k]);
		else if (strcmp(tab[0], "setenv") == 0 && ft_ctab_len(tab) > 3)
			ft_putendl("setenv: Too many arguments");
		else if (strcmp(tab[0], "setenv") == 0 && ft_ctab_len(tab) == 3)
			ft_setenv(&(*shell), tab[1], tab[2]);
		else if (strcmp(tab[0], "setenv") == 0 && ft_ctab_len(tab) == 2)
			ft_setenv(&(*shell), tab[1], NULL);
		else if (strcmp(tab[0], "env") == 0)
			ft_ctab_display((*shell)->env);
		else if (strcmp(tab[0], "cd") == 0)
			ft_cd(&(*shell), tab);
		else
			ft_manage_call(&(*shell), tab);
	}
}

static char		*ft_check_line(char *line)
{
	unsigned int		i;

	i = 0;
	if (line)
	{
		while (line[i] && (line[i] == '\t' || line[i] == ' '))
			i++;
		if (i == ft_strlen(line))
			return (NULL);
		else
			return (ft_strsub(line, i, ft_strlen(line) - i));
	}
	return (line);
}

static void		ft_prompt(t_shell **shell)
{
	char	**tab;

	ft_putstr("$> ");
	if (get_next_line(0, &(*shell)->line) > 0)
	{
		tab = NULL;
		if (((*shell)->line = ft_check_line((*shell)->line)) != NULL)
			tab = ft_strsplit((*shell)->line, ' ');
		if (tab != NULL)
		{
			(*shell)->env[ft_ctab_len((*shell)->env) - 1] =
				ft_strdup(ft_strjoin("_=/bin/usr/", tab[0]));
			ft_parse(&(*shell), tab);
			ft_ctab_clear(tab);
		}
	}
	else
		ft_shell_clear(&(*shell));
}

int				main(void)
{
	extern char	**environ;
	t_shell		*shell;

	shell = NULL;
	signal(SIGINT, ft_sig_handler);
	ft_shell_init(&shell);
	ft_dup_env(&shell, environ);
	ft_mod_env(shell->env, "SHLVL", ft_itoa(shell->lvl));
	while ((shell)->done)
		ft_prompt(&shell);
	free(shell);
	shell = NULL;
	return (0);
}
