/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 09:52:23 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 09:52:24 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

void   makePonyStack( void ) {

  Pony  ponyOnStack = Pony("george the heapster", "blue");
  ponyOnStack.getColor();
  return;
}

Pony*   makePonyHeap( void ) {

  Pony* makePonyHeap = new Pony("sarah the stack holder", "red");
  return makePonyHeap;
}

int   main() {

  Pony  *stillExist;

  stillExist = makePonyHeap();
  makePonyStack();

  stillExist->getColor();
  delete stillExist;

  return ( 0 );
};
