/*
Copyright (c) 2013 Ithai Levi

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"), to 
deal in the Software without restriction, including without limitation the 
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in 
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE.
*/

/*
ncspec - TDD mini-framework
-----------------------------------------------------------

usage:

#include <stdio.h>
#include "ncspec.h"
#include "calculator.h"

describe(calculator) {
   it(should_add_two_numbers) {
      assert( 2 == add(1,1) );
   }
   it(should_substract_two_numbers) {
      assert( 1 == sub(2,1) );
   }
}  

int main(int argc, char const *argv[]) {
   test(calculator);
   return 0;
}
*/

#define assert(SCALAR)\
   (SCALAR)\
     ? printf("\r\t\033[1;32m[x]\n")\
     : printf("\r\t\033[1;31m[ ]\n\t\t%s\n",#SCALAR);

#define describe(MODULE) \
   int MODULE()

#define test(MODULE) \
   printf("\033[4m\033[1;34m%s\033[0m\n\n",#MODULE);\
   MODULE();\
   printf("\033[0m\n\n");

#define it(REQUIREMENT)\
   printf("\033[0m\t    %s",#REQUIREMENT);
