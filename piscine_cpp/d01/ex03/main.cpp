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
#include "ZombieHorde.hpp"

int   main() {

  ZombieHorde   mainHorde = ZombieHorde(2);

  mainHorde.annouce();


  return ( 0 );
}
