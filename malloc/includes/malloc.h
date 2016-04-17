/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:32:08 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 14:23:50 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>
# include "libft.h"
# include <sys/mman.h>
# include <sys/types.h>
# define TINY_BLOCKS 16
# define TINY_LIGN 4096
# define TINY_LIMIT 512
# define SMALL_BLOCKS 512
# define SMALL_LIGN 800
# define SMALL_LIMIT 4096

typedef struct	s_tiny
{
	long			tab[TINY_LIGN][2];
	size_t			total_size;
	struct s_tiny	*next;
	void			*ptr;

}				t_tiny;

typedef struct	s_small
{
	long			tab[SMALL_LIGN][2];
	size_t			total_size;
	struct s_small	*next;
	void			*ptr;

}				t_small;

typedef struct	s_large
{
	size_t			size;
	int				status;
	struct s_large	*next;
	void			*ptr;

}				t_large;

typedef struct	s_env
{
	t_tiny			*head_tiny;
	t_small			*head_small;
	t_large			*head_large;
	size_t			total_size;
}				t_env;

t_env	g_env;

void			*ft_realloc(void *ptr, size_t size);
void			*ft_malloc(size_t size);
void			show_alloc_mem();
void			ft_free(void *ptr);
void			*ft_malloc_tiny(size_t size);
void			ft_print_tab_tiny();
t_tiny			*ft_create_tiny_zone(void);
void			*ft_add_tiny_zone(size_t size);
t_tiny			*ft_delete_zone_tiny(t_tiny *tiny);
t_tiny			*ft_check_if_tiny(void *ptr);
void			*ft_look_for_free_space_tiny(long tab[4096][2], size_t size);
long			ft_does_it_fit_tiny(long tab[4096][2], long start, size_t size);
void			ft_update_tab_tiny(long tab[4096][2], long start, size_t size);
long			ft_check_for_wrong_ptr_tiny(void *ptr, t_tiny *tiny);
long			ft_remove_from_tab_tiny(void *ptr, t_tiny *tiny);
void			*ft_malloc_small(size_t size);
void			ft_print_tab_small();
t_small			*ft_create_small_zone();
void			*ft_add_small_zone(size_t size);
t_small			*ft_delete_zone_small(t_small *small);
t_small			*ft_check_if_small(void *ptr);
void			*ft_look_for_free_space_small(long tab[4096][2], size_t size);
long			ft_does_it_fit_small(long tab[4096][2],
		long start, size_t size);
void			ft_update_tab_small(long tab[4096][2], long start, size_t size);
long			ft_check_for_wrong_ptr_small(void *ptr, t_small *small);
long			ft_remove_from_tab_small(void *ptr, t_small *small);
t_large			*ft_create_large_zone(size_t size);
t_large			*ft_delete_zone_large(t_large *large);
void			*ft_add_large_zone(size_t size);
t_large			*ft_check_if_large(void *ptr);
void			*ft_mod_large(size_t size);
void			ft_print_tab_large();
#endif
