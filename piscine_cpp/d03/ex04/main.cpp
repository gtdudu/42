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

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int     main( void ) {

  ClapTrap  x;
  FragTrap  y;
  ScavTrap  z;
  NinjaTrap w;
  SuperTrap v;


  std::cout << std::endl << "ClapTrap: " << std::endl << x << std::endl;
  std::cout << std::endl << "FragTrap: " << std::endl << y << std::endl;
  std::cout << std::endl << "ScavTrap: " << std::endl << z << std::endl;
  std::cout << std::endl << "NinjaTrap: " << std::endl << w << std::endl;
  std::cout << std::endl << "SuperTrap: " << std::endl << v << std::endl;
  v.vaulthunter_dot_exe("ScavTrap");
  std::cout << std::endl << "NinjaTrap: " << std::endl << w << std::endl;

  w.ninjaShoebox(z);
  std::cout << std::endl << "NinjaTrap: " << std::endl << w << std::endl;

  w.ninjaShoebox(w);
  std::cout << std::endl << "NinjaTrap: " << std::endl << w << std::endl;



  FragTrap claptrap;
  FragTrap a("Gt");
  FragTrap b("Bunnie");
  FragTrap c("Zoe");
  FragTrap const isConst("Anna");
  FragTrap const & e = isConst;
  FragTrap d(e);

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
  d.vaulthunter_dot_exe("Zoe");
  d.vaulthunter_dot_exe("Zoe");
  std::cout << std::endl << a << std::endl;


  ScavTrap scavtrap;
  ScavTrap g("Gt");
  ScavTrap h("Bunnie");
  ScavTrap i("Zoe");
  ScavTrap j(g);

  std::cout << std::endl << scavtrap << std::endl;
  h.rangedAttack("Gt");
  h.meleeAttack("Gt");
  h.takeDamage(110);
  i.takeDamage(35);
  i.beRepaired(15);
  j.meleeAttack("Bunnie");
  i.beRepaired(80);
  i.challengeNewComer("Bunnie");
  j.meleeAttack("Bunnie");
  j.challengeNewComer("Anna");
  g.challengeNewComer("Zoe");

  return ( 0 );
}
