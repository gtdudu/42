/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 12:43:37 by tdurand           #+#    #+#             */
/*   Updated: 2015/04/21 17:44:23 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void		ft_imagin(float *reduced)
{
	float	delta;
	float	res1;
	float	res2;
	float	alpha;

	ft_putendl("Discriminant strictly negative, there are no real solutions");
	ft_putendl("There are two complex solutions :");
	delta = (reduced[1] * reduced[1]) - (4 * reduced[2] * reduced[0]);
	alpha = (-1 * reduced[1]) / (2 * reduced[2]);
	res1 = (ft_sqrt(-delta) / (2 * reduced[2]));
	res2 = (ft_sqrt(-delta) / (2 * reduced[2]));
	printf("%g + %g * i\n", alpha, res1);
	printf("%g - %g * i\n", alpha, res2);
}

void		ft_deg2(float *reduced)
{
	float	delta;
	float	res1;
	float	res2;
	float	beta;
	float	alpha;

	delta = (reduced[1] * reduced[1]) - (4 * reduced[2] * reduced[0]);
	if (delta < 0)
		ft_imagin(reduced);
	else if (delta == 0)
	{
		ft_putendl("Discriminant is equal to zero, the solution is: ");
		res1 = (-1 * reduced[1]) / (2 * reduced[2]);
		printf("%f", res1);
	}
	else
	{
		ft_putendl("Discriminant is stricly positive, the two solutions are: ");
		alpha = (-1 * reduced[1]) / (2 * reduced[2]);
		beta = ft_sqrt(delta);
		res1 = alpha + (beta / (2 * reduced[2]));
		res2 = alpha - (beta / (2 * reduced[2]));
		printf("%f\n", res2);
		printf("%f\n", res1);
	}
}

void		ft_deg1(float *reduced)
{
	float	res;

	if (reduced[1] != 0)
	{
		res = (-1 * reduced[0]) / reduced[1];
		printf("The solution is:");
		printf("\n%g\n", res);
	}
	else
		ft_putendl("This is insoluble");
}

void		ft_deg0(float *reduced)
{
	if (reduced[0] == 0)
		ft_putendl("All real numbers are a potential solution");
	else
		ft_putendl("X^0 = 1 This is insoluble");
}

int			ft_resolve(char *tab1, char *tab2)
{
	int		degree;
	float	*reduced;

	reduced = routine(tab1, tab2);
	if (ft_get_max_power(tab1) >= ft_get_max_power(tab2))
		degree = ft_get_max_power(tab1);
	else
		degree = ft_get_max_power(tab2);
	if (reduced[2] == 0 && degree <= 2)
		degree = 1;
	if (degree == 2)
		ft_deg2(reduced);
	if (degree == 1)
		ft_deg1(reduced);
	if (degree == 0)
		ft_deg0(reduced);
	return (1);
}
