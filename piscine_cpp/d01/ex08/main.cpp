/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 16:51:09 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/06 16:51:11 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>

int   main() {

  Human jim;

  jim.action("rangedAttack", "bob");
  jim.action("intimidatingShout", "bob");
  jim.action("meleeAttack", "bob");


  return ( 0 );
}
