/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:09:49 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/13 15:09:50 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int   main( void ) {

  Array<char>      i( 9 );
  Array<float>    f( 1 );
  Array<float>    copy(f);
  Array<unsigned int> l;

  i.print("i");
  f.print("f");
  copy.print("copy");



  try {
    i[-1] = 9;
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
    std::cout << "NEGATIVE INDEX" << std::endl << std::endl;
  }


  try {
    i[9] = 'f';
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
    std::cout << "INDEX TOO HIGH" << std::endl << std::endl;
  }

  std::cout << "PRINT LENGTH i: " << i.size() << std::endl << std::endl;
  std::cout << "PRINT LENGTH f: " << f.size() << std::endl << std::endl;
  std::cout << "PRINT LENGTH copy: " << copy.size() << std::endl << std::endl;


  try {
    i[5] = 'u';
    f[0] = 42;
    i.print("i");
    f.print("f");
    copy.print("copy");
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

;

  return ( 0 );
}
