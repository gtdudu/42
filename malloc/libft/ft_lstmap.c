/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 01:03:10 by tdurand           #+#    #+#             */
/*   Updated: 2014/12/30 17:54:11 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*new;
	t_list		*begin;

	if (lst && f)
	{
		tmp = (*f)(lst);
		if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		begin = new;
		while (lst->next)
		{
			tmp = (*f)(lst->next);
			if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			lst = lst->next;
			new = new->next;
		}
		return (begin);
	}
	return (NULL);
}
