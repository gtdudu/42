/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:11:56 by tdurand           #+#    #+#             */
/*   Updated: 2014/11/06 18:57:58 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_wrd(char const *s, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			n++;
		while (s[i] != c)
			i++;
		i++;
	}
	return (n);
}

static char		**ft_getsubs(char const *s, char c, char **tab, int nb_wrd)
{
	int		i;
	int		tmp;
	int		l_wrd;
	int		p;

	i = 0;
	p = 0;
	while (p < nb_wrd)
	{
		while (s[i] == c)
			i++;
		tmp = i;
		l_wrd = 0;
		while (s[i] != c)
		{
			i++;
			l_wrd++;
		}
		tab[p] = ft_strsub(s, tmp, l_wrd);
		p++;
	}
	tab[p] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_wrd;

	if (s && c)
	{
		nb_wrd = count_wrd(s, c);
		tab = (char **)malloc(sizeof(tab) * nb_wrd + 1);
		if (tab)
			return (ft_getsubs(s, c, tab, nb_wrd));
	}
	return (NULL);
}
