/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 12:42:36 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/21 14:39:29 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

void	ft_format_print(float *reduced, int i);
void	ft_print(int max1, int max2, float *reduced);
int		ft_nb_spaces(char *str);
char	*ft_no_space(char *str);
int		ft_get_max_power(char *str);
float	*ft_fill_left(char *str, int max);
float	*ft_fill_right(char *str, int max);
void	ft_imagin(float *reduced);
void	ft_deg2(float *reduced);
void	ft_deg1(float *reduced);
void	ft_deg0(float *reduced);
int		ft_resolve(char *tab1, char *tab2);
float	*ft_reduced(float *f1, float *f2, int max1, int max2);
float	*routine(char *left, char *right);
int		ft_aredigits(char *str);
int		ft_check(char **tab);
float	ft_abs(float nb);
float	ft_sqrt(float nb);

#endif
