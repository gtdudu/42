/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:48:44 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/04 14:00:14 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class   Contact {

public:

	Contact( void );
	~Contact( void );

	void 	printContact( void ) const;
	void 	printPreview( int i ) const;
	void 	createContact( void );

private:

	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickName;
	std::string		_login;
	std::string		_postalAdress;
	std::string		_emailAdress;
	std::string		_phoneNumber;
	std::string		_birthdayDate;
	std::string		_favoriteMeal;
	std::string		_underwearColor;
	std::string		_darkestSecret;

	std::string		_format( std::string str) const;

};


class 	Phonebook {

public:

	Phonebook( void );
	~Phonebook( void );

private:

	int const		_maxContact;
	int					_nbContact;
	Contact			store[8];

	void	_addContact( void );
	void 	_getInput( void );
	void	_listContact( void ) const;
	void	_searchContact( void ) const;

};



#endif
