#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

extern void axpy1(float a, float *x, float * restrict y, size_t n);

#define N 1000

unsigned long hash(char *a, size_t n)
{
  size_t i;
  unsigned long r=0;
  for (i=0; i<n; i++) {
    r += a[i];
    r = r*0x96906d7e52553935L;
    r = (r<<27)|(r>>37);
  }
  return r;
}

int main()
{
  float y[N];
  float x[2*N];
  float z[2*N];
  float r=1.0;
  size_t i,j;
  for (i=0; i<N; i++) {
    y[i] = (float)(i+N);
  }
  for (i=0; i<2*N; i++) {
    x[i] = 1.0/((float)(i+1));
    z[i] = r*x[i];
    r=-r;
  }
  for (j=0; j<N; j++) {
    for (i=1; i<N; i++) {
      axpy1(z[i+j] ,x+j+N-i,y,    i);
      axpy1(-z[i+j],x+j,    y+N-i,i);
    }
  }
  printf("checksum of y: %lx\n",hash((char *)y,N*sizeof(float)));
  return 0;
}
