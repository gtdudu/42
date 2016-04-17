/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:07:36 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/06 11:07:38 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.class.hpp"

void 	comparison(Fixed & a, Fixed const & b ) {

		if (a < b)
			std::cout << "a < b" << std::endl;
		if ( a > b)
			std::cout << "a > b " << std::endl;
		if (a == b )
			std::cout << "a == b " << std::endl;
		if (a >= b)
			std::cout << "a >= b " << std::endl;
		if (a <= b)
			std::cout << "a <= b " << std::endl;

}

void 	arithmetic(Fixed const & a, Fixed const & b ) {

		std::cout << "a + b: " << a + b << std::endl;
		std::cout << "a - b: " << a - b << std::endl;
		std::cout << "a * b: " << a * b << std::endl;
		std::cout << "a / b: " << a / b << std::endl;
}

int 	main( void ) {

	Fixed a( -1.1f );
	Fixed c( 2.9f );
	Fixed const b( 1.5f );
	Fixed const d( 4.2f );


	std::cout << "a: " << a << " b: " << b << std::endl;
	comparison(a, b);

 	a =  Fixed ( 10 );
	std::cout << "a: " << a << " b: " << b << std::endl;
 	comparison(a, b);


	a =  Fixed ( 15 );
	std::cout << "a: " << a << " b: " << b << std::endl;
	comparison(a, b);

	std::cout << std::endl << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	arithmetic(a, b);

	std::cout << std::endl << std::endl;
	a =  Fixed ( 0 );
	std::cout << std::endl << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	a =  Fixed ( 0 );
	std::cout << std::endl << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << std::endl << std::endl;
	std::cout << "a: " << a << " c: " << c << std::endl;
	std::cout << "min: " << Fixed::min( a, c ) << std::endl;
	std::cout << "max: " << Fixed::max( a, c ) << std::endl;


	std::cout << std::endl << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "min: " << Fixed::min( a, b ) << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;


	Fixed e;
	Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << std::endl << std::endl;
	std::cout << e << std::endl;
	std::cout << ++e << std::endl;
	std::cout << e << std::endl;
	std::cout << e++ << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	e =  Fixed ( 13 );

	std::cout << Fixed::max( e, f ) << std::endl;

	return 0;
}
