/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:25:21 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 16:25:22 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form {

public:

  RobotomyRequestForm( void );
  RobotomyRequestForm( std::string target );
  RobotomyRequestForm( RobotomyRequestForm const & src );

  RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

  ~RobotomyRequestForm( void );
  virtual void          execute(Bureaucrat const & executor) const;

private:
  static int        _nbCalled;
};

#endif
