#include <stddef.h>

void axpy1(float a, float *x, float *y,
           float *z, float *w, float *v,
           size_t n)
{
  size_t i;
  for (i=0; i<n; i++) {
    z[i] += a*x[i];
    w[i] = x[i]+y[i];
    v[i] = x[i]*z[i];
  }
}
