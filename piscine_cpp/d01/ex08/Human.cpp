/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 16:51:03 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/06 16:51:04 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>

Human::Human( void ) {
  std::cout << "constructor called" << std::endl;;
  this->_store[0] = &Human::meleeAttack;
  this->_store[1] = &Human::rangedAttack;
  this->_store[2] = &Human::intimidatingShout;
  return;
};

Human::~Human( void ){
  std::cout << "destructor called" << std::endl;;
  return;
}

void Human::action(std::string const & action_name, std::string const & target) {
  for (size_t i = 0; i < 3; i++) {
    if (action_name == Human::_names[i] )
      (this->*_store[i])(target);
  }
  return;
};

void Human::meleeAttack(std::string const & target){

  std::cout << "melee attack on " << target << std::endl;
  return;
};

void Human::rangedAttack(std::string const & target) {
  std::cout << "ranged attack on " << target << std::endl;;
  return;
};

void Human::intimidatingShout(std::string const & target) {

  std::cout << "intimidating shout on " << target << std::endl;;
  return;
};

const std::string  Human::_names[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
