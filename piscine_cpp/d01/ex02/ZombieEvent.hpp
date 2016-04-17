/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:11:42 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 11:11:49 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H

class ZombieEvent {

public:

	ZombieEvent( void );
	~ZombieEvent( void );

	void 				setZombieType(std::string type);
	Zombie* 		newZombie(std::string name);
	Zombie*			randomChump(void);

private:
	std::string 	_type;
	std::string 	_name;
	static const std::string _names[]; 

};

#endif
