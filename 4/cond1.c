#include <stddef.h>

void axpy1(float a, float *x, float *y, float * restrict z, size_t n)
{
  size_t i;
  for (i=0; i<n; i++)
    if (x[i]<y[i])
      z[i] += a*x[i];
}
