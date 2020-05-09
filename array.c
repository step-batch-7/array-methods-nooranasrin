#include<stdlib.h>
#include<stdio.h>
#include "array.h"

Array *create_dynamic_array(int length) {
  Array *array = malloc(sizeof(Array));
  array->length = length;
  array->array = malloc(sizeof(int) * array->length);
  return array;
}

Array *create_dynamic_array_from(int *list, int length) {
  Array *array = create_dynamic_array(length);

  for (int index = 0; index < length; index++) {
    array->array[index] = list[index];
  }

  return array;
}

Array *map(Array *list, Mapper operation) {
  Array *mapped_elements = create_dynamic_array(list->length);

  for (int index = 0; index < list->length; index++) {
    int result = operation(list->array[index]);
    mapped_elements->array[index] = result;
  }

  return mapped_elements;
}

Array *filter(Array *list, Predicate predicate) {
  int filtered_elements[list->length];
  int count = 0;

  for (int index = 0; index < list->length; index++)
  {
    if(predicate(list->array[index])) {
      filtered_elements[count++] = list->array[index];
    }
  }

  return create_dynamic_array_from(filtered_elements, count);
};

int reduce(Array *list, int initialContext, Reducer operation) {
  int context = initialContext;
  for(int index = 0; index < list->length; index++) {
    context = operation(context, list->array[index]);
  }
  return context;
};