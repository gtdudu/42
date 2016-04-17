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

#include "FragTrap.hpp"
#include <iostream>


//RANDOM ATTACK STRUCT
struct r_attack
{
	std::string		name;
	unsigned int  dmg;
};

// CONSTRUCTORS
FragTrap::FragTrap( void ) : _hitPoints( 100 ), _maxHitPoints( 100 ),
_energyPoints( 100 ), _maxEnergyPoints( 100 ), _level( 1 ),
_name( "no_name"), _meleeAttackDamage( 30 ),
_rangedAttackDamage( 20 ), _armorDamageReduction( 5 ) {
  srand (time(NULL));
  std::cout << "Default fragtrap was created." << std::endl;
  return;
}

FragTrap::FragTrap( std::string name ) : _hitPoints( 100 ), _maxHitPoints( 100 ),
_energyPoints( 100 ), _maxEnergyPoints( 100 ), _level( 1 ),
_name( name ), _meleeAttackDamage( 30 ),
_rangedAttackDamage( 20 ), _armorDamageReduction( 5 ) {
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


// GETTER
unsigned int              FragTrap::getHitpoints( void ) const {
  return this->_hitPoints;
};

unsigned int              FragTrap::getMaxHitPoints( void ) const {
  return this->_maxHitPoints;
};

unsigned int              FragTrap::getEnergyPoints( void ) const {
  return this->_energyPoints;
};

unsigned int              FragTrap::getMaxEnergyPoints( void ) const {
  return this->_maxEnergyPoints;
};

unsigned int              FragTrap::getLevel( void ) const {
    return this->_level;
};

std::string               FragTrap::getName( void ) const {
    return this->_name;
};

unsigned int              FragTrap::getMeleeAttackDamage( void ) const {
  return this->_meleeAttackDamage;
};

unsigned int              FragTrap::getRangedAttackDamage( void ) const {
  return this->_rangedAttackDamage;
};

unsigned int              FragTrap::getArmorDamageReduction( void ) const {
  return this->_armorDamageReduction;
};


// PUBLIC MEMBER FUNCTIONS
void    FragTrap::rangedAttack(std::string const & target) const {
    std::cout << "FRAG-TP " << this->_name << " attacks " << target << " at range, causing ";
    std::cout << this->_rangedAttackDamage << " points of damage !" << std:: endl;
};

void    FragTrap::meleeAttack(std::string const & target) const {
  std::cout << "FRAG-TP " << this->_name << " attacks " << target << " at melee, causing ";
  std::cout << this->_meleeAttackDamage << " points of damage !" << std:: endl;

};

void    FragTrap::takeDamage( unsigned int amount ) {
  unsigned int  realDmg;
  if (amount > this->_armorDamageReduction)
    realDmg = amount - this->_armorDamageReduction;
  else
    realDmg = 0;
  if ( realDmg >= this->_hitPoints)
    this->_hitPoints = 0;
  else
    this->_hitPoints -= realDmg;
  std::cout << "FRAG-TP " << this->_name << " takes " << realDmg << "  points of damages ! ";
  std::cout << this->_hitPoints << "  remaining ! "  << std:: endl;
};

void    FragTrap::beRepaired(unsigned int amount) {
  if ( (this->_hitPoints + amount ) >= this->_maxHitPoints )
    this->_hitPoints = this->_maxHitPoints;
  else
    this->_hitPoints += amount;

  std::cout << "FRAG-TP " << this->_name << " health increases by " << amount << ".";
  std::cout << " It now has " << this->_hitPoints << " hit points! " << std:: endl;
};

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

std::ostream &    operator<<(std::ostream & o, FragTrap const & rhs) {
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
