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

Object increment(Object number) {
  int *num = malloc(sizeof(int));
  *num = *(int *)number + 1;
  return num;
}

void display_dynamic_array(Array *list) {
  for (int index = 0; index < list->length; index++) {
    printf("%d\n", list->array[index]);
  }
} 

void display_int_array(ArrayVoid_ptr list) {
  for (int index = 0; index < list->length; index++) {
    printf("%d\n", *(int *)list->array[index]);
  }
} 

int main() {
  Array *numbers = create_dynamic_array(5);
  numbers->array[0] = 1;
  numbers->array[1] = 2;
  numbers->array[2] = 3;
  numbers->array[3] = 4;
  numbers->array[4] = 15;
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
  ArrayVoid_ptr incremented_numbers = map_void(array, &increment);
  display_int_array(incremented_numbers);
  Object result = reduce_void(array, &context, &add);
  printf("The void sum : %d\n", *(int *)result);
  return 0;
}