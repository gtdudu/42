/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 12:30:48 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/13 12:30:51 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T >
void      iter( T *arr, int len, void (*f)(T const &)) {
  for (int i = 0; i < len; i++) {
    (*f)(arr[i]);
  }
  std::cout << std::endl;
  return;
}

template< typename T >
void  printItem(T const & item) {
  std::cout << item << " ";
  return;
}

int   main( void ) {

  std::string   strArr[] = {"how", "are", "you", "?"};
  int           intArr[] = {1, 2, 3, 4, 5};
  float         floatArr[] = {1.45f, -3.6f, 8.4f, 9.9f, 0.03f};
  int           len = 4;

  std::cout << "adress strArr: " << strArr << std::endl;
  iter<std::string>(strArr, len, printItem<std::string>);

  std::cout << "adress intArr: " << intArr << std::endl;
  iter<int>(intArr, len, printItem<int>);

  std::cout << "adress floatArr: " << floatArr << std::endl;
  iter<float>(floatArr, len, printItem<float>);

  return ( 0 );
}
