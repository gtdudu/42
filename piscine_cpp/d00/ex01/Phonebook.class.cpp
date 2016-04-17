/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:52:55 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/04 13:54:42 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <limits>

#include "Phonebook.class.hpp"


// CONTACT
Contact::Contact( void ) {
	return;
}

Contact::~Contact( void ) {
	return;
}

void 	Contact::createContact( void ) {

	std::string buff;

	std::cout << "Please enter your first name: " << std::endl;
	std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
	std::getline (std::cin,this->_firstName);

	std::cout << "Please enter your last name: " << std::endl;
	std::getline (std::cin,this->_lastName);

	std::cout << "Please enter your nick name: " << std::endl;
	std::getline (std::cin,this->_nickName);

	std::cout << "Please enter your login: " << std::endl;
	std::getline (std::cin,this->_login);

	std::cout << "Please enter your postal adress: " << std::endl;
	std::getline (std::cin,this->_postalAdress);

	std::cout << "Please enter your email adress: " << std::endl;
	std::getline (std::cin,this->_emailAdress);

	std::cout << "Please enter your phone number: " << std::endl;
	std::getline (std::cin,this->_phoneNumber);

	std::cout << "Please enter your birthday date: " << std::endl;
	std::getline (std::cin,this->_birthdayDate);

	std::cout << "Please enter your favorite meal " << std::endl;
	std::getline (std::cin,this->_favoriteMeal);

	std::cout << "Please enter your underwear color: " << std::endl;
	std::getline (std::cin,this->_underwearColor);

	std::cout << "Please enter your darkest secret: " << std::endl;
	std::getline (std::cin,this->_darkestSecret);

	return;
}

void 	Contact::printContact( void ) const {

	std::cout << this->_firstName << std::endl;
	std::cout << this->_lastName << std::endl;
	std::cout << this->_nickName << std::endl;
	std::cout << this->_login << std::endl;
	std::cout << this->_postalAdress << std::endl;
	std::cout << this->_emailAdress << std::endl;
	std::cout << this->_phoneNumber << std::endl;
	std::cout << this->_birthdayDate << std::endl;
	std::cout << this->_favoriteMeal << std::endl;
	std::cout << this->_underwearColor << std::endl;
	std::cout << this->_darkestSecret << std::endl;
	return;
}

std::string		Contact::_format( std::string str ) const {

	std::string 	tmp;

	if (str.length() >= 8) {
		tmp = str.substr(0, 7) + '.';
	} else {
		tmp = str;
	}
	return tmp;
}


void 	Contact::printPreview( int i ) const {

	std::cout << std::setw(10);
	std::cout << i << " | ";
	std::cout << std::setw(10);
	std::cout << this->_format(this->_firstName)  << " | ";
	std::cout << std::setw(10);
	std::cout << this->_format(this->_lastName) << " | ";
	std::cout << std::setw(10);
	std::cout << this->_format(this->_nickName) << " | ";
	std::cout << std::setw(10);
	std::cout << this->_format(this->_login) << std::endl;
	return;
}



// PHONE BOOK
Phonebook::Phonebook( void ) : _maxContact( 8 ), _nbContact( 0 ) {

	this->_getInput();
	return;
}

Phonebook::~Phonebook( void ) {

	return;
}


void 	Phonebook::_listContact( void ) const {

	std::string str;
	int 				nb;

	if (this->_nbContact == 0) {
		std::cout << "You didn't add a contact yet !" << std::endl;
	}

	for (size_t i = 0; i < this->_nbContact; i++) {
		this->store[i].printPreview(i);
	}

	if (this->_nbContact > 0) {
		std::cout << std::endl;
		std::cout << "Enter an index to view the full contact: " << std::endl;
		std::cin >> str;
		nb = -1;
		try {
			nb = std::stoi (str,nullptr);
		}
		catch(std::invalid_argument)  {
			std::cout << "Invalid index." << std::endl;
		}
		if (nb >= 0) {
				if (nb < this->_nbContact) {
					this->store[nb].printContact();
				} else {
					std::cout << "Invalid index." << std::endl;
				}
		}

	}
	return;

}

void 	Phonebook::_searchContact( void ) const {

	std::cout << "Searching" << std::endl;
	return;
}

void 	Phonebook::_addContact( void ){

	this->store[this->_nbContact].createContact();
	this->_nbContact += 1;
	return;

}

void 	Phonebook::_getInput( void )  {

	char    			buff[512];
	std::string		sExit ("EXIT");
	std::string		sSearch ("SEARCH");
	std::string		sAdd ("ADD");

	std::cout << "What do you wanna do ? (EXIT, ADD, SEARCH) " << std::endl;
	std::cin >> buff;

	if (sExit.compare(std::string(buff)) == 0) {
		std::cout << "Goodbye" << std::endl;
		return;
	}
	else if (sSearch.compare(std::string(buff)) == 0) {
		this->_listContact();
	}
	else if (sAdd.compare(std::string(buff)) == 0) {
		if (this->_nbContact == 8) {
			std::cout << "You already have 8 contacts..";
		} else {
			this->_addContact();
		}
	}
	this->_getInput();
	return;
}
