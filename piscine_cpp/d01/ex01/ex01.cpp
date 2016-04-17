/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:47:05 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/05 10:59:31 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void  memoryLeak() {

	std::string* 		panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;

	delete panthere;

}
