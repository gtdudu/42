/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:06:50 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 15:06:51 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef WEAPON_H
# define WEAPON_H

class Weapon {

public:
  Weapon( void );
  ~Weapon( void );
  std::string const&     getType( void ) const;
  void                   setType( std::string );

private:
  std::string     type;


};

#endif
