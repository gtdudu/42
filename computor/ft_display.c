/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 12:20:02 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/21 17:47:09 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_format_print(float *reduced, int i)
{
	if (i == 0)
	{
		if (reduced[i] < 0)
			printf("-%g * X^%d", (-1 * reduced[i]), i);
		else
			printf("%g * X^%d", reduced[i], i);
	}
	else
	{
		if (reduced[i] < 0)
			printf(" - %g * X^%d", (-1 * reduced[i]), i);
		else
			printf(" + %g * X^%d", reduced[i], i);
	}
}

void	ft_print(int max1, int max2, float *reduced)
{
	int		i;
	int		max;

	i = -1;
	if (max1 >= max2)
		max = max1;
	else
		max = max2;
	printf("Reduced form: ");
	while (++i <= max)
		ft_format_print(reduced, i);
	printf(" = 0\nPolynomial degree: %d\n", max);
	if (max > 2)
	{
		ft_putstr("Polynomial degree is strictly superior than 2");
		ft_putendl(" : I can't solve this.");
	}
}
