/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:36:31 by tdurand           #+#    #+#             */
/*   Updated: 2015/03/03 19:00:08 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbase_lg(long n, int base)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > base - 1)
	{
		ft_putbase_lg(n / base, base);
		ft_putbase_lg(n % base, base);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n + 'a' - 10);
	}
}
