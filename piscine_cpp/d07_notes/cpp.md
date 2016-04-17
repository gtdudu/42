## templates
fonction/class/structure template <=> modele de code a trous...

```
#include <iostream>

int   max( int x, int y ) {

  return ( x>=y ? x : y );

}

/*  ------------ TEMPLATE ------------*/


template< typename T >
T const &      max( T const & x, T const & y ) {
  return ( x>=y ? x : y );
}

int       foo (int x ) {
  std::cout << "Long computing time" << std::endl;
  return x;
}


int       main ( void ) {

  int a = 21;
  int b = 42;

  std::cout << "Max of" << a << " and " << b << " is ";
  std::cout << max<int>( a , b ) << std::endl;   // Explicit instanciation
  std::cout << "Max of" << a << " and " << b << " is ";
  std::cout << max( a , b ) << std::endl;   // Implicit instanciation


  float c = 21;
  float d = 42;

  std::cout << "Max of" << c << " and " << d << " is ";
  std::cout << max<float>( c , d ) << std::endl;   // Explicit instanciation
  std::cout << "Max of" << c << " and " << d << " is ";
  std::cout << max( c , d ) << std::endl;   // Implicit instanciation

  etc... pas d effet de bord !
}

```

Pour les structures


```

template< typename T >
class   List {

public:

  List<T>( T const & content ) { //... };
  List<T>( List<T> const & content ) { //... };

  ~List<T>( void ) { //... }

private:

  T*          _content;
  List<T> *   _next;


};

int     main( void ) {

  List <int>              a( 42 );
  List <float>            b( 3.14f );
  List < List< int > >    c( a );

}

```
## default types

```
template< typename T = float>
```

et dans le main

```
<>
```

## specializations

template
```
template< typename T, U>
class Pair {
  Pair< T, U>( void ) {
    //...
  }
};
```

partial specialization
```
template< typename U>
class Pair < int, U > {
  Pair< int, U>( void ) {
    //...
  }
};
```

complete specialization
```
template<>
class Pair< bool, bool > {
  Pair< bool, bool>( void ) {
    //...
  }
};
```

main.cpp
```
Pair<int, int>            // partial
Pair<std::string, float>  //generic
Pair<float, bool>         //generic
Pair<bool, bool>          //complete
```
