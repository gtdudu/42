/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 12:37:48 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 12:37:50 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int n ) : _store( new Zombie[n] ), _hordeSize( n ){

  int randomNb;

  srand (time(NULL));
  std::cout << "A new zombie horde was created" << std::endl;

  for (int i=0; i<n; i++){
      randomNb = rand() % 10;
      this->_store[i].setName(ZombieHorde::_names[randomNb]);
      this->_store[i].setType("Hunter");
  }
  return;
}

ZombieHorde::~ZombieHorde( void ) {

  delete [] this->_store;
  std::cout << "The zombie horde was completly destroyed" << std::endl;
  return;
}

void      ZombieHorde::annouce( void ) const {

  for (int i=0; i<this->_hordeSize; i++){
    this->_store[i].annouce();
  }
  return;
}

const std::string ZombieHorde::_names[10] = {"Charly", "Gt", "Sura", "Aline", "Chloe", "Maggie", "Rick", "Antoine", "Gaessy", "Jordane"};
