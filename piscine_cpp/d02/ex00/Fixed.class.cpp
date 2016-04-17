/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:24:00 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/06 10:24:01 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.class.hpp"

Fixed::Fixed( void ) : _fpv( 0 ) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::~Fixed( void ) {
  std::cout << "Destructor called" << std::endl;
  return;
}


Fixed::Fixed( Fixed const & src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

Fixed &   Fixed::operator=( Fixed const & rhs ) {
  std::cout << "Assignation operator called" << std::endl;

  if (this != &rhs)
    this->_fpv = rhs.getRawBits();

  return *this;
}


int   Fixed::getRawBits( void ) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_fpv;
};

void   Fixed::setRawBits( int const raw ) {
  this->_fpv = raw;
  std::cout << "Destructor called" << std::endl;


};

int const    Fixed::_nbFracBits = 8;
