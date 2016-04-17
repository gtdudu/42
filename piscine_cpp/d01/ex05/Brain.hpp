/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:51:49 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 13:51:50 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#ifndef BRAIN_H
# define BRAIN_H

class Brain {

public:

	Brain( void );
	~Brain( void );

  std::string 	identify( void ) const;

private:

	std::string		    _size;

};

#endif
