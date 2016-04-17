/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:22:34 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 18:22:36 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap  {

public:
  SuperTrap( void );
  SuperTrap( std::string name );
  SuperTrap( SuperTrap const & src);
  ~SuperTrap( void );

  SuperTrap & operator=( SuperTrap const & rhs );

};

#endif
