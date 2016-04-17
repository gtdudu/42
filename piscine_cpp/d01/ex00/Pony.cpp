/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 09:51:43 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 09:52:09 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

Pony::Pony( std::string n, std::string c ) : _name( n ), _color( c ) {
  std::cout << this->_name << " the pony, came to life" << std::endl;
  return;
}


Pony::~Pony( void ) {
  std::cout << this->_name << " Pony died painfully" << std::endl;
  return;
}

void   Pony::getColor( void ) const {
  std::cout << this->_name << " is of a beautifull " << this->_color << std::endl;
}
