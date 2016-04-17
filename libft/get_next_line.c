/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:32:29 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/24 01:42:24 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_realloc_s(char *s, int n)
{
	char		*result;
	int			i;

	if (!(result = malloc(sizeof(result) * (ft_strlen(s) - n + 1))))
		return (NULL);
	i = 0;
	while (s[i + n])
	{
		result[i] = s[i + n];
		i++;
	}
	result[i] = '\0';
	free(s);
	s = NULL;
	return (result);
}

static t_get	*ft_new(t_get **alst, int fd)
{
	t_get		*list;

	if (!(*alst))
	{
		if (!(list = (t_get *)malloc(sizeof(t_get))))
			return (NULL);
		list->s = NULL;
		list->f = fd;
		list->next = NULL;
	}
	else if ((*alst) && alst)
	{
		if (!(list = (t_get *)malloc(sizeof(t_get))))
			return (NULL);
		list->s = NULL;
		list->f = fd;
		list->next = (*alst);
		(*alst) = list;
	}
	return (list);
}

static int		get_line(t_get *tmp, char **line)
{
	int					ret;
	int					i;
	char				buf[BUF_SIZE + 1];

	while (ft_check_char(tmp->s, '\n') == 0
			&& (ret = read(tmp->f, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp->s = (tmp->s) ? ft_strjoin(tmp->s, buf) : ft_strdup(buf);
	}
	if (ret == -1)
		return (-1);
	if (tmp->s != NULL)
	{
		i = 0;
		while (tmp->s[i] && tmp->s[i] != '\n')
			i++;
		*line = ft_strsub(tmp->s, 0, i);
		if (ret == 0 && ft_strlen(*line) == ft_strlen(tmp->s))
			ft_memdel((void **)&(tmp->s));
		else
			tmp->s = ft_realloc_s(tmp->s, i + 1);
		return (1);
	}
	return (0);
}

static int		ft_free(t_get **lst, t_get *tmp)
{
	t_get	*crs;

	crs = (*lst);
	if (crs == tmp)
	{
		(*lst) = (*lst)->next;
		ft_memdel((void **)&tmp);
		return (1);
	}
	while (crs)
	{
		if (crs->next == tmp)
		{
			crs->next = crs->next->next;
			ft_memdel((void **)&tmp);
			return (1);
		}
		else
			crs = crs->next;
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_get			*lst;
	t_get					*tmp;

	if (!line)
		return (-1);
	if (!lst)
		if (!(lst = ft_new(&lst, fd)))
			return (-1);
	tmp = lst;
	while ((tmp && tmp->f != fd))
		tmp = tmp->next;
	if (tmp == NULL)
		if (!(tmp = ft_new(&lst, fd)))
			return (-1);
	if (get_line(tmp, line) == 1)
	{
		if (tmp->s == NULL && *line[0] == '\0')
			if (ft_free(&lst, tmp))
				return (0);
		return (1);
	}
	else if (get_line(tmp, line) == -1)
		return (-1);
	return (0);
}
