/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:46:56 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 15:46:57 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap {

public:
  ClapTrap( void );
  ClapTrap( unsigned int e, unsigned int me, std::string n, unsigned int mad, unsigned int rad, unsigned int ard );
  ClapTrap( ClapTrap const & src);
  ~ClapTrap( void );

  void    rangedAttack( std::string const & target ) const;
  void    meleeAttack( std::string const & target ) const;
  void    takeDamage( unsigned int amout );
  void    beRepaired( unsigned int amout );

  unsigned int              getHitpoints( void ) const;
  unsigned int              getMaxHitPoints( void ) const;
  unsigned int              getEnergyPoints( void ) const;
  unsigned int              getMaxEnergyPoints( void ) const;
  unsigned int              getLevel( void ) const;
  std::string               getName( void ) const;
  unsigned int              getMeleeAttackDamage( void ) const;
  unsigned int              getRangedAttackDamage( void ) const;
  unsigned int              getArmorDamageReduction( void ) const;


  ClapTrap & operator=( ClapTrap const & rhs );


protected:
  unsigned int               _hitPoints;
  unsigned int               _maxHitPoints;
  unsigned int               _energyPoints;
  unsigned int               _maxEnergyPoints;
  unsigned int               _level;
  std::string                _name;
  unsigned int               _meleeAttackDamage;
  unsigned int               _rangedAttackDamage;
  unsigned int               _armorDamageReduction;

};


std::ostream &    operator<<( std::ostream & o, ClapTrap const & rhs);


#endif
