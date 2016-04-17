/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:01:41 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 11:01:43 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie {

public:

	Zombie( std::string t, std::string n );
	Zombie( void );
	~Zombie( void );

	void 	annouce( void ) const;
	void 	setType( std::string t );
	void 	setName( std::string n );

private:


	std::string		_type;
	std::string 	_name;

};

#endif
