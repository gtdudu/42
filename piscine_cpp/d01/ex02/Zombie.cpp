/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:01:35 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 11:01:36 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string t, std::string n ) : _type( t ), _name( n ) {

  std::cout << "<" << this->_name << " " << this->_type << "> Was created.... watch out!" << std::endl;
  return;
}

Zombie::~Zombie( void ) {

  std::cout << "<" << this->_name << " " << this->_type << "> Was killed, good job." << std::endl;
  return;
}

void  Zombie::annouce( void ) const {

  std::cout << "<" << this->_name << " " << this->_type << "> Braiiiiinnnnnns...." << std::endl;
  return;
}
