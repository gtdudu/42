/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:52:07 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 13:52:09 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

#ifndef HUMAN_H
# define HUMAN_H

class Human {

public:

	Human( void );
	~Human( void );

	std::string			identify( void ) const;
  Brain const &   getBrain( void ) const;


private:

  Brain const   _brain;

};

#endif
