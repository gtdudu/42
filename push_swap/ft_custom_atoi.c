/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:25:55 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/22 18:31:11 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_check_wrong_char(const char *str)
{
	long	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n')
		i++;
	return (i);
}

long	ft_custom_atoi_end(long nb, int flag, long neg)
{
	if (neg)
		nb = -nb;
	if (flag == 0)
		return (nb);
	else
		return (3000000000);
}

long	ft_custom_atoi(const char *str)
{
	long		i;
	long		neg;
	long		nb;
	int			flag;

	flag = 0;
	nb = 0;
	neg = 0;
	i = ft_check_wrong_char(str);
	if (str[i] == '-' || str[i] == '+')
	{
		flag = 1;
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		flag = 0;
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	nb = ft_custom_atoi_end(nb, flag, neg);
	return (nb);
}
