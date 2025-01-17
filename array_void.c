#include<stdio.h>
#include<stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_void(int length) {
  ArrayVoid *array = malloc(sizeof(ArrayVoid));
  array->length = length;
  array->array = malloc(sizeof(Object) * array->length);
  return array;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate) {
  ArrayVoid_ptr filtered_elements = create_array_void(src->length);
  int count = 0;

  for (int index = 0; index < src->length; index++)
  {
    if(predicate(src->array[index])) {
      filtered_elements->array[count++] = src->array[index];
      filtered_elements->length = count;
    }
  }
  return filtered_elements;
};

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper) {
  ArrayVoid_ptr mapped_elements = create_array_void(src->length);

  for (int index = 0; index < src->length; index++) {
    mapped_elements->array[index] = mapper(src->array[index]);
  }

  return mapped_elements;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer) {
  Object context = init;
  for(int index = 0; index < src->length; index++) {
    context = reducer(context, src->array[index]);
  }
  return context;
}
