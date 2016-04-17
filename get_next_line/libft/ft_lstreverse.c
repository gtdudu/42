/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:28:39 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/09 19:07:57 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **alst)
{
	t_list	*prev;
	t_list	*src;
	t_list	*nxt;

	if ((*alst) && alst)
	{
		prev = (*alst);
		src = prev->next;
		nxt = src->next;
		prev->next = NULL;
		while (src->next)
		{
			src->next = prev;
			prev = src;
			src = nxt;
			nxt = nxt->next;
		}
		src->next = prev;
		(*alst) = src;
	}
}
