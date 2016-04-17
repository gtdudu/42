/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 16:50:35 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/06 16:50:36 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMAN_H
# define HUMAN_H

#include <iostream>

class Human {

typedef void (Human::*Funcs)(std::string const &);

public:
  Human( void );
  ~Human( void );
  void action(std::string const & action_name, std::string const & target);

private:
  void                      meleeAttack(std::string const & target);
  void                      rangedAttack(std::string const & target);
  void                       intimidatingShout(std::string const & target);
  Funcs                     _store[3];
  static const std::string  _names[];

};

#endif
