/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:02:40 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/12 13:02:44 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <limits>

void printNoChar( double d ) {
  if (std::numeric_limits<int>::max() == static_cast<int>(d) || std::numeric_limits<int>::min() == static_cast<int>(d))
    std::cout << "int    : Impossible" << std::endl;
  else
    std::cout << "int    : " << static_cast<int>(d) << std::endl;
  std::cout << "float  : " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;

  std::cout << "double : " << static_cast<double>(d) << std::endl;
}


void pImpossible( void ) {
  std::cout << "char   : Impossible" << std::endl;
  std::cout << "int    : Impossible" << std::endl;
  std::cout << "float  : Nanf" << std::endl;
  std::cout << "double : Nan" << std::endl;
}

int main( int ac, char **av ) {

  int       l;
  int       flag = 0;
  int       isF = 0;
  char      *end;
  double    d;

  if (ac == 1) {
    std::cout << "No argument passed" << std::endl;
  } else if (ac == 2) {
    for (int j = 0; j < av[1][j]; j++) {
      if (isalpha(av[1][j])) {
        if (av[1][j] == 'f')
          isF = 1;
        flag += 1;
      }
    }

    d = strtod(av[1], &end);
    l = strlen(av[1]);

    if (l >= 1 && flag <= 1 && isdigit(av[1][0])) {
      if (flag && !isF ) {
        pImpossible();
      } else {
        if (isprint(d))
          std::cout << "char   : '" << static_cast<char>(d) << "'" << std::endl;
        else
          std::cout << "char   : " << "Non displayable" << std::endl;
        printNoChar(d);
      }
    }  else if (l == 1) {
      std::cout << "char   : '" << av[1][0] << "'" << std::endl;
      std::cout << "int    : " << static_cast<int>(av[1][0]) << std::endl;
      std::cout << "float  : " << std::fixed << std::setprecision(1) << static_cast<float>(av[1][0]) << "f" << std::endl;
      std::cout << "double : " << static_cast<double>(av[1][0]) << std::endl;

    } else {
      std::string s1 (av[1]);
      int         fla = 0;
      if (s1.compare("-inff") == 0 || s1.compare("nanf") == 0 || s1.compare("+inff") == 0  )
        fla = 1;
      if (s1.compare("-inf") == 0 || s1.compare("nan") == 0 || s1.compare("+inf") == 0  )
        fla = 2;

      if (fla == 1) {
          s1 = s1.substr(0, l - 1);
      }
      if (fla) {
        std::cout << "char   : Impossible" << std::endl;
        std::cout << "int    : Impossible" << std::endl;
        std::cout << "float  : " << s1 << "f" << std::endl;
        std::cout << "double : " << s1 << std::endl;
      } else if ((flag && !isF) || flag > 1 ){
        pImpossible();
      } else {
        std::cout << "char   : Impossible" << std::endl;
        printNoChar(d);
      }
    }

  } else {
    std::cout << "Too many arguments" << std::endl;
  }

  return ( 0 );
}
