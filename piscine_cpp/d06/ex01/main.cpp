/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:12:36 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/12 18:12:38 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data {
  std::string s1;
  int n;
  std::string s2;
};

// a refaire ! renvois juste une putain de structure et c est regle...


void * serialize( void ) {
  std::string     *s = new std::string("hdjlspei");
  std::string     part2("arghtyup");
  int             randomInt;
  int *           ptr;
  char *          c;
  // int             rIndex;

  std::string alphnum ("abcdefghijlmnopqrstuvwxyz0123456789");
  //
  // for (int i = 0; i < 8; i++) {
  //   rIndex = rand() % 30;
  //   part1 += alphnum[rIndex];
  // }

  randomInt = 42;
  ptr = &randomInt;
  c = reinterpret_cast<char*>(ptr);

  s->append(c).append(part2);
  //
  // for (int i = 0; i < 8; i++) {
  //   rIndex = rand() % 34;
  //   part2 += alphnum[rIndex];
  // }

  std::cout << s->length() << std::endl;

  return reinterpret_cast<void *>(s);
}

Data * deserialize( void * raw ) {

  Data *          d = 0;
  std::string     tmp;

  std::string *s = reinterpret_cast<std::string *>(raw);
  d->s1 = s->substr(0, 8);
  d->s2 = s->substr(s->end() - 8, 8);
  // d->n = *(reinterpret_cast<int*>(s->substr(8, 9)));


  tmp = s->erase(s->end() - 8, 8);
  tmp = s->erase(0, 8);


  const char *cstr = tmp.c_str();

  const int * i = reinterpret_cast<const int *>(cstr);

  std::cout << i << std::endl;
  d->s1 = s->substr(0, 8);
  // d->n = *(reinterpret_cast<int*>(s->substr(8, 9)));
  d->s2 = s->substr(s->length() - 8, 8);
  //
  // for(std::string::size_type i = 0; i < s->size(); ++i) {
  //     std::cout << s[i];
  // }

  return d;
}


int   main( void ) {
  srand (time(NULL));

  void * data;
  Data * st;

  data = serialize();
  st = deserialize(data);

  return ( 0 );

}
