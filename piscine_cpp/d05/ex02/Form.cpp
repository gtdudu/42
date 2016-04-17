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
  std::cout << "form Consctructor" << std::endl;
  return;
}

Form::Form( std::string n, int ms, int me, std::string t ) : _name( n ), _minSign( ms ), _minExec( me ), _signed( false ), _target( t ) {
  std::cout << "custon form Consctructor" << std::endl;
  if ( this->_minSign < 1 || this->_minExec < 1 ) {
    throw Form::GradeTooHighException();
  }
  else if ( this->_minSign > 150 || this->_minExec > 150 ) {
    throw Form::GradeTooLowException();
  }
  return;
};

Form::Form( Form const & src) : _name (src.getName()), _minSign(src.getMinSign()), _minExec(src.getMinExec()) {
  std::cout << "copy form Consctructor" << std::endl;
  *this = src;
};

Form::~Form( void ) {
  std::cout << "form desctructor" << std::endl;
  return;
};

Form & Form::operator=( Form const & rhs) {
  std::cout << "form assignation" << std::endl;
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

bool                Form::getSigned() const {
  return this->_signed;
};

std::string         Form::getTarget() const {
  return this->_target;
}

void                Form::setSigned(bool s) {
    this->_signed = s;
};

void                Form::setTarget(std::string t) {
  this->_target = t;
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



void                Form::checkExec(Bureaucrat const & rhs) const {
  if (this->_signed) {
    if (rhs.getGrade() > this->_minExec)
      throw Form::GradeTooLowException();
  } else {
    throw Form::NotSignedException();
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
  o << "target: " << rhs.getTarget()<< std::endl;
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


Form::NotSignedException::NotSignedException( void ) {
  return;
};

Form::NotSignedException::NotSignedException( Form::NotSignedException const & src) {
  *this = src;
  return;
};

Form::NotSignedException::~NotSignedException( void ) throw() {
  return;
};

Form::NotSignedException & Form::NotSignedException::operator=( Form::NotSignedException const & rhs) {
  (void)rhs;
  return *this;
};

const char * Form::NotSignedException::what() const throw() {
  return ( "Forn isn't signed!" );
};
