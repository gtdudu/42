/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:23:59 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 15:24:00 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <iostream>

class ScavTrap {

public:
  ScavTrap( void );
  ScavTrap( std::string name );
  ScavTrap( ScavTrap const & src);
  ~ScavTrap( void );

  void    rangedAttack( std::string const & target ) const;
  void    meleeAttack( std::string const & target ) const;
  void    takeDamage( unsigned int amout );
  void    beRepaired( unsigned int amout );
  void    challengeNewComer(std::string const & target);

  unsigned int              getHitpoints( void ) const;
  unsigned int              getMaxHitPoints( void ) const;
  unsigned int              getEnergyPoints( void ) const;
  unsigned int              getMaxEnergyPoints( void ) const;
  unsigned int              getLevel( void ) const;
  std::string               getName( void ) const;
  unsigned int              getMeleeAttackDamage( void ) const;
  unsigned int              getRangedAttackDamage( void ) const;
  unsigned int              getArmorDamageReduction( void ) const;


  ScavTrap & operator=( ScavTrap const & rhs );


private:
  unsigned int               _hitPoints;
  unsigned int               _maxHitPoints;
  unsigned int               _energyPoints;
  unsigned int               _maxEnergyPoints;
  unsigned int               _level;
  std::string                _name;
  unsigned int               _meleeAttackDamage;
  unsigned int               _rangedAttackDamage;
  unsigned int               _armorDamageReduction;

  static unsigned int       _nbRandomChallenges;
  static std::string        _challenges[];

};


std::ostream &    operator<<( std::ostream & o, ScavTrap const & rhs);


#endif
