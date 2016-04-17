/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:08:48 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 10:10:40 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef PONY_H
# define PONY_H

class Pony {

public:

	Pony( std::string n, std::string c );
	~Pony( void );

  void 	getColor( void ) const;

private:

  std::string _name;
	std::string _color;

};

#endif
