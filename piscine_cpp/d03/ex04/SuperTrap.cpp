/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:22:26 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 18:22:27 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

// CONSTRUCTORS
SuperTrap::SuperTrap( void ) : ClapTrap(100, 100, 120, 120, 1, "Suupry", 60, 20, 5) {
  srand (time(NULL));
  std::cout << "An awesome SuperTrap was born." << std::endl;
  return;
}

SuperTrap::SuperTrap( std::string name ) : ClapTrap(100, 100, 120, 120, 1, name, 60, 20, 5) {
  srand (time(NULL));
  std::cout << "Kick ass SuperTrap named " << this->_name << " is borned." << std::endl;
  return;
}

SuperTrap::SuperTrap( SuperTrap const & src) {
  *this = src;
  std::cout << this->_name << " the SuperTrap has been created by copy." << std::endl;
  return;
}

SuperTrap & SuperTrap::operator=( SuperTrap const & rhs ) {
  std::cout << "Assignation operator called" << std::endl;
  if (this != &rhs) {
    this->_hitPoints = rhs.getHitpoints();
    this->_maxHitPoints = rhs.getMaxHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_level = rhs.getLevel();
    this->_name = rhs.getName();
    this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->_rangedAttackDamage = rhs.getRangedAttackDamage();
    this->_armorDamageReduction = rhs.getArmorDamageReduction();
  }
  return *this;
}


// DESTRUCTORS
SuperTrap::~SuperTrap() {
  std::cout << "Poor SuperTrap "<< this->_name <<" is no longer living." << std::endl;
  return;
}
