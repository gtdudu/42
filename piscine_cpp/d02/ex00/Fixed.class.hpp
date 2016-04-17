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

class Fixed {

public:

  Fixed( void );
  Fixed( Fixed const & src);
  ~Fixed (void);

  Fixed & operator=( Fixed const & rhs );

  int   getRawBits( void ) const;
  void   setRawBits( int const raw );

private:

    int                 _fpv;
    static int const    _nbFracBits;


};


#endif
