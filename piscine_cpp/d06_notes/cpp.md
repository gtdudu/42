## upcast and downcast

```
class Parent                       {};
class Child1: public Parent        {};
class Child2: public Parent        {};

Child1      a;

Parent *    b = &a;                 //Implicit reinterpretation cast
Parent *    c = (Parent *)&a;       //Explicit reinterpretation cast

Parent *    d = &a;                 // Implicit upcast -> Ok
Child1 *    e = d;                  // Implicit downcast -> Hell no
Child2 *    f = (Child2 *) d        //Explicit downcast -> ok, but really ?

```

## static cast

```
int       a = 42;

double    b = a;                    // Implicit promotion -> ok
int       c = b;                    // Implicit demotion -> hell no
int       d = static_cast<int>(b)   // Explicit demotion -> ok
```

```
class Parent                       {};
class Child1: public Parent        {};
class Child2: public Parent        {};

class Unrelated                    {};


Child1        a;

Parent *      b = &a;                             // Implicit upcast -> ok
Child1 *      c = b;                              // Implicit downcast -> no way
Child2 *      d = static_cast<Child2 *>(b);       // Explicit downcast ->ok...

Unrelated *   e = static_cast<Unrelated *>(&a);   //Explicit conversion -> no
```

## Dynamic cast
// rtti activé ( run time type information)

```
class Parent                       { public: virtual ~Parent( void ){} };
class Child1: public Parent        {};
class Child2: public Parent        {};

Child1        a;
Parent *      b = &a;                //Implicit upcast -> ok


//Explicit downcast by pointers
Child1 *      c = dynamic_cast<Child1 *>(b);
if ( c == NULL ) {
  std::cout << "conversion is NOT ok " << std::endl;
} else {
  std::cout << "conversion is ok " << std::endl;
}

//Explicit downcast by reference
try {
  Child2 &    d = dynamic_cast<Child2 &>(*b);
  std::cout << "Conversion is OK" << std::endl;
}
catch (std::bad_cast &bc){
  std::cout << "Conversion is NOT Ok" << bc.what()<< std::endl;
}
```

## Reinterpret cast

```
float       a = 420.042f

void *      b = &a;                           // Implicit promotion -> ok
int *       c = reinterpret_cast<int *>(b);   // okey, i obey
int &       d = reinterpret_cast<int &>(b);   // okey, i obey

```

## Const cast

```
int             a = 42;

int const *     b = &a;                         // Implicit promotion -> ok
int *           c = b;                          // Implicit demotion -> hell no
int *           d = const_cast<int *>(b);       // Explicit demotion -> ok, i obey
```


## cast operators

```

class Foo {

public:
  foo ( float const v) : _v( v ) {};

  float     getV( void )          { return this->_v; }

  operator float()                { return this->_v; }
  operator int()                  { return static_cast<int>( this->_v ); }

private:

  float   _v;

}


Foo       a( 420.024f );
float     b = a;
int       c = a;


std::cout << a.getv() << std::endl;
std::cout << b << std::endl;
std::cout << c << std::endl;
```

## Explicit keyword

```
class A {};
class B {};

class C {

public:

             C( A const & _ ) { return; }
  explicit   C( B const & _ ) { return; }

};


void    f ( C const & _ ) {

  return;
}

int     main( void ) {

  f( A() );  // Implicit conversion OK
  f( B() );  // Implicit conversion NOT ok, constructor is explicit

  return 0;
}

```

## Conclusion

```
------------------------------------------------------------------------------
  Cast            |  Conv.  |   Reint.  |   Upcast  | downcast |  Type qual
------------------------------------------------------------------------------
Implicit          |   yes   |           |    yes    |           |           |
static_cast       |   yes   |           |    yes    |    yes    |           |
dynamic_cast      |         |           |    yes    |    yes    |           |
const_cast        |         |           |           |           |    yes    |
reinterpret_cast  |         |     yes   |    yes    |    yes    |           |
------------------------------------------------------------------------------
Legacy C cast     |   yes   |    yes    |    yes    |    yes    |    yes    |
------------------------------------------------------------------------------


------------------------------------------------------------------------------
  Cast            |   semantic_check  |  reliable at run  |  tested at run
------------------------------------------------------------------------------
Implicit          |         yes       |         yes       |                   |
static_cast       |         yes       |                   |                   |
dynamic_cast      |         yes       |         yes       |         yes       |
const_cast        |                   |                   |                   |
reinterpret_cast  |                   |                   |                   |
------------------------------------------------------------------------------
Legacy C cast     |                   |                   |                   |
------------------------------------------------------------------------------
```
