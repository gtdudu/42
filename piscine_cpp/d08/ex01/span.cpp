/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 11:27:26 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/14 11:27:27 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <exception>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <list>

Span::Span( void ) : _n( 0 ), _filled( 0 ) {
  srand (time(NULL));
  return;
};

Span::Span( unsigned int n ) : _n( n ), _filled( 0 ) {
  srand (time(NULL));
  return;
};

Span::Span ( Span const & src) {
  *this = src;
  return;
};

Span & Span::operator=(Span const & rhs) {
  if ( this != &rhs) {
    this->_n = rhs.getN();
    this->_filled = rhs.getFilled();
    this->_l = rhs.getL();
  }
  return *this;
};

Span::~Span( void ) {
  return;
};

unsigned int    Span::getN( void ) const {
  return this->_n;
}

unsigned int    Span::getFilled( void ) const {
  return this->_filled;
}

std::list<int>    Span::getL( void ) const {
  return this->_l;
}

void            Span::addNumber( int n ) {
  if (this->_filled + 1 <= this->_n) {
    this->_l.push_back(n);
    this->_filled += 1;
    this->_l.sort();
  }
  else
    throw std::exception();
};

void            Span::addNumber( int n, int min, int max) {
  if (this->_filled + n <= this->_n) {
    for (int i = 0; i < n; i++) {
      this->_l.push_back(min + (rand() % (int)(max - min + 1)));
    }
    this->_filled += n;
    this->_l.sort();
  } else
      throw std::exception();
};

unsigned int    Span::shortestSpan() const {

  if ( this->_filled == 0 || this->_filled == 1 )
    throw std::exception();
  unsigned int result[this->_filled + 1];
  std::adjacent_difference ( this->_l.begin(), this->_l.end(), result);
  std::sort(result + 1, result + this->_filled);

  return result[1];
};

unsigned int    Span::longestSpan() const {

  if ( this->_filled == 0 || this->_filled == 1 )
    throw std::exception();
  return this->_l.back() - this->_l.front();
};
