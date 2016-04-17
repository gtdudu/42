/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:25:14 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 16:25:15 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm( void ) : Form("robotomy", 72, 45, "no_target") {
  std::cout << "create Robotomy" << std::endl;
  return;
};

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("robotomy", 72, 45, target) {
  std::cout << "custom create Robotomy" << std::endl;
  return;
};

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) {
  std::cout << "copy create Robotomy" << std::endl;
  *this = src;
  return;
};

//ASSIGNATION
RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
  std::cout << "assignation Robotomy" << std::endl;
  if (this != &rhs) {
    this->setSigned(rhs.getSigned());
    this->setTarget(rhs.getTarget());
  }
  return *this;
};

//IMPLEMENTATION
void          RobotomyRequestForm::execute(Bureaucrat const & executor) const {
  this->checkExec(executor);
  if (RobotomyRequestForm::_nbCalled == 0) {
    std::cout << "\7DRrrrrrrrrRrRRrrrr" << this->getTarget() << " has been robotomized successfully." << std::endl;
    RobotomyRequestForm::_nbCalled += 1;
  } else {
    std::cout << this->getTarget() << " robotomization has failed." << std::endl;
    RobotomyRequestForm::_nbCalled = 0;
  }
  return;
}

// DESTRUCTOR
RobotomyRequestForm::~RobotomyRequestForm( void ) {
  std::cout << "destruction Robotomy" << std::endl;
  return;
};

int          RobotomyRequestForm::_nbCalled = 0;
