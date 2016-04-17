/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:22:10 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/25 15:37:39 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	show_alloc_mem(void)
{
	ft_putendl("\n");
	if (g_env.head_tiny)
	{
		ft_putstr("TINY : ");
		ft_putbase_lg(g_env.head_tiny->tab[0][0], 16);
		ft_print_tab_tiny();
	}
	if (g_env.head_small)
	{
		ft_putstr("SMALL : ");
		ft_putbase_lg((long)g_env.head_small->ptr, 16);
		ft_print_tab_small();
	}
	if (g_env.head_large != NULL)
	{
		ft_putstr("LARGE : ");
		ft_putbase_lg((long)g_env.head_large->ptr, 16);
		ft_print_tab_large();
	}
	ft_putstr("Total : ");
	ft_putbase_lg((long)g_env.total_size, 10);
}

void	ft_print_tab_tiny(void)
{
	int		i;
	t_tiny	*tmp;

	tmp = g_env.head_tiny;
	ft_putendl("");
	while (tmp != NULL)
	{
		i = 0;
		while (i < TINY_LIGN)
		{
			if (tmp->tab[i][1] != 0 && tmp->tab[i][1] != -1)
			{
				ft_putbase_lg(tmp->tab[i][0], 16);
				ft_putstr(" - ");
				ft_putbase_lg(tmp->tab[i][0] + (tmp->tab[i][1] - 1), 16);
				ft_putstr(" : ");
				ft_putbase_lg(tmp->tab[i][1], 10);
				ft_putendl(" octets");
			}
			i++;
		}
		ft_putendl("");
		tmp = tmp->next;
	}
}

void	ft_print_tab_small(void)
{
	int		i;
	t_small	*tmp;

	tmp = g_env.head_small;
	ft_putendl("");
	while (tmp != NULL)
	{
		i = 0;
		while (i < SMALL_LIGN)
		{
			if (tmp->tab[i][1] != 0 && tmp->tab[i][1] != -1)
			{
				ft_putbase_lg(tmp->tab[i][0], 16);
				ft_putstr(" - ");
				ft_putbase_lg(tmp->tab[i][0] + (tmp->tab[i][1] - 1), 16);
				ft_putstr(" : ");
				ft_putbase_lg(tmp->tab[i][1], 10);
				ft_putendl(" octets");
			}
			i++;
		}
		ft_putendl("");
		tmp = tmp->next;
	}
}

void	ft_print_tab_large(void)
{
	t_large	*tmp;

	tmp = g_env.head_large;
	ft_putendl("");
	while (tmp != NULL)
	{
		ft_putbase_lg((long)tmp->ptr, 16);
		ft_putstr(" - ");
		ft_putbase_lg((long)tmp->ptr + ((long)tmp->size - 1), 16);
		ft_putstr(" : ");
		ft_putbase_lg((long)tmp->size, 10);
		ft_putendl(" octets");
		tmp = tmp->next;
	}
}
