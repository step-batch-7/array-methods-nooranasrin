#include <stdio.h>
#include "test_array.h"

int main(void) {
  run_tests_for_reduce();
  run_tests_for_map();
  run_tests_for_filter();
  return 0;
}