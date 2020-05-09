#include<stdio.h>
#include<stdlib.h>
#include "test_array.h"
#include "../array.h"

int sum(num1, num2) {
  return num1 + num2;
}

int increment(num) {
  return num + 1;
}

Bool is_odd(number) {
  return number % 2 != 0;
}


void test_empty_array_for_reduce() {
  Array *numbers = create_dynamic_array(1);
  char description[] = "Should give the initial context when the array is empty\n";
  int actual = reduce(numbers, 0, &sum);
  assert_equal(0, actual, description);
}

void test_non_empty_array_for_reduce() {
  Array *numbers = create_dynamic_array(2);
  numbers->array[0] = 9;
  numbers->array[1] = 18;
  char description[] = "Should give the sum of elements when the array is not empty\n";
  int actual = reduce(numbers, 0, &sum);
  assert_equal(27, actual, description);
}

void run_tests_for_reduce() {
  printf("---------------reduce-------------\n");
  test_empty_array_for_reduce();
  test_non_empty_array_for_reduce();
  printf("\n");
}

void test_empty_array_for_map() {
  Array *numbers = create_dynamic_array(0);
  char description[] = "Should give the an empty list when the array is empty\n";
  Array *actual = map(numbers, &increment);
  Array *expected = create_dynamic_array(0);
  assert_array_equal(expected, actual, description);
}

void test_non_empty_array_for_map() {
  Array *numbers = create_dynamic_array(2);
  numbers->array[0] = 9;
  numbers->array[1] = 18;
  char description[] = "Should give the incremented values of all the elements\n";
  Array *actual = map(numbers, &increment);
  Array *expected = create_dynamic_array(2);
  expected->array[0] = 10;
  expected->array[1] = 19;
  assert_array_equal(expected, actual, description);
}

void run_tests_for_map() {
  printf("---------------map-------------\n");
  test_empty_array_for_map();
  test_non_empty_array_for_map();
  printf("\n");
}

void test_empty_array_for_filter() {
  Array *numbers = create_dynamic_array(0);
  char description[] = "Should give the an empty list when the array is empty\n";
  Array *actual = filter(numbers, &is_odd);
  Array *expected = create_dynamic_array(0);
  assert_array_equal(expected, actual, description);
}

void test_non_empty_array_for_filter() {
  Array *numbers = create_dynamic_array(2);
  numbers->array[0] = 9;
  numbers->array[1] = 18;
  char description[] = "Should give the incremented values of all the elements\n";
  Array *actual = filter(numbers, &is_odd);
  Array *expected = create_dynamic_array(1);
  expected->array[0] = 9;
  assert_array_equal(expected, actual, description);
}

void run_tests_for_filter() {
  printf("---------------filter-------------\n");
  test_empty_array_for_filter();
  test_non_empty_array_for_filter();
  printf("\n");
}