/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:51:42 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 13:51:43 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain( void ) : _size( "small" ) {

  std::cout << "Generating small Brain." << std::endl;
  return;
}


Brain::~Brain( void ) {

  std::cout << "Destroying brain." << std::endl;
  return;
}

std::string  Brain::identify( void ) const {

  std::stringstream   ss;

  ss << this;
  return ss.str();
}
