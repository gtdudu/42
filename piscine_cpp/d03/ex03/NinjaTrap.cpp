/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:45:16 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 17:45:17 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

// CONSTRUCTORS
NinjaTrap::NinjaTrap( void ) : ClapTrap(60, 60, 120, 120, 1, "Oscavy", 60, 5, 0) {
  srand (time(NULL));
  std::cout << "An awesome NinjaTrap was born." << std::endl;
  return;
}

NinjaTrap::NinjaTrap( std::string name ) : ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0) {
  srand (time(NULL));
  std::cout << "Kick ass NinjaTrap named " << this->_name << " is borned." << std::endl;
  return;
}

NinjaTrap::NinjaTrap( NinjaTrap const & src) {
  *this = src;
  std::cout << this->_name << " the NinjaTrap has been created by copy." << std::endl;
  return;
}

NinjaTrap & NinjaTrap::operator=( NinjaTrap const & rhs ) {
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
NinjaTrap::~NinjaTrap() {
  std::cout << "Freaky NinjaTrap "<< this->_name <<" is no longer living." << std::endl;
  return;
}

//PUBLIC MEMBER FUNCTIONS

void    NinjaTrap::ninjaShoebox(ScavTrap & target) {
  std::cout << "NinjaTrap "<< this->_name <<" is using ninjaShoebox on ScavTrap to increase his armor !" << std::endl;
  this->_armorDamageReduction += target.getArmorDamageReduction();
  std::cout << "NinjaTrap increased his armor by" <<  target.getArmorDamageReduction() << " points !" << std::endl;
  return;
};

void    NinjaTrap::ninjaShoebox(FragTrap & target) {
  std::cout << "NinjaTrap "<< this->_name <<" is using ninjaShoebox on FragTrap to increase his armor !" << std::endl;
  this->_armorDamageReduction += target.getArmorDamageReduction();
  std::cout << "NinjaTrap increased his armor by" <<  target.getArmorDamageReduction() << " points !" << std::endl;
  return;
};

void    NinjaTrap::ninjaShoebox(NinjaTrap & target) {
  std::cout << "NinjaTrap "<< this->_name <<" is using ninjaShoebox on NinjaTrap to increase his armor !" << std::endl;
  this->_armorDamageReduction += target.getArmorDamageReduction();
  std::cout << "NinjaTrap increased his armor by" <<  target.getArmorDamageReduction() << " points !" << std::endl;
  return;
};
