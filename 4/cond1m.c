#include <stddef.h>
#include <stdio.h>
#include <string.h>

void axpy1(float a, float *x, float *y, float * restrict z, size_t n);

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


int main()
{
  float x[2*N];
  float y[2*N];
  float z[N];
  float a[2*N];
  size_t i,j;
  memset(z,0,sizeof(z));
  randinit(x,2*N);
  randinit(y,2*N);
  randinit(a,2*N);
  for (j=0; j<N; j++) {
    for (i=1; i<N; i++) {
      axpy1(a[i+j],  x+N-j,    y+N-i,z    ,i);
      axpy1(a[N-i+j],x+2*N-i-j,y+N-i+j,z+N-i,i);
    }
  }
  printf("checksum of z: %lx\n",hash((char *)z,sizeof(z)));
  return 0;
}
