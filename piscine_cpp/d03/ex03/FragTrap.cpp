/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:03:02 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 10:03:03 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>


//RANDOM ATTACK STRUCT
struct r_attack
{
	std::string		name;
	unsigned int  dmg;
};

// CONSTRUCTORS
FragTrap::FragTrap( void ) : ClapTrap(100, 100, 100, 100, 1, "Fragolin", 30, 20, 5) {
  srand (time(NULL));
  std::cout << "Default fragtrap was created." << std::endl;
  return;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(100, 100, 50, 50, 1, name, 30, 20, 5) {
  srand (time(NULL));
  std::cout << "fragtrap " << this->_name << " was created." << std::endl;
  return;
}

FragTrap::FragTrap( FragTrap const & src) {
  *this = src;
  std::cout << "Copy fragtrap " << this->_name << " was created." << std::endl;
  return;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
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
FragTrap::~FragTrap() {
  std::cout << "Fragtrap "<< this->_name <<" has been destroyed" << std::endl;
  return;
}

void    FragTrap::vaulthunter_dot_exe(std::string const & target) {

  if (this->_energyPoints >= 25) {
    unsigned int randomNb = rand() % FragTrap::_nbRandomAttacks;

    std::cout << "FRAG-TP " << this->_name << " is using a " << FragTrap::_attacks[randomNb].name<< " attack on ";
    std::cout << target << " inflicting ";
    std::cout << FragTrap::_attacks[randomNb].dmg << " points of damages!" << std::endl;
    this->_energyPoints -= 25;
  } else {
    std::cout << this->_name << " is running low on energy and therfore can't do shit."  << std::endl;
  }
  return;
}

//PUBLIC NON MEMBER ATTRIBUTES
unsigned int   FragTrap::_nbRandomAttacks = 6;
r_attack       FragTrap::_attacks[] = {
  {"I Am Rubber, You Are Glue", 5},
  {"Load 'n' Splode", 15},
  {"Hyperion Punch", 25 },
  {"Livin' Near the Edge", 35 },
  {"One Last Thing", 66},
  {"Death Machine", 99}
};
