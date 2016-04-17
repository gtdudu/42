/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:58:57 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/04 12:59:09 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main( int ac, char **av ) {

	int		i;
	int		j;
	char	c;

	if ( ac > 1 ){
		i = 1;
		while ( i < ac ) {
			j = 0;
			while ( av[i][j] ) {
				c = av[i][j];
				std::cout << (char)toupper(c);  
				j++;
			}	
			i++;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "* LOUD AND UNBEARABLE FEEBACK NOISE *" << std::endl;
	}
	return 0;

}
