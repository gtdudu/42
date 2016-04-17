/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:58:36 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/11 13:58:37 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_H
# define FORM_H

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

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

  class NotSignedException : public std::exception {

  public:

    NotSignedException( void );
    NotSignedException( NotSignedException const & src);
    virtual ~NotSignedException( void ) throw();
    NotSignedException & operator=( NotSignedException const & rhs);

    virtual const char * what() const throw();

  };


  Form( Form const & src);
  virtual ~Form( void );

  Form & operator=( Form const & rhs);

  std::string         getName() const;
  int                 getMinSign() const;
  int                 getMinExec() const;
  bool                getSigned() const;
  std::string         getTarget() const;

  void                beSigned(Bureaucrat const & rhs);
  virtual void          execute(Bureaucrat const & executor) const = 0;

protected:

  Form( void );
  Form( std::string n, int ms, int me, std::string t );
  void                checkExec(Bureaucrat const & rhs) const;

  void                setTarget(std::string t);
  void                setSigned(bool s);

private:


  std::string const     _name;
  int const             _minSign;
  int const             _minExec;
  bool                  _signed;
  std::string           _target;

};

std::ostream &    operator<<( std::ostream & o, Form const & rhs);

#endif
