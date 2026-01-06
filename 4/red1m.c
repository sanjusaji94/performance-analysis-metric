#include <stddef.h>
#include <stdio.h>

float dot1(float *x, float *y, size_t n);

#define N 1000

unsigned long hash(char *a, size_t n)
{
  size_t i;
  unsigned long r=0;
  for (i=0; i<N; i++) {
    r += a[i];
    r = r*0x96906d7e52553935L;
    r = (r<<27)|(r>>37);
  }
  return r;
}

int main()
{
  float x[2*N];
  float y[2*N];
  float r=0.0;
  size_t i,j;
  for (i=0; i<2*N; i++) {
    x[i] = (float)(i);
    y[i] = (float)(N-i);
  }
  for (j=0; j<N; j++) {
    for (i=1; i<N; i++) {
      r += dot1(&x[i],&y[j],i);
    }
  }
  printf("r= %f\n",r);
  return 0;
}
