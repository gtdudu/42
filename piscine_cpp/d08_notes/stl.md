## standard template library

```
#include <iostream>
#include <map>
#include <vector>
#include <list>

int     main( void ) {

  std::list<int>                      list1;
  std::map<std::string, IOperation*>  map1;
  std::vector<int>                    v1;
  std::vector<int>                    v2(42, 100);


  list1.push_back(1);
  list1.push_back(17);
  list1.push_back(42);

  map1["opA"] = new OperationA;
  map1["opB"] = new OperationB;


  std::list<int>::const_iterator      it;
  std::list<int>::const_iterator      ite = list1.end();


  for (it = list1.begin(); it != ite; ++it) {
    std::cout << *it << std::endl;
  }

  return ( 0 );

}
```

## algorithm

```
#include <iostream>
#include <algorithm>
#include <list>


void    displayInt (int i) {
  std::cout << i << std::endl;
}

int     main( void ) {

  std::list<int>    lst;

  lst.push_back(10);
  lst.push_back(23);
  lst.push_back(3);
  lst.push_back(17);
  lst.push_back(20);

  for_each(lst.begin(), lest.end(), displayInt);

  return ( 0 );

}
```
