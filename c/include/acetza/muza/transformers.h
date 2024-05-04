#pragma once
#include <stdbool.h>
typedef double (*AzTransformer)(double x);
typedef struct AzTransformReturn {
  double end;
  double last;
  bool disrupted;
} AzTransformReturn;
double AzSmooth(double x);
