/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:24:21 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 16:24:25 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
#include "Form.hpp"
#include <string>

class ShrubberyCreationForm : public Form {

public:

  ShrubberyCreationForm( void );
  ShrubberyCreationForm( std::string target );
  ShrubberyCreationForm( ShrubberyCreationForm const & src );

  ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

  ~ShrubberyCreationForm( void );
  virtual void          execute(Bureaucrat const & executor) const;

};

#endif
