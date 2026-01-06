#include <stddef.h>

void axpy1(float a, float *x, float * restrict y, size_t n)
{
  size_t i;
  
#ifdef __clang__
#pragma clang loop vectorize(disable)
#endif
  for (i=0; i<n; i++)
    y[i] += a*x[i];
}
