/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 11:59:14 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 11:59:16 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int   main( void ) {

  try {
    Form a;
    std::cout << a;
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Form * b = new Form("joey", 2, 160);
    std::cout << *b;
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Form a;
    Form c ( a );
    std::cout << c;
    Bureaucrat b;
    c.beSigned(b);
    std::cout << c;

  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Form * b = new Form("joey", 30, 140);
    Bureaucrat * e = new Bureaucrat(20);
    b->beSigned(*e);
    std::cout << *b;
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  return ( 0 );
}
