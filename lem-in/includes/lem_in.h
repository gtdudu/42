/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 16:25:50 by tdurand           #+#    #+#             */
/*   Updated: 2015/06/08 07:14:33 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct	s_room
{
	int				id;
	char			*name;
	int				id_ant;
	struct s_room	*next;
	struct s_room	*prev;
}				t_room;

typedef struct	s_path
{
	int				status;
	int				id;
	int				len;
	int				current_id;
	struct s_path	*next;
	struct s_room	*start;
}				t_path;

typedef struct	s_ant
{
	int		on;
	int		gtg;
	int		total_ants;
	int		arrived;
	int		nb_room;
	char	*start;
	char	*end;
	t_room	*rooms;
	t_path	*paths;
	t_path	*solution;
	char	**matrix;
}				t_ant;

void			ft_clear_paths(t_path *path);
void			ft_clear_rooms(t_room *room);
void			ft_del_from_matrix(t_ant *ant);
void			ft_del_from_matrix_2(t_ant *ant, t_room *rtmp);
void			ft_clear_all(t_ant *ant);

t_path			*ft_cpy_path(t_path *path);
t_room			*ft_cpy_room(t_room *room);
t_room			*ft_cpy_rooms(t_room *room);

t_ant			*ft_add_paths(t_ant *ant, t_path *curr, int	i);
t_path			*ft_get_curr(t_ant *ant, int *dist);
t_ant			*ft_process_paths(t_ant *ant);

t_room			*ft_get_start(t_ant *ant);
t_room			*ft_get_room_from_id(t_room *room, int id);
int				ft_room_len(t_room *room);
int				ft_get_id(t_room *room, char *name);
t_ant			*ft_double_linked_list(t_ant *ant);

t_ant			*ft_init_ant(void);
t_path			*ft_init_paths(t_ant *ant);
int				*ft_init_dist(int len);
char			**ft_init_matrix(int l);
t_room			*ft_init_room(int id, char **tab);

void			ft_print_room(t_room *room);
void			ft_debug(t_path *paths);
int				ft_check_opt(char *str);
void			ft_print_opt(t_ant *ant, int opt);

t_ant			*ft_get_tubes(t_ant *ant, char **tab);
t_ant			*ft_manage_intel(int *tag, t_ant *ant, char **tab);
t_ant			*ft_manage_cmd(t_ant *ant, char *line, char **tab);
t_ant			*ft_read_input(t_ant *ant);
void			ft_str_digit(t_ant *ant, char *str);

t_ant			*ft_switch_id(t_ant *ant, int new_id, int old_id);
t_ant			*ft_correct_id(t_ant *ant);
t_ant			*ft_first_line(t_ant *ant, char *line);

#endif
