#include "acetza/assert.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
void AzAssert(bool condition, int code, const char *message, ...) {
  if (condition) return;
  printf("Assertion failed\n->Message: ");
  va_list args;
  va_start(args, message);
  vprintf(message, args);
  va_end(args);
  printf("\nExit with code %i\n", code);
  exit(code);
}
