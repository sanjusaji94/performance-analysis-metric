#include <stddef.h>

/* dot product */
float dot1(float *x, float *y, size_t n)
{
  size_t i;
  float r=0.0;
  /* -ffast-math is necessary, otherwise this loop cannot be vectorized */
  for (i=0; i<n; i++)
    r += x[i]*y[i];
  return r;
}
