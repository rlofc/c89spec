c89spec
=======
TDD mini-framework for ANSI-C

Motivation
----------
After using mocha for Javascript, I looked for a simple
and aesthetic TDD framework for my C code. I wanted my specs
to look clean and readable, so I wrote ncspec, but it relied 
on nested functions, so I revised it and wrote
a simple, ANSI-C compliant version.

Usage
-----

Write your spec:

```C
#include <stdio.h>
#include "c89spec.h"
#include "calculator.h"

describe(calculator) {
   it (should add two numbers) {
      assert( 2 == add(1,1) );
   }
   it (should subtract two numbers) {
      assert( 1 == sub(2,1) );
   }
   it (should multiply two numbers) {
      assert( 5 == mul(2,2) ); // on purpose
   }
   it (should divide two numbers) {
      assert( 2 == div(4,2) );
   }
}  

int main(int argc, char const *argv[]) {
   test(calculator);
   return summary();
}
```

Work your way to the green:

![c89spec result](https://raw.github.com/L3V3L9/c89spec/docs/img/c89spec.jpg)

Configuration
-------------
Define C89SPEC_NO_FANCY_STUFF to disable colors and other formatting.
Redefine C89SPEC_PROFILE_THRESHOLD to change the max allowed time per "it" in seconds.milliseconds (default is 1.00).

