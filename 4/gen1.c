#include <stddef.h>

void gen1(int * restrict a, size_t n, int offset)
{
  size_t i;
  for (i=0; i<n; i++) {
    int j=i+offset;
    a[i] = j*j;
  }
}
