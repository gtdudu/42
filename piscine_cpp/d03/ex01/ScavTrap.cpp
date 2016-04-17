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

#include "ScavTrap.hpp"
#include <iostream>

// CONSTRUCTORS
ScavTrap::ScavTrap( void ) : _hitPoints( 100 ), _maxHitPoints( 100 ),
_energyPoints( 50 ), _maxEnergyPoints( 50 ), _level( 1 ),
_name( "no_name"), _meleeAttackDamage( 20 ),
_rangedAttackDamage( 15 ), _armorDamageReduction( 3 ) {
  srand (time(NULL));
  std::cout << "An awesome ScavTrap was born." << std::endl;
  return;
}

ScavTrap::ScavTrap( std::string name ) : _hitPoints( 100 ), _maxHitPoints( 100 ),
_energyPoints( 50 ), _maxEnergyPoints( 50 ), _level( 1 ),
_name( name), _meleeAttackDamage( 20 ),
_rangedAttackDamage( 15 ), _armorDamageReduction( 3 ) {
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


// GETTER
unsigned int              ScavTrap::getHitpoints( void ) const {
  return this->_hitPoints;
};

unsigned int              ScavTrap::getMaxHitPoints( void ) const {
  return this->_maxHitPoints;
};

unsigned int              ScavTrap::getEnergyPoints( void ) const {
  return this->_energyPoints;
};

unsigned int              ScavTrap::getMaxEnergyPoints( void ) const {
  return this->_maxEnergyPoints;
};

unsigned int              ScavTrap::getLevel( void ) const {
    return this->_level;
};

std::string               ScavTrap::getName( void ) const {
    return this->_name;
};

unsigned int              ScavTrap::getMeleeAttackDamage( void ) const {
  return this->_meleeAttackDamage;
};

unsigned int              ScavTrap::getRangedAttackDamage( void ) const {
  return this->_rangedAttackDamage;
};

unsigned int              ScavTrap::getArmorDamageReduction( void ) const {
  return this->_armorDamageReduction;
};


// PUBLIC MEMBER FUNCTIONS
void    ScavTrap::rangedAttack(std::string const & target) const {
    std::cout << "SCAV-TP " << this->_name << " attacks " << target << " at range, causing ";
    std::cout << this->_rangedAttackDamage << " points of damage !" << std:: endl;
};

void    ScavTrap::meleeAttack(std::string const & target) const {
  std::cout << "SCAV-TP " << this->_name << " attacks " << target << " at melee, causing ";
  std::cout << this->_meleeAttackDamage << " points of damage !" << std:: endl;

};

void    ScavTrap::takeDamage( unsigned int amount ) {
  unsigned int  realDmg;
  if (amount > this->_armorDamageReduction)
    realDmg = amount - this->_armorDamageReduction;
  else
    realDmg = 0;
  if ( realDmg >= this->_hitPoints)
    this->_hitPoints = 0;
  else
    this->_hitPoints -= realDmg;
  std::cout << "SCAV-TP " << this->_name << " takes " << realDmg << "  points of damages ! ";
  std::cout << this->_hitPoints << "  remaining ! "  << std:: endl;
};

void    ScavTrap::beRepaired(unsigned int amount) {
  if ( (this->_hitPoints + amount ) >= this->_maxHitPoints )
    this->_hitPoints = this->_maxHitPoints;
  else
    this->_hitPoints += amount;

  std::cout << "SCAV-TP " << this->_name << " health increases by " << amount << ".";
  std::cout << " It now has " << this->_hitPoints << " hit points! " << std:: endl;
};

void    ScavTrap::challengeNewComer(std::string const & target) {

  unsigned int randomNb = rand() % ScavTrap::_nbRandomChallenges;
  std::cout << "SCAV-TP " << this->_name << " is challenging " << target <<  " to " << ScavTrap::_challenges[randomNb] << std::endl;
  return;
}

//PUBLIC NON MEMBER ATTRIBUTES
unsigned int   ScavTrap::_nbRandomChallenges = 3;
std::string    ScavTrap::_challenges[] = {"eat its own tire", "shoot itself with an unloaded gun", "listen to justin bieber discography"};

std::ostream &    operator<<(std::ostream & o, ScavTrap const & rhs) {
  o << "name: " << rhs.getName() << std::endl <<
	"hp: "<< rhs.getHitpoints() << std::endl <<
	"max hp: "<< rhs.getMaxHitPoints() << std::endl <<
	"energy: "<< rhs.getEnergyPoints() << std::endl <<
	"max energy: "<< rhs.getMaxEnergyPoints() << std::endl <<
	"lvl: "<< rhs.getLevel() << std::endl <<
	"melee dmg: "<< rhs.getMeleeAttackDamage() << std::endl <<
	"range dmg: "<< rhs.getRangedAttackDamage() << std::endl <<
	"armor reduction: "<< rhs.getArmorDamageReduction() << std::endl;

  return o;
}
