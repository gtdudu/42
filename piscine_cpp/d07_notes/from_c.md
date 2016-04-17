## parametric macros

Probleme de l effet de bord.

```

#include <stdio.h>


// long et relou
int     max_int ( int x, int y ) { return ( x>=y ? x : y ); }
float     max_float ( float x, float y ) { return ( x>=y ? x : y ); }
char     max_char ( char x, char y ) { return ( x>=y ? x : y ); }


int     foo( int x ) { printf( " Long computing time\n"); return x; }


// macro parametric
#define max(x, y)       ( ((x)>=(y)) ? (x) : (y) )


int   main( void ) {

  int a = 21;
  int b = 42;

  printf( "Max of %d and %d is %d\n", a, b, max_int( a, b ) );
  printf( "Max of %d and %d is %d\n", a, b, max( a, b ) );


  float c = -1.7f;
  float d = 4.2f;

  printf( "Max of %f and %f is %f\n", c, d, max_float( a, b ) );
  printf( "Max of %f and %f is %f\n", c, d, max( a, b ) );



  char e = 'a';
  char f = 'z';

  printf( "Max of %s and %s is %s\n", e, f, max_char( e, f ) );
  printf( "Max of %s and %s is %s\n", e, f, max( e, f ) );

  /* But......
   effet de bord !! au final a cause de la macro,  foo() est appelé 3 fois !
  */

  printf( "Max of %d and %d is %d\n", a, b, max_int( foo(a), foo(b) ) );
  printf( "Max of %d and %d is %d\n", a, b, max( foo(a), foo(b) ) );

}


```


Cas des listes chainees..

solution 1 : une structure par type puis une fonction pour traiter chaque type...

solution 2 : une structure qui contient un void * + la taille de l element.. ( oblige a dereference puor acceder a la donnee.. )

solution 3: header linux liste chainee
