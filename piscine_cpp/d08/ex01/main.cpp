/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 11:27:19 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/14 11:27:20 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>


int     main ( void ) {

  Span    s1(5);
  Span    s2(10001);
  Span    s3(1);
  Span    s4(0);



  std::cout << std::endl << "SUBJECT MAIN: " << std::endl;
  try {
    s1.addNumber(5);
    s1.addNumber(3);
    s1.addNumber(17);
    s1.addNumber(9);
    s1.addNumber(11);
    std::cout << "shortestSpan: " << s1.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << s1.longestSpan() << std::endl;
  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }



  std::cout << std::endl << "NO ELEM ERROR: " << std::endl;
  try {
    std::cout << "shortestSpan: " << s4.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << s4.longestSpan() << std::endl;
  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl << "ONE ELEM ERROR: " << std::endl;
  try {
    s3.addNumber(5);
    std::cout << "shortestSpan: " << s3.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << s3.longestSpan() << std::endl;
  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }


  std::cout << std::endl << "HUGE LIST NOP: " << std::endl;
  try {
    s2.addNumber(20000 , -1045967, 1456789);
    std::cout << "size: " << s2.getL().size() << std::endl;
    std::cout << "shortestSpan: " << s2.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << s2.longestSpan() << std::endl;
    std::cout << "front: " << s2.getL().front() << std::endl;
    std::cout << "back: " << s2.getL().back() << std::endl;

  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }


  std::cout << std::endl << "MEDIUM LIST OK: " << std::endl;
  try {
    s2.addNumber(100 , -21111, 14567);
    std::cout << "size: " << s2.getL().size() << std::endl;
    std::cout << "shortestSpan: " << s2.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << s2.longestSpan() << std::endl;
    std::cout << "front: " << s2.getL().front() << std::endl;
    std::cout << "back: " << s2.getL().back() << std::endl;

  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }


  std::cout << std::endl << "HUGE LIST OK: " << std::endl;
  try {
    s2.addNumber(9900 , -211110, 1456700);
    std::cout << "size: " << s2.getL().size() << std::endl;
    std::cout << "shortestSpan: " << s2.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << s2.longestSpan() << std::endl;
    std::cout << "front: " << s2.getL().front() << std::endl;
    std::cout << "back: " << s2.getL().back() << std::endl;

  } catch ( std::exception e) {
    std::cout << e.what() << std::endl;
  }

  return ( 0 );
}
