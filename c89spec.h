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

#ifndef C89SPEC_H_SC604JRD
#define C89SPEC_H_SC604JRD

/* profiler threshold                                                         */
#ifndef C89SPEC_PROFILE_THRESHOLD
#define C89SPEC_PROFILE_THRESHOLD 1.00                          /* in seconds */
#endif

/* MACRO and function definitions of c89spec:                                 */
/* -----------------------------                                              */
/* describe({module_name})                                                    */
/* it({module responsibility})                                                */
/* assert({scalar})                                                           */
/* test({module_name})                                                        */
/* summary()                                                                  */

/* "describe" encapsulates a set of "it" clauses in a function                */
/* MODULE should be a valid C function literal                                */
#define describe(MODULE) \
   void MODULE()

/* "assert" tests the passed scalar, and prints the result and time.          */
/* You can have several assert tests declared in a single "it" clause but     */
/* only one assert can be executed during the test.                           */
#define assert(SCALAR) \
   _c89spec_end_it(); \
   (SCALAR) ? _c89spec_assert_passed() \
            : _c89spec_assert_failed(#SCALAR);

/* "it" encapsulates a single test in a curly block.                          */
/* REQUIREMENT can be anything that's valid as string.                        */
#define it(REQUIREMENT) \
   _c89spec_begin_it(#REQUIREMENT);

/* "test" invokes a "describe" clause.                                        */
#define test(MODULE) \
   _c89spec_test_module(#MODULE,MODULE);

/* Use "summary" to optionally print the final tests counters and             */
/* return the tests final result                                              */
int summary();

/* private functions                                                          */
void _c89spec_test_module(const char * module,void (*func)());
void _c89spec_begin_it(const char * requirement);
void _c89spec_end_it();
void _c89spec_assert_passed();
void _c89spec_assert_failed(const char * scalar);

#endif /* end of include guard: C89SPEC_H_SC604JRD */
