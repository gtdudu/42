/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 07:00:02 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/22 18:10:40 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct	s_pile
{
	int					nb;
	struct s_pile		*next;
	struct s_pile		*prev;
}				t_pile;

typedef struct	s_piles
{
	struct s_pile		*a;
	struct s_pile		*b;
}				t_piles;

long			ft_custom_atoi(const char *str);
int				ft_solve(t_piles *piles);
int				ft_pile_is_sorted(t_piles *piles);
int				ft_pilea_is_sorted(t_piles *piles);
int				ft_pile_display(t_pile *pile);
int				ft_pile_size(t_pile *pile);
int				ft_ten(int *path, int len);
int				ft_apply_functions(t_piles *piles, int *path, int size);
int				ft_get_side(t_piles *piles);
void			ft_forest(t_piles *piles);
void			ft_display_path(int *path, int len);
void			ft_display_path_sub(int *path, int i);
void			ft_free(t_pile *pile);
void			ft_set_to_zero(int *path, int len, int start);
void			ft_swap(t_pile **pile);
void			ft_push(t_pile **pilea, t_pile **pileb);
void			ft_pushb(t_pile **pilea, t_pile **pileb);
void			ft_rotate(t_pile **pile);
void			ft_rotate_rev(t_pile **pile);
void			ft_pile_display_all(t_piles *piles);
void			ft_sa(t_piles *piles);
void			ft_sb(t_piles *piles);
void			ft_ss(t_piles *piles);
void			ft_pa(t_piles *piles);
void			ft_pb(t_piles *piles);
void			ft_ra(t_piles *piles);
void			ft_rb(t_piles *piles);
void			ft_rr(t_piles *piles);
void			ft_rra(t_piles *piles);
void			ft_rrb(t_piles *piles);
void			ft_rrr(t_piles *piles);
t_pile			*ft_pile_cpy(t_pile *a);
t_pile			*ft_pop_first(t_pile **pile);
t_pile			*ft_pile_push(t_pile **alst, int nb);
t_pile			*ft_pile_add(t_pile **alst, int nb);
t_pile			*ft_pile_new(int nb);

#endif
