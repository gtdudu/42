/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:01:50 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 11:01:51 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void ) {

  std::cout << "A new zombie event was created" << std::endl;
  return;
}

ZombieEvent::~ZombieEvent( void ) {

  std::cout << "Zombie event was destroyed" << std::endl;
  return;
}

void      ZombieEvent::setZombieType( std::string type ) {

  this->_type = type;
  return;
}

Zombie *   ZombieEvent::newZombie( std::string name ) {

  this->_name = name;
  Zombie * newZombie = new Zombie(this->_type, this->_name);

  return newZombie;
}


Zombie *   ZombieEvent::randomChump( void ) {

  int randomNb;

  srand (time(NULL));
  randomNb = rand() % 6;

  this->_name = ZombieEvent::_names[randomNb];
  Zombie * newZombie = new Zombie(this->_type, this->_name);

  newZombie->annouce();

  return newZombie;
}

const std::string ZombieEvent::_names[6] = {"Charly", "Gt", "Sura", "Aline", "Chloe", "Maggie"};
