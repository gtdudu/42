/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:24:52 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 16:24:55 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form {

public:

  PresidentialPardonForm( void );
  PresidentialPardonForm( std::string target );
  PresidentialPardonForm( PresidentialPardonForm const & src );

  PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

  ~PresidentialPardonForm( void );
  virtual void          execute(Bureaucrat const & executor) const;

};

#endif
