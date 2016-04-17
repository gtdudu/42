/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:11:56 by tdurand           #+#    #+#             */
/*   Updated: 2014/12/30 18:54:41 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_wrd(char const *s, char c)
{
	int		i;
	int		cpt;
	char	*stmp;
	int		p;

	stmp = (char *)s;
	i = 0;
	cpt = 0;
	p = 0;
	while (stmp[i])
	{
		while (stmp[i] == c && stmp[i])
			i++;
		while (stmp[i] && stmp[i] != c)
		{
			i++;
			p = 1;
		}
		if (p == 1)
			cpt++;
		p = 0;
	}
	return (cpt);
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
		while (s[i] && s[i] == c)
			i++;
		tmp = i;
		l_wrd = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			l_wrd++;
		}
		tab[p] = ft_strsub(s, tmp, l_wrd);
		p++;
	}
	tab[p] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_wrd;

	if (s && c)
	{
		nb_wrd = count_wrd(s, c);
		tab = (char **)malloc(sizeof(char*) * nb_wrd + 1);
		if (tab)
			return (ft_getsubs(s, c, tab, nb_wrd));
	}
	return (NULL);
}
