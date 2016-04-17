/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:37:37 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/09 19:06:36 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, void *content, size_t content_size)
{
	t_list		*lst;

	if ((*alst) && alst)
	{
		lst = ft_lstnew(content, content_size);
		lst->next = (*alst);
		(*alst) = lst;
	}
}
