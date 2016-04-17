/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 11:59:01 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 11:59:03 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( void ) : _name("bury"), _grade(150) {
  return;
};

Bureaucrat::Bureaucrat( int grade, std::string name ) : _name(mame) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  else {
    this->_grade = grade;
  }
  return;
};

Bureaucrat::Bureaucrat( Bureaucrat const & src) {
  *this = src;
  std::cout << "Bureaucrat " << this->_name << " was created." << std::endl;
  return;
};

Bureaucrat::~Bureaucrat( void ) {
  return;
};

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs) {
  std::cout << "Assignation operator called" << std::endl;
  if (this != &rhs) {
    this->_grade = rhs.getGrade();
  }
  return *this;
};

std::string   Bureaucrat::getName() const {
  return this->_name;
};

int           Bureaucrat::getGrade() const {
    return this->_grade;
};

void          Bureaucrat::incrementGrade() {
  if (this->_grade == 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  else {
    this->_grade -= 1;
  }
  return;
};

void          Bureaucrat::decrementGrade() {
  if (this->_grade == 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  else {
    this->_grade += 1;
  }
  return;
}


Bureaucrat::GradeTooHighException::GradeTooHighException( void ) {
  return;
};

Bureaucrat::GradeTooHighException::GradeTooHighException( Bureaucrat::GradeTooHighException const & src) {
  *this = src;
  return;
};

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {
  return;
};

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=( Bureaucrat::GradeTooHighException const & rhs) {
  (void)rhs;
  return *this;
};


const char * Bureaucrat::GradeTooHighException::what() const throw() {
  return ( "GradeTooHighException" );
};


Bureaucrat::GradeTooLowException::GradeTooLowException( void ) {
  return;
};

Bureaucrat::GradeTooLowException::GradeTooLowException( Bureaucrat::GradeTooLowException const & src) {
  *this = src;
  return;
};

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {
  return;
};

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=( Bureaucrat::GradeTooLowException const & rhs) {
  (void)rhs;
  return *this;
};


const char * Bureaucrat::GradeTooLowException::what() const throw() {
  return ( "GradeTooLowException" );
};

std::ostream &    operator<<( std::ostream & o, Bureaucrat const & rhs) {
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
  return o;
};
