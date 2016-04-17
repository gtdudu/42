/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:46:51 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 15:46:52 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include <iostream>

// CONSTRUCTORS
ClapTrap::ClapTrap( void ) : _hitPoints( 100 ), _maxHitPoints( 100 ),
_energyPoints( 0 ), _maxEnergyPoints( 0 ), _level( 1 ),
_name( "no_name"), _meleeAttackDamage( 0 ),
_rangedAttackDamage( 0 ), _armorDamageReduction( 0 ) {
  std::cout << "ClapTrap constructor called." << std::endl;
  return;
}

ClapTrap::ClapTrap( unsigned int hp, unsigned int mhp, unsigned int e, unsigned int me, unsigned int lvl, std::string n, unsigned int mad,
   unsigned int rad, unsigned int ard ) : _hitPoints( hp ), _maxHitPoints( mhp ),
_energyPoints( e ), _maxEnergyPoints( me ), _level( lvl ),
_name( n ), _meleeAttackDamage( mad ),
_rangedAttackDamage( rad ), _armorDamageReduction( ard ) {
  std::cout << "ClapTrap constructor called." << std::endl;
  return;
}

ClapTrap::ClapTrap( ClapTrap const & src) {
  *this = src;
  std::cout << "Copy ClapTrap constructor called." << std::endl;
  return;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {
  std::cout << "ClapTrap assignation operator called" << std::endl;
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
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap has been destroyed" << std::endl;
  return;
}


// GETTER
unsigned int              ClapTrap::getHitpoints( void ) const {
  return this->_hitPoints;
};

unsigned int              ClapTrap::getMaxHitPoints( void ) const {
  return this->_maxHitPoints;
};

unsigned int              ClapTrap::getEnergyPoints( void ) const {
  return this->_energyPoints;
};

unsigned int              ClapTrap::getMaxEnergyPoints( void ) const {
  return this->_maxEnergyPoints;
};

unsigned int              ClapTrap::getLevel( void ) const {
    return this->_level;
};

std::string               ClapTrap::getName( void ) const {
    return this->_name;
};

unsigned int              ClapTrap::getMeleeAttackDamage( void ) const {
  return this->_meleeAttackDamage;
};

unsigned int              ClapTrap::getRangedAttackDamage( void ) const {
  return this->_rangedAttackDamage;
};

unsigned int              ClapTrap::getArmorDamageReduction( void ) const {
  return this->_armorDamageReduction;
};


// PUBLIC MEMBER FUNCTIONS
void    ClapTrap::rangedAttack(std::string const & target) const {
    std::cout << this->_name << " attacks " << target << " at range, causing ";
    std::cout << this->_rangedAttackDamage << " points of damage !" << std:: endl;
};

void    ClapTrap::meleeAttack(std::string const & target) const {
  std::cout << this->_name << " attacks " << target << " at melee, causing ";
  std::cout << this->_meleeAttackDamage << " points of damage !" << std:: endl;

};

void    ClapTrap::takeDamage( unsigned int amount ) {
  unsigned int  realDmg;
  if (amount > this->_armorDamageReduction)
    realDmg = amount - this->_armorDamageReduction;
  else
    realDmg = 0;
  if ( realDmg >= this->_hitPoints)
    this->_hitPoints = 0;
  else
    this->_hitPoints -= realDmg;
  std::cout << this->_name << " takes " << realDmg << "  points of damages ! ";
  std::cout << this->_hitPoints << "  remaining ! "  << std:: endl;
};

void    ClapTrap::beRepaired(unsigned int amount) {
  if ( (this->_hitPoints + amount ) >= this->_maxHitPoints )
    this->_hitPoints = this->_maxHitPoints;
  else
    this->_hitPoints += amount;

  std::cout << this->_name << " health increases by " << amount << ".";
  std::cout << " It now has " << this->_hitPoints << " hit points! " << std:: endl;
};

std::ostream &    operator<<(std::ostream & o, ClapTrap const & rhs) {
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
