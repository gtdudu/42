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


#include "Bureaucrat.hpp"
#include <iostream>

int   main( void ) {

  try {
    Bureaucrat * b = new Bureaucrat(150);

    std::cout << *b;
    b->incrementGrade();
    std::cout << *b;
    b->decrementGrade();
    std::cout << *b;
    b->decrementGrade();

 }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  return ( 0 );
}
