#include<stdio.h>
#include<stdlib.h>
#include "array.h"
#include "array_void.h"

int get_square(number) {
  return number * number;
}

Bool is_odd(number) {
  return number % 2 != 0 ? True : False;
}

int get_sum(sum, number) {
  return sum + number;
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
  numbers->array[4] = 15;
  Array *squares = map(numbers, &get_square);
  display_dynamic_array(squares);
  printf("\n");
  Array *odds = filter(numbers, &is_odd);
  display_dynamic_array(odds);
  printf("\n");
  int sum = reduce(numbers, 0, &get_sum);
  printf("The sum is %d\n", sum);

  ArrayVoid *array = create_array_void(5);
  array->array[0] = (int *)1;
  array->array[1] = (int *)2;
  array->array[2] = (int *)3;
  array->array[3] = (int *)4;
  array->array[4] = (int *)5;
  return 0;
}