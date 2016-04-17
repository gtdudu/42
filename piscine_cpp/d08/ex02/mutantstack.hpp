/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:50:33 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/14 16:50:34 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// https://github.com/Ngoguey42/piscine_cpp/tree/master/j08_STL/ex02
#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>
#include <iterator>

template <typename T>
class   MutantStack : public std::stack<T> {

public:
  MutantStack( void ) { return; };
  ~MutantStack( void ) { return; };

  class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {

  public:
    iterator( void ) { return; };


    iterator( MutantStack<T>::iterator const & src ) {
      *this = src;
      return;
    };

    MutantStack<T>::iterator    operator=(MutantStack<T>::iterator const & rhs){
      if (this != &rhs) {
        this->_top = rhs.getPtr();
      }
      return *this;
    }

    MutantStack<T>::iterator &   operator++( void ) {
      this->_top++;
      return *this;
    }

    MutantStack<T>::iterator     operator++( int ) {
      MutantStack<T>::iterator   tmp(*this);
      this->_top++;
      return ( tmp );
    }

    MutantStack<T>::iterator &  operator--( void ) {
      this->_top--;
      return *this;
    }

    MutantStack<T>::iterator     operator--( int ) {
      MutantStack<T>::iterator    tmp(*this);

      this->_top -= 1;
      return tmp;
    }

    T    operator*( void ) {
      return *(this->_top);
    }


    void savePtr( T * ptr) {
      this->_top = ptr;
    }


    T * getPtr( void ) const {
      return this->_top;
    }

  private:
    T *   _top;

  };


  MutantStack<T>::iterator     begin( void ) {
    MutantStack<T>::iterator    it;
    if (this->size()) {
      it.savePtr(&(this->top()));
      std::advance(it, -this->size() + 1);
    } else {
      it.savePtr(NULL);
    }
    return it;
  };




private:
    MutantStack( MutantStack const & src) { *this = src; return; };
    MutantStack &   operator=(MutantStack const & rhs) { static_cast<void>(rhs); return *this; }
};

#endif
