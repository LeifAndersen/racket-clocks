#include <stdio.h>
#include <time.h>
#include "grind.c"
#include <sys/times.h>

clock_t easy_times() {
  struct tms t;
  times(&t);
  return t.tms_utime;
}

clock_t easy_times2() {
  struct tms t;
  times(&t);
  return t.tms_utime + t.tms_stime;
}

clock_t easy_times3() {
  struct tms t;
  times(&t);
  return t.tms_utime + t.tms_stime + t.tms_cutime + t.tms_cstime;
}

int main()
{
  printf("Timing one process:\n");
  printf("%d\n", clock());
  printf("%d\n", easy_times());
  printf("%d\n", easy_times2());
  printf("%d\n", easy_times3());
  printf("%d\n", grind());
  printf("%d\n", clock());
  printf("%d\n", easy_times());
  printf("%d\n", easy_times2());
  printf("%d\n", easy_times3());

  printf("\nTiming multi process:\n");
  printf("%d\n", clock());
  printf("%d\n", easy_times());
  printf("%d\n", easy_times2());
  printf("%d\n", easy_times3());
  printf("%d\n", grind2());
  printf("%d\n", clock());
  printf("%d\n", easy_times());
  printf("%d\n", easy_times2());
  printf("%d\n", easy_times3());
  return 0;
}
