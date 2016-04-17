/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:48:41 by tdurand           #+#    #+#             */
/*   Updated: 2014/12/30 17:55:24 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **alst, void *content, size_t content_size)
{
	t_list		*lst;
	t_list		*begin;

	if (alst && (*alst))
	{
		lst = ft_lstnew(content, content_size);
		begin = (*alst);
		if (begin == NULL)
			(*alst) = lst;
		else
		{
			while (begin->next)
				begin = begin->next;
			begin->next = lst;
		}
	}
}
