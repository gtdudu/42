/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:50:38 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/14 16:50:39 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <vector>
#include <deque>
#include <iostream>

int     main( void ) {


  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  std::cout << "size: " << mstack.size() << std::endl;
  //
  //
  //
  MutantStack<int>::iterator it = mstack.begin();
  it++;

  std::cout << "*begin: " << *it << std::endl;
  // MutantStack<int>::iterator ite = mstack.end();
  // ++it;
  // --it;
  // while (it != ite) {
  // std::cout << *it << std::endl;
  // ++it;
  // }
  std::stack<int> s(mstack);

  return ( 0 );
}
