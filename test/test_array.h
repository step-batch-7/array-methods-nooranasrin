#ifndef __ARRAY_TEST_
#define __ARRAY_TEST_
#include "../array.h"

void assert_equal(int expectedValue, int actualValue, char *message);
void run_tests_for_reduce();
void test_empty_array_for_reduce();
void test_non_empty_array_for_reduce();
void run_tests_for_map();
void test_empty_array_for_map();
void test_non_empty_array_for_map();
void run_tests_for_filter();
void test_empty_array_for_filter();
void test_non_empty_array_for_filter();
void assert_array_equal(Array *expectedValue, Array *actualValue, char *message);

#endif