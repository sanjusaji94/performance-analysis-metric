#include <stddef.h>

typedef struct {
  long val1;
  double val2;
  float val3;
  int val4, val5;
  char val6, val7, val8, val9;
} payload_t;

typedef struct list {
  struct list *next;
  payload_t payload;
} list_t;

long array1(payload_t a[], size_t n);
long list1(list_t *a);
long array2(payload_t a[], size_t n);
long list2(list_t *a);
