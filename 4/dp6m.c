#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void axpy1(float a, float *x, float *y,
           float *z, float *w, float *v,
           size_t n);

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

void randinit(float *a, size_t n)
{
  size_t i;
  static unsigned long r=1;
  for (i=0; i<n; i++) {
    a[i] = ((float)r)/18446744073709551616.0-0.5;
    r = r*0x96906d7e52553935L;
    r = (r<<27)|(r>>37);
  }
}


int main(int argc, char *argv[])
{
  float x[2*N];
  float y[2*N];
  float z[N];
  float w[N];
  float v[N];
  float a[2*N];
  size_t i, j, n, iterations;
  if (argc!=2) {
    fprintf(stderr, "Usage: %s <avg-vector-length>\n",argv[0]);
    return 1;
  }
  n = atol(argv[1]);
  if (n<1 || n>500) {
    fprintf(stderr, "Average vector length must be in range 1..500");
    return 1;
  }
  memset(z,0,sizeof(z));
  randinit(x,2*N);
  randinit(y,2*N);
  randinit(a,2*N);
  iterations=0;
  j=0;
  while (1) {
    for (i=1; i<2*n; i++) {
      if (iterations>=1000000) {
        printf("checksum of z: %lx\n",hash((char *)z,sizeof(z)));
        return 0;
      }
      axpy1(a[i+j],  x+N-j,    y+N-i,z      ,w+N-i,v    ,i);
      axpy1(a[N-i+j],x+2*N-i-j,y+N-i+j,z+N-i,w    ,v+N-i,i);
      iterations++;
      j++;
      if (j==N)
        j=0;
    }
  }
}
