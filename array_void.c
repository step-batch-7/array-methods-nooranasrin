#include<stdio.h>
#include<stdlib.h>
#include "array_void.h"

ArrayVoid* create_array_void(int length) {
  ArrayVoid *array = malloc(sizeof(ArrayVoid));
  array->length = length;
  array->array = malloc(sizeof(Object) * array->length);
  return array;
}