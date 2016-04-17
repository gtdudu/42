/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:02:23 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 11:02:24 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int   main() {

  Zombie        tank = Zombie("tank", "Robert");
  ZombieEvent   factory;

  factory.setZombieType("jockey");

  Zombie* namedZombie = factory.newZombie("Raph");
  Zombie* ramdomZombie = factory.randomChump();

  tank.annouce();
  namedZombie->annouce();

  delete namedZombie;
  delete ramdomZombie;

  return ( 0 );
}
