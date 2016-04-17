/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 13:40:22 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/21 17:42:18 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

float	ft_abs(float nb)
{
	if (nb == 0)
		return (0);
	else if (nb < 0)
		return (-nb);
	else
		return (nb);
}

float	ft_sqrt(float nb)
{
	float	high;
	float	low;
	float	mid;
	float	oldmid;
	float	midsqr;

	if (nb < 0)
		return (-1);
	if (nb == 0)
		return (0);
	low = 0;
	high = nb;
	mid = nb;
	oldmid = 1;
	while (ft_abs(oldmid - mid) >= 0.000000001)
	{
		oldmid = mid;
		mid = (high + low) / 2;
		midsqr = mid * mid;
		if (midsqr > nb)
			high = mid;
		else
			low = mid;
	}
	return (mid);
}
