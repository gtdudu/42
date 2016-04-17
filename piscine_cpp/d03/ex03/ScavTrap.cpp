/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:23:54 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 15:23:55 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

// CONSTRUCTORS
ScavTrap::ScavTrap( void ) : ClapTrap(100, 100, 50, 50, 1, "Oscavy", 20, 15, 3) {
  srand (time(NULL));
  std::cout << "An awesome ScavTrap was born." << std::endl;
  return;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3) {
  srand (time(NULL));
  std::cout << "Kick ass ScavTrap named " << this->_name << " is borned." << std::endl;
  return;
}

ScavTrap::ScavTrap( ScavTrap const & src) {
  *this = src;
  std::cout << this->_name << " the ScavTrap has been created by copy." << std::endl;
  return;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {
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
ScavTrap::~ScavTrap() {
  std::cout << "Poor ScavTrap "<< this->_name <<" is no longer living." << std::endl;
  return;
}

void    ScavTrap::challengeNewComer(std::string const & target) {

  unsigned int randomNb = rand() % ScavTrap::_nbRandomChallenges;
  std::cout << "SCAV-TP " << this->_name << " is challenging " << target <<  " to " << ScavTrap::_challenges[randomNb] << std::endl;
  return;
}

//PUBLIC NON MEMBER ATTRIBUTES
unsigned int   ScavTrap::_nbRandomChallenges = 4;
std::string    ScavTrap::_challenges[] = {"eat its own tire", "shoot itself with an unloaded gun", "listen to justin bieber discography", "stop talking for a while"};
