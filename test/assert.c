#include<stdio.h>
#include "test_array.h"
#include "../array.h"

void assert_equal(int expectedValue, int actualValue, char *message) {
  char symbol[] = "✅";

  if(expectedValue != actualValue ) {
    char error_symbol[] = "❌";
    printf("%s %s  * Expected -> %d\n  * Got -> %d\n",error_symbol, message, expectedValue, actualValue);
    return;
  }

  printf("%s %s",symbol, message);
}

Bool are_arrays_equal(Array *expectedValue, Array *actualValue) {
  if(expectedValue->length != actualValue->length) {
    return False;
  }

  for(int index = 0; index < expectedValue->length; index++) {
    if(expectedValue->array[index] != actualValue->array[index]) {
      return False;
    }
  }

  return True;
};

void assert_array_equal(Array *expectedValue, Array *actualValue, char *message) {
  char symbol[] = "✅";

  if(!are_arrays_equal(expectedValue, actualValue) ) {
    char error_symbol[] = "❌";
    printf("%s %s",error_symbol, message);
    return;
  }

  printf("%s %s",symbol, message);
}