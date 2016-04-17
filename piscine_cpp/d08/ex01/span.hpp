/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 11:27:30 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/14 11:27:31 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <list>

class Span {

public:

  Span( unsigned int n );
  ~Span( void );

// GETTER
  unsigned int    getN( void ) const;
  unsigned int    getFilled( void ) const;
  std::list<int>  getL( void ) const;

// MEMBER FUNCTIONS
void            addNumber( int n );
void            addNumber( int n, int min, int max );
unsigned int    shortestSpan( void ) const;
unsigned int    longestSpan( void ) const;

private:

  Span( void );
  Span ( Span const & src);
  Span & operator=(Span const & rhs);
  unsigned int        _n;
  unsigned int        _filled;
  std::list<int>      _l;

};

#endif
