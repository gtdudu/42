/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:03:13 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/07 10:03:14 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int     main( void ) {

  FragTrap claptrap;
  FragTrap a("Gt");
  FragTrap b("Bunnie");
  FragTrap c("Zoe");
  FragTrap const isConst("Anna");
  FragTrap const & e = isConst;
  FragTrap d(e);
  FragTrap j(a);

  a.rangedAttack("Bunnie");
  a.meleeAttack("Bunnie");
  a.takeDamage(110);


  b.takeDamage(35);
  b.beRepaired(15);
  c.meleeAttack("Bunnie");
  b.beRepaired(80);
  b.vaulthunter_dot_exe("Zoe");

  c.meleeAttack("Bunnie");

  c.vaulthunter_dot_exe("Anna");
  d.vaulthunter_dot_exe("Zoe");

  std::cout << std::endl << a << std::endl;

  return ( 0 );
}
