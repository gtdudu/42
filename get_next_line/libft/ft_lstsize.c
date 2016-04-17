/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:56:13 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/09 19:08:42 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list **alst)
{
	int			i;
	t_list		*tmp;

	i = 0;
	if ((*alst) && alst)
	{
		tmp = (*alst);
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
