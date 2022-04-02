#include <stdlib.h>
#include <stdio.h>
#include <Steering.hpp>
#include "main.h"
#include "etl/function.h"


etl::ifunction<void>* timer1_callback;   // A pointer to a callback taking no parameters.

void AddMethod() {
  printf("This works.");
}


int main(void) {
  AddMethod();
  exit(0);
}
