#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e2work1.h"

#define N 1000

void init(payload_t *p)
{
  p->val1 = random();
  p->val2 = (double)random()*0.000000001;
  p->val3 = (float)random()*0.000000001;
  p->val4 = random();
  p->val5 = random();
  p->val6 = random();
  p->val7 = random();
  p->val8 = random();
  p->val9 = random();

}

void mainarray(int v)
{
  size_t i;
  long r=0;
  payload_t a[N];
  for (i=0; i<N; i++)
    init(&a[i]);
  if (v==1)
    for (i=0; i<100000; i++)
      r += array1(a,N);
  else
    for (i=0; i<100000; i++)
      r += array2(a,N);
  printf("%ld\n",r);
}

void mainlist(int v)
{
  size_t i;
  long r=0;
  list_t a[N];
  for (i=0; i<N; i++) {
    init(&(a[i].payload));
    a[i].next = &a[i+1];
  }
  a[N-1].next = NULL;
  if (v==1)
    for (i=0; i<100000; i++)
      r += list1(a);
  else
    for (i=0; i<100000; i++)
      r += list2(a);
  printf("%ld\n",r);
}

int main(int argc, char *argv[])
{
  int v;
  if (argc<3)
    goto usage;
  srandom(1234); /* always use the same pseudo-random numbers */
  if (strcmp(argv[2],"1")==0)
    v=1;
  else if (strcmp(argv[2],"2")==0)
    v=2;
  else
    goto usage;
  if (strcmp(argv[1],"array")==0) {
    mainarray(v);
  } else if (strcmp(argv[1],"list")==0) {
    mainlist(v);
  } else
    goto usage;
  return 0;    
  
 usage:
  fprintf(stderr,"Usage: %s array|list 1|2\n", argv[0]);
  return 1;
}
