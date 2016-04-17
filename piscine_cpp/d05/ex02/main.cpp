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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int   main( void ) {

  std::cout << "FORM NOT SIGNED" << std::endl;
  try {
    Form * b = new ShrubberyCreationForm("home");
    Bureaucrat a(138);
    std::cout << *b;
    b->execute(a);
    delete b;
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  std::cout <<std::endl << "FORM SIGNED BUT GRADE TOO LOW" << std::endl;
  try {
    Form * b = new ShrubberyCreationForm("home");
    Bureaucrat a(138);
    b->beSigned(a);
    std::cout << *b;
    b->execute(a);

  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  std::cout <<std::endl << "SHRUBBERY FORM SIGNED, GRADE OK, BUREAUCRAT EXECUTE" << std::endl;
  try {
    Form * b = new ShrubberyCreationForm("home");
    Bureaucrat a(136);
    b->beSigned(a);
    std::cout << *b;
    a.executeForm(*b);

    delete b;
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }


  std::cout << "FORM NOT SIGNED" << std::endl;
  try {
    Form * b = new RobotomyRequestForm("thor");
    Bureaucrat a(138);
    std::cout << *b;
    b->execute(a);
    delete b;
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  std::cout <<std::endl << "FORM SIGNED BUT GRADE TOO LOW" << std::endl;
  try {
    Form * b = new RobotomyRequestForm("thor");
    Bureaucrat a(60);
    b->beSigned(a);
    std::cout << *b;
    b->execute(a);

  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }

  std::cout <<std::endl << "ROBOTOMY FORM SIGNED, GRADE OK, BUREAUCRAT EXECUTE" << std::endl;
  try {
    Form * b = new RobotomyRequestForm("thor");
    Bureaucrat a(44);
    b->beSigned(a);
    std::cout << *b;
    a.executeForm(*b);
    a.executeForm(*b);
    a.executeForm(*b);
    a.executeForm(*b);

    delete b;
  }
  catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }


    std::cout << "FORM NOT SIGNED" << std::endl;
    try {
      Form * b = new PresidentialPardonForm("gt");
      Bureaucrat a(138);
      std::cout << *b;
      b->execute(a);
      delete b;
    }
    catch (std::exception & e) {
      std::cout << e.what() << std::endl;
    }

    std::cout <<std::endl << "FORM SIGNED BUT GRADE TOO LOW" << std::endl;
    try {
      Form * b = new PresidentialPardonForm("gt");
      Bureaucrat a(138);
      b->beSigned(a);
      std::cout << *b;
      b->execute(a);

    }
    catch (std::exception & e) {
      std::cout << e.what() << std::endl;
    }

    std::cout <<std::endl << "PRESIDENTIAL FORM SIGNED, GRADE OK, BUREAUCRAT EXECUTE" << std::endl;
    try {
      Form * b = new PresidentialPardonForm("gt");
      Bureaucrat a(4);
      b->beSigned(a);
      std::cout << *b;
      a.executeForm(*b);

      delete b;
    }
    catch (std::exception & e) {
      std::cout << e.what() << std::endl;
    }

  return ( 0 );
}
