/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:37:02 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 15:37:03 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef HUMANA_H
# define HUMANA_H

class HumanA {

public:
  HumanA( void );
  ~HumanA( void );
  std::string const&     getType( void ) const;
  void                   setType( std::string );

private:
  std::string     type;


};

#endif
