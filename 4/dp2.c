#include <stddef.h>

void axpy1(float a, float *x, float * restrict y, size_t n)
{
  size_t i;
  for (i=1; i<n; i++) {
    x[i] = x[i - 1] * (float)n;   // loop-carried dependency
    y[i] += a * x[i];
  }
}