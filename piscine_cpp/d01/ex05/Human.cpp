/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:52:01 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 13:52:02 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

Human::Human( void ) {


  std::cout << "Generating a new Human." << std::endl;
  return;
}


Human::~Human( void ) {

  std::cout << "Destroying Human." << std::endl;
  return;
}

std::string   Human::identify( void ) const {

  return this->_brain.identify();
}

Brain const &  Human::getBrain( void ) const {

  return this->_brain;
};
