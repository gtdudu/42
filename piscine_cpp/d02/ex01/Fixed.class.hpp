/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:24:07 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/06 10:24:09 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include "Fixed.class.hpp"

class Fixed {

public:

  Fixed( void );
  Fixed( Fixed const & src);
  Fixed( const int i);
  Fixed( const float f);
  ~Fixed (void);

  Fixed & operator=( Fixed const & rhs );

  int      getRawBits( void ) const;
  void     setRawBits( int const raw );
  float    toFloat( void ) const;
  int      toInt( void ) const;

private:

    int                 _fpv;
    static int const    _nbFracBits;


};

std::ostream &    operator<<( std::ostream & o, Fixed const & rhs);


#endif
