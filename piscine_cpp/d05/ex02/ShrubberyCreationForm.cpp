/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:24:12 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 16:24:13 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("buisson", 145, 137, "no_target") {
  std::cout << "create Shrubbery" << std::endl;
  return;
};

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("buisson", 145, 137, target) {
  std::cout << "custom create Shrubbery" << std::endl;
  return;
};

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) {
  std::cout << "copy create Shrubbery" << std::endl;
  *this = src;
  return;
};

//ASSIGNATION
ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
  std::cout << "assignation Shrubbery" << std::endl;
  if (this != &rhs) {
    this->setSigned(rhs.getSigned());
    this->setTarget(rhs.getTarget());
  }
  return *this;
};

//IMPLEMENTATION
void          ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  this->checkExec(executor);
  std::string			filename;

  filename = this->getTarget() + "_shrubbery";
  std::ifstream infile(filename);
  if (!infile.good()) {
  	std::ofstream		out(filename);
  	out << "   *   \n  ***  \n ***** \n   *   \n";
  	out.close();
    std::cout << "created file " << this->getTarget() << std::endl;
  } else {
    std::cout << "file already exists" << std::endl;
  }
  return;
}

// DESTRUCTOR
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
  std::cout << "destruction Shrubbery" << std::endl;
  return;
};
