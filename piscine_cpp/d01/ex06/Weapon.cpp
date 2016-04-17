/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:06:43 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 15:06:44 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon( void ) {
  return;
}

Weapon::~Weapon( void ) {
  return;
}

std::string const&     Weapon::getType( void ) const {


  return this->type;
};
