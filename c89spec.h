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
   return summary();
}
*/
int _c89spec_tests_execs   = 0;
int _c89spec_tests_passed  = 0;
int _c89spec_tests_failed  = 0;

#ifdef C89SPEC_NO_FANCY_STUFF
static const char * _C89SPEC_NO_COLOR    = "";
static const char * _C89SPEC_UNDERSCORE  = "";
static const char * _C89SPEC_RED_COLOR   = "";
static const char * _C89SPEC_GREEN_COLOR = "";
static const char * _C89SPEC_BLUE_COLOR  = "";
#else
static const char * _C89SPEC_NO_COLOR    = "\033[0m";
static const char * _C89SPEC_UNDERSCORE  = "\033[4m";
static const char * _C89SPEC_RED_COLOR   = "\033[1;31m";
static const char * _C89SPEC_GREEN_COLOR = "\033[1;32m";
static const char * _C89SPEC_BLUE_COLOR  = "\033[1;34m";
#endif

#define assert(SCALAR) \
   (SCALAR) \
     ? printf("\r\t%s[x]\n",_C89SPEC_GREEN_COLOR) \
     : printf("\r\t%s[ ]\n\t\t%s\n",_C89SPEC_RED_COLOR \
                                   ,#SCALAR); \
   (SCALAR) \
     ? _c89spec_tests_passed++ \
     : _c89spec_tests_failed++;

#define describe(MODULE) \
   int MODULE()

#define test(MODULE) \
   printf("%s%s%s%s\n\n",_C89SPEC_UNDERSCORE \
                        ,_C89SPEC_BLUE_COLOR \
                        ,#MODULE \
                        ,_C89SPEC_NO_COLOR); \
   MODULE(); \
   printf("%s\n\n",_C89SPEC_NO_COLOR);

#define it(REQUIREMENT) \
   _c89spec_tests_execs++; \
   printf("%s\t[?] %s",_C89SPEC_NO_COLOR \
                      ,#REQUIREMENT);


int summary() {
   printf ("Total: %s%d%s\n",_C89SPEC_BLUE_COLOR
                            ,_c89spec_tests_execs
                            ,_C89SPEC_NO_COLOR);

   printf ("\tPassed: %s%d%s\n",_C89SPEC_GREEN_COLOR
                               ,_c89spec_tests_passed
                               ,_C89SPEC_NO_COLOR);

   printf ("\tFailed: %s%d%s\n",_c89spec_tests_failed 
                                  ? _C89SPEC_RED_COLOR
                                  : _C89SPEC_GREEN_COLOR
                               ,_c89spec_tests_failed
                               ,_C89SPEC_NO_COLOR);
   printf ("\n");
   return _c89spec_tests_failed;
}
