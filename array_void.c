#include<stdio.h>
#include<stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_void(int length) {
  ArrayVoid *array = malloc(sizeof(ArrayVoid));
  array->length = length;
  array->array = malloc(sizeof(Object) * array->length);
  return array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer) {
  Object context = init;
  for(int index = 0; index < src->length; index++) {
    context = reducer(context, src->array[index]);
  }
  return context;
}
