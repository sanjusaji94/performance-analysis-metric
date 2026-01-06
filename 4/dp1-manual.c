#include <stddef.h>
#include <string.h>

typedef float v16f __attribute__ ((vector_size (64)));
typedef float v8f __attribute__ ((vector_size (32)));
typedef float v4f __attribute__ ((vector_size (16)));
typedef float v2f __attribute__ ((vector_size (8)));

void axpy1(float a, float *x, float * restrict y, size_t n)
{
  size_t i;
  for (i=0; i+15<n; i+=16) {
    v16f vx, vy;
    /* gcc (at least) requires 64-byte-aligned memory accesses to
       v16f; the following memcpy() calls allow arbitrary alignment
       and are optimized appropriately by gcc and clang */
    memcpy(&vx,&x[i],sizeof(vx));
    memcpy(&vy,&y[i],sizeof(vy));
    vy += a * vx;
    memcpy(&y[i],&vy,sizeof(vy));
  }
#if 1
  /* This is auto-vectorized, unfortunately not by using AVX-512 with masks */
  for (; i<n; i++)
    y[i] += a*x[i];
#else
  /* If we also want to manually vectorize processing the remaining
     elements, here's code for that, that produces similar code to the
     auto-vectorization of the code above */
  if (i+7<n) {
    v8f vx, vy;
    memcpy(&vx,&x[i],sizeof(vx));
    memcpy(&vy,&y[i],sizeof(vy));
    vy += a * vx;
    memcpy(&y[i],&vy,sizeof(vy));
    i+=8;
  }
  if (i+3<n) {
    v4f vx, vy;
    memcpy(&vx,&x[i],sizeof(vx));
    memcpy(&vy,&y[i],sizeof(vy));
    vy += a * vx;
    memcpy(&y[i],&vy,sizeof(vy));
    i+=4;
  }
  if (i+1<n) {
    v2f vx, vy;
    memcpy(&vx,&x[i],sizeof(vx));
    memcpy(&vy,&y[i],sizeof(vy));
    vy += a * vx;
    memcpy(&y[i],&vy,sizeof(vy));
    i+=2;
  }
  if (i<n) {
    y[i] += a*x[i];
  }
#endif
}
