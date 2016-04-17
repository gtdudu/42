/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:24:40 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 16:24:42 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm( void ) : Form("president", 25, 5, "no_target") {
  std::cout << "create Presidential" << std::endl;
  return;
};

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("president", 25, 5, target) {
  std::cout << "custom create Presidential" << std::endl;
  return;
};

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) {
  std::cout << "copy create Presidential" << std::endl;
  *this = src;
  return;
};

//ASSIGNATION
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
  std::cout << "assignation Presidential" << std::endl;
  if (this != &rhs) {
    this->setSigned(rhs.getSigned());
    this->setTarget(rhs.getTarget());
  }
  return *this;
};

//IMPLEMENTATION
void          PresidentialPardonForm::execute(Bureaucrat const & executor) const {
  this->checkExec(executor);
  std::cout << this->getTarget() << "  has been pardoned by Zafod Beeblebrox." << std::endl;
  return;
}

// DESTRUCTOR
PresidentialPardonForm::~PresidentialPardonForm( void ) {
  std::cout << "destruction Presidential" << std::endl;
  return;
};
