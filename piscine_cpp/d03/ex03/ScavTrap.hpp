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
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
  ScavTrap( void );
  ScavTrap( std::string name );
  ScavTrap( ScavTrap const & src);
  ~ScavTrap( void );

  void    challengeNewComer(std::string const & target);

  ScavTrap & operator=( ScavTrap const & rhs );


private:

  static unsigned int       _nbRandomChallenges;
  static std::string        _challenges[];

};

#endif
