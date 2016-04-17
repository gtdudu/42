/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:12:55 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/13 15:12:57 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
#include <string>
#include <iostream>
#include <exception>



template< typename T >
class   Array {

public:

  Array( void ) : _n( 0 ), _arr(new T[this->size()] ) {
    return;
  };

  Array( unsigned int n ) : _n( n ), _arr(new T[this->size()] ) {
    for (unsigned int i = 0; i < n; i++) {
      this->_arr[i] = T();
      /* code */
    }
    return;
  };


  Array( Array const & src ) {
    *this = src;
    return;
  };

  Array & operator=( Array const & rhs ) {
    if (this != &rhs) {
      this->_n = rhs.size();
      this->_arr = new T[this->_n];
      for (unsigned int i = 0; i < this->_n; i++) {
        this->_arr[i] = rhs[i];
      }
    }
    return *this;
  }

  T		operator[](unsigned int i) const {
		if (i >= this->_n)
			throw std::exception();
		return this->_arr[i];
	}

  T	& 	operator[](unsigned int i) {
		if (i >= this->_n)
			throw std::exception();
		return this->_arr[i];
	}

  unsigned int    size() const {
    return this->_n;
  }

  void            print(std::string n) const {
    std::cout << "array: " << n << std::endl;
    for (unsigned int i = 0; i < this->size(); i++) {
      std::cout << "index: " << i << "  content: "<< this->_arr[i] <<std::endl;
    }
    std::cout << std::endl;
  }

  ~Array( void ) {
    std::cout << "destructor called" << std::endl;
      delete[] this->_arr;
  }

private:

  unsigned int      _n;
  T *               _arr;


};

#endif
