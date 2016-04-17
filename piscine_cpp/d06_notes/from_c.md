
## 00: type_conversion

le c propose 2 cast: explicit / implicit

```
int a = 42

double b = a;                 // implicit cast
double c = (double)a          // explicit cast

double d = a                  // implicit promotion -> ok
int e = d;                    // implicit demotion -> hazardous
int f = (int)d                // expicit demotion -> ok, you re in charge
```


## 01: type reinterpretation

Toujours la meme notion de hierarchie.

```
float a = 420.042f;

void *b = &a;                 /* implicit reinterpretation cast */
void *c = (void *)&a          /* explicit reinterpretation cast */

void *d = &a;                 /* implicit propomotion -> ok */
int *e  = d;                  /* implicit demotion -> hazardous */
int *f  = (int *)d;           /* explicit demotion -> ok, why not..*/
```

## 02: type qualifier reinterpretation

```
int a = 42;

int const * b = &a;                 /* Implicit type qualifier cast   */
int const * c = (int const *) &a;   /* Implicit type qualifier cast   */

int const *d = &a;                  /* implicit propomotion -> ok */
int * e = d;                        /* implicit demotion -> doesnt compile */
int  f = (int *)d;                  /* explicit demotion -> ok, why not..*/

```
