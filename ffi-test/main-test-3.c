#include <stdio.h>
#include <time.h>
#include "grind.c"

int main()
{
  printf("%d\n", clock());
  int x = grind2();
  printf("%d\n", x);
  printf("%d\n", clock());
  return 0;
}
