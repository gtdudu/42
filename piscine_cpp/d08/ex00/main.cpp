/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 10:48:34 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/14 10:48:35 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

void  printItem(int n) {

  std::cout << n << " ";
  return;
}

int   main( void ) {

  std::list<int>    lst;
  std::vector<int>  vec;

  lst.push_back(2);
  lst.push_back(5);
  lst.push_back(99);
  lst.push_back(42);
  lst.push_back(0);


  vec.push_back(2);
  vec.push_back(5);
  vec.push_back(99);
  vec.push_back(42);
  vec.push_back(0);


  std::cout << "PRINTING VECTOR: " << std::endl;
  for_each(vec.begin(), vec.end(), printItem);
  std::cout << std::endl;

  std::cout << "PRINTING LIST: " << std::endl;
  for_each(lst.begin(), lst.end(), printItem);
  std::cout << std::endl;

  std::cout << "LOOKING FOR 42 IN LST: SHOULD WORK" << std::endl;
  try {
    std::cout << easyfind< std::list< int > >(lst, 42) << std::endl;
  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "LOOKING FOR 42 IN VEC: SHOULD WORK" << std::endl;
  try {
    std::cout << easyfind< std::vector< int > >(vec, 42) << std::endl;
  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "LOOKING FOR 7 IN LST: SHOULD NOT WORK" << std::endl;
  try {
    std::cout << easyfind< std::list< int > >(lst, 7) << std::endl;
  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "LOOKING FOR 7 IN VEC: SHOULD NOT WORK" << std::endl;
  try {
    std::cout << easyfind< std::vector< int > >(vec, 7) << std::endl;
  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }

  return ( 0 );
}
