#include <stdio.h>
#include <time.h>
#include "c89spec.h"

/* summary metrics                                                            */
int _c89spec_tests_execs   = 0;
int _c89spec_tests_passed  = 0;
int _c89spec_tests_failed  = 0;

/* profiler global vars                                                       */
clock_t _c89spec_clock_begin;
clock_t _c89spec_clock_end;
double  _c89spec_test_time;

/* Use "summary" to optionally print the final tests counters and             */
/* return the tests final result                                              */
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
