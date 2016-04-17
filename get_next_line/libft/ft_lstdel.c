/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:10:44 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/09 19:04:41 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst) && alst && del)
	{
		ft_lstdel(&(*alst)->next, del);
		(*del)((*alst)->content, (*alst)->content_size);
		free((*alst));
		(*alst) = NULL;
	}
}
