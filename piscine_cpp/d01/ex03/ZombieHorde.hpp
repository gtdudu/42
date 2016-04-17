/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 12:37:55 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 12:37:58 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

class ZombieHorde {

public:

	ZombieHorde( int n );
	~ZombieHorde( void );

  void 	annouce( void ) const;

private:

	const int 	_hordeSize;
  Zombie * 		_store;
	static const std::string _names[];

};

#endif
