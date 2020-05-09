#include<stdio.h>
#include<stdlib.h>
#include "array.h"
#include "array_void.h"

int get_square(int number) {
  return number * number;
}

Bool is_odd(int number) {
  return number % 2 != 0 ? True : False;
}

int get_sum(int sum, int number) {
  return sum + number;
}

Object add(Object sum, Object number) {
  int total = *(int *)sum + *(int *)number;
  return (sum = &total);
}

void display_dynamic_array(Array *list) {
  for (int index = 0; index < list->length; index++) {
    printf("%d\n", list->array[index]);
  }
} 

int main() {
  Array *numbers = create_dynamic_array(5);
  numbers->array[0] = 1;
  numbers->array[1] = 2;
  numbers->array[2] = 3;
  numbers->array[3] = 4;
  numbers->array[4] = 5;
  Array *squares = map(numbers, &get_square);
  display_dynamic_array(squares);
  printf("\n");
  Array *odds = filter(numbers, &is_odd);
  display_dynamic_array(odds);
  printf("\n");
  int sum = reduce(numbers, 0, &get_sum);
  printf("The sum is %d\n", sum);

  ArrayVoid_ptr array = create_array_void(5);
  array->array[0] = &numbers->array[0];
  array->array[1] = &numbers->array[1];
  array->array[2] = &numbers->array[2];
  array->array[3] = &numbers->array[3];
  array->array[4] = &numbers->array[4];
  int context = 0;
  Object result = reduce_void(array, &context, &add);
  printf("The void sum : %d\n", *(int *)result);
  return 0;
}