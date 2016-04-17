/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:06:30 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/19 15:56:29 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H
# include "libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_shell
{
	int		done;
	int		lvl;
	char	**env;
	char	*line;
	char	*pwd;
	char	*oldpwd;
	char	*home;
	char	*path;
	char	*err;
}				t_shell;

void			ft_convert_tild(char **tab, t_shell **shell);
void			ft_sig_handler(int sig);
void			ft_sig_handler_2(int sig);
int				ft_get_i(char **tab, char *index);
void			ft_shell_init(t_shell **shell);
void			ft_shell_clear(t_shell **shell);
void			ft_cd(t_shell **env, char **tab);
int				ft_path_call(t_shell **shell, char **tab);
void			ft_dup_env(t_shell **shell, char **environ);
void			ft_ctab_pop(t_shell **shell, char *str);
char			*ft_getstr_env(char **tab, char *index);
char			**ft_mod_env(char **tab, char *index, char *str);
void			ft_ctab_push(t_shell **shell, char *index, char *str);
void			ft_setenv(t_shell **shell, char *index, char*str);
void			ft_save(t_shell **shell, char *str);
int				ft_perm_r(char *tab);
int				ft_home(t_shell **shell);
int				ft_from_home(t_shell **shell, char *str);
int				ft_minus(t_shell **shell);
void			ft_errors(t_shell **shell, int err, char *str);

#endif
