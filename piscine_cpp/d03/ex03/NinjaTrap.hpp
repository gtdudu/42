/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:45:21 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 17:45:23 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
# define NINJATRAP_H

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap {

public:
  NinjaTrap( void );
  NinjaTrap( std::string name );
  NinjaTrap( NinjaTrap const & src);
  ~NinjaTrap( void );

  void    ninjaShoebox(ScavTrap & target);
  void    ninjaShoebox(FragTrap & target);
  void    ninjaShoebox(NinjaTrap & target);

  NinjaTrap & operator=( NinjaTrap const & rhs );

};

#endif
