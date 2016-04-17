/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:46:21 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 13:46:26 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {

  std::string     str = "HI THIS IS BRAIN";

  std::string*    strPtr = &str;
  std::string&    strRef = str;

  std::cout <<"strPtr: " << *strPtr << std::endl;
  std::cout <<"strRef: " << strRef << std::endl;

  return ( 0 );

}
