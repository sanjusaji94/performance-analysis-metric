#include <stddef.h>
#include <stdio.h>

void gen1(int a[], size_t n, int offset);

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
  int x[2*N];
  size_t i,j;
  for (j=0; j<N; j++) {
    for (i=1; i<N; i++) {
      gen1(x+j,i,i+j);
    }
  }
  return 0;
}
