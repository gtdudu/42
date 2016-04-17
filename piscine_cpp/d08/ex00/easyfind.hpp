/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 10:48:08 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/14 10:48:16 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>
#include <exception>

template< typename T >
int      easyfind( T c, int n ) {

  typename T::const_iterator      it;

  it = std::find(c.begin(), c.end(), n);

  if (it == c.end())
    throw std::exception();
  else
    return *it;
}




#endif
