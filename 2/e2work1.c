#include "e2work1.h"

long array1(payload_t a[], size_t n)
{
  size_t i=0;
  long r=0;
  while (i<n) {
    r += a[i].val1 + a[i].val5;
    i++;
  }
  return r;
}

long list1(list_t *a)
{
  long r=0;
  while (a != NULL) {
r += a->payload.val1 + a->payload.val5;
a = a->next;
}
  return r;
}

long array2(payload_t a[], size_t n)
{
  size_t i=0;
  long r=0;
  while (i<n) {
    r += a[i].val1 + a[i].val5;
    r ^= a[i].val6;
    i++;
  }
  return r;
}

long list2(list_t *a)
{
  long r=0;
  while (a != NULL) {
    r += a->payload.val1 + a->payload.val5;
    r ^= a->payload.val6;
    a = a->next;
  }
  return r;
}
