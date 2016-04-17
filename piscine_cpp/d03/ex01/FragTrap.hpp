/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:03:07 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 10:03:08 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>

struct  r_attack;

class FragTrap {

public:
  FragTrap( void );
  FragTrap( std::string name );
  FragTrap( FragTrap const & src);
  ~FragTrap( void );

  void    rangedAttack( std::string const & target ) const;
  void    meleeAttack( std::string const & target ) const;
  void    takeDamage( unsigned int amout );
  void    beRepaired( unsigned int amout );
  void    vaulthunter_dot_exe(std::string const & target);

  unsigned int              getHitpoints( void ) const;
  unsigned int              getMaxHitPoints( void ) const;
  unsigned int              getEnergyPoints( void ) const;
  unsigned int              getMaxEnergyPoints( void ) const;
  unsigned int              getLevel( void ) const;
  std::string               getName( void ) const;
  unsigned int              getMeleeAttackDamage( void ) const;
  unsigned int              getRangedAttackDamage( void ) const;
  unsigned int              getArmorDamageReduction( void ) const;


  FragTrap & operator=( FragTrap const & rhs );


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

  static unsigned int       _nbRandomAttacks;
  static r_attack           _attacks[];

};


std::ostream &    operator<<( std::ostream & o, FragTrap const & rhs);


#endif
