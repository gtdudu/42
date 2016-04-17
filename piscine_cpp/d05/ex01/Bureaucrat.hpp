/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 11:59:07 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 11:59:08 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <stdexcept>

class Bureaucrat {

public:

  Bureaucrat( void );
  Bureaucrat( int grade );
  Bureaucrat( Bureaucrat const & src);
  ~Bureaucrat( void );

  class GradeTooHighException : public std::exception {

  public:

    GradeTooHighException( void );
    GradeTooHighException( GradeTooHighException const & src);
    virtual ~GradeTooHighException( void ) throw();
    GradeTooHighException & operator=( GradeTooHighException const & rhs);

    virtual const char * what() const throw();
  };

  class GradeTooLowException : public std::exception {

  public:

    GradeTooLowException( void );
    GradeTooLowException( GradeTooLowException const & src);
    virtual ~GradeTooLowException( void ) throw();
    GradeTooLowException & operator=( GradeTooLowException const & rhs);

    virtual const char * what() const throw();

  };

  Bureaucrat & operator=( Bureaucrat const & rhs);

  std::string   getName() const;
  int           getGrade() const;
  void          incrementGrade();
  void          decrementGrade();
  void          signForm(std::string fn, int fg, bool ok) const;

private:
  std::string const   _name;
  int                 _grade;

};

std::ostream &    operator<<( std::ostream & o, Bureaucrat const & rhs);

#endif
