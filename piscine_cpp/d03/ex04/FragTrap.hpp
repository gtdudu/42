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
#include "ClapTrap.hpp"

struct  r_attack;

class FragTrap : public virtual ClapTrap {

public:
  FragTrap( void );
  FragTrap( std::string name );
  FragTrap( FragTrap const & src);
  ~FragTrap( void );

  FragTrap & operator=( FragTrap const & rhs );

  void    vaulthunter_dot_exe(std::string const & target);



private:

  static unsigned int       _nbRandomAttacks;
  static r_attack           _attacks[];

};

#endif
