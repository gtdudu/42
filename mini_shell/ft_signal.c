/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 01:04:34 by tdurand           #+#    #+#             */
/*   Updated: 2015/02/19 15:44:46 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

void			ft_sig_handler_2(int sig)
{
	(void)sig;
	ft_putendl("");
}

void			ft_sig_handler(int sig)
{
	ft_putendl("");
	ft_putstr("$> ");
	(void)sig;
}
