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
#include <cmath>  // roundf
#include "Fixed.class.hpp"

//ex00 constructor
Fixed::Fixed( void ) : _fpv( 0 ) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::Fixed( Fixed const & src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

//ex01 constructor
Fixed::Fixed( const int i) : _fpv( i << Fixed::_nbFracBits ){
  std::cout << "Int constructor called" << std::endl;
  return;
};

Fixed::Fixed( const float f) {
  std::cout << "Float constructor called" << std::endl;
  float tmp;
  tmp =  f * ( 1 << Fixed::_nbFracBits );
  tmp = roundf(tmp);
  this->_fpv = tmp;
  return;
}

//Destructor
Fixed::~Fixed( void ) {
  std::cout << "Destructor called" << std::endl;
  return;
}

//ex00 overload
Fixed &   Fixed::operator=( Fixed const & rhs ) {
  std::cout << "Assignation operator called" << std::endl;

  if (this != &rhs)
    this->_fpv = rhs.getRawBits();

  return *this;
}

//ex00 member functions
int   Fixed::getRawBits( void ) const {
  return this->_fpv;
};

void   Fixed::setRawBits( int const raw ) {
  this->_fpv = raw;
  return;
};

//ex01 member functions
float    Fixed::toFloat( void ) const {

  return static_cast<float>(this->_fpv) / ( 1 << Fixed::_nbFracBits );
};

int      Fixed::toInt( void ) const {

  return this->_fpv >> Fixed::_nbFracBits;
}


//ex01 overload
std::ostream &    operator<<(std::ostream & o, Fixed const & rhs) {
  o << rhs.toFloat();
  return o;
}


int const    Fixed::_nbFracBits = 8;
