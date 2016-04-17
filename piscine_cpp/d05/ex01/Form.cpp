/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:58:31 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 13:58:32 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

Form::Form( void ) : _name( "no_name" ), _minSign( 70 ), _minExec( 30 ), _signed( false ) {
  return;
}

Form::Form( std::string n, int ms, int me ) : _name( n ), _minSign( ms ), _minExec( me ), _signed(false) {
  if ( this->_minSign < 1 || this->_minExec < 1 ) {
    throw Form::GradeTooHighException();
  }
  else if ( this->_minSign > 150 || this->_minExec > 150 ) {
    throw Form::GradeTooLowException();
  }
  return;
};

Form::Form( Form const & src) : _name (src.getName()), _minSign(src.getMinSign()), _minExec(src.getMinExec()) {
  *this = src;
};

Form::~Form( void ) {
  return;
};

Form & Form::operator=( Form const & rhs) {
  if (this != &rhs) {
    this->_signed = rhs.getSigned();
  }
  return *this;
};


std::string         Form::getName() const {
  return this->_name;
};

int                 Form::getMinSign() const {
  return this->_minSign;
};

int                 Form::getMinExec() const {
  return this->_minExec;
};

bool                 Form::getSigned() const {
  return this->_signed;
};

void                Form::beSigned(Bureaucrat const & rhs) {
  if (rhs.getGrade() <= this->_minSign) {
    this->_signed = true;
    rhs.signForm(this->_name, this->_minSign, true);
  } else {
    rhs.signForm(this->_name, this->_minSign, false);
    throw Form::GradeTooLowException();
  }
}


std::ostream &    operator<<( std::ostream & o, Form const & rhs) {
  o << "name: " << rhs.getName() << std::endl;
  o << "min to sign: " << rhs.getMinSign() << std::endl;
  o << "min to exec: " << rhs.getMinExec() << std::endl;
  if (rhs.getSigned())
    o << "Is it signed: true" << std::endl;
  else
    o << "Is it signed: false" << std::endl;
  return o;
};


Form::GradeTooHighException::GradeTooHighException( void ) {
  return;
};

Form::GradeTooHighException::GradeTooHighException( Form::GradeTooHighException const & src) {
  *this = src;
  return;
};

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {
  return;
};

Form::GradeTooHighException & Form::GradeTooHighException::operator=( Form::GradeTooHighException const & rhs) {
  (void)rhs;
  return *this;
};


const char * Form::GradeTooHighException::what() const throw() {
  return ( "GradeTooHighException" );
};


Form::GradeTooLowException::GradeTooLowException( void ) {
  return;
};

Form::GradeTooLowException::GradeTooLowException( Form::GradeTooLowException const & src) {
  *this = src;
  return;
};

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {
  return;
};

Form::GradeTooLowException & Form::GradeTooLowException::operator=( Form::GradeTooLowException const & rhs) {
  (void)rhs;
  return *this;
};

const char * Form::GradeTooLowException::what() const throw() {
  return ( "GradeTooLowException" );
};
