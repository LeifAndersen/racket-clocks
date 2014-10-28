#include <unistd.h>
#include <stdio.h>

//gcc -dynamiclib grind.c -o libgrind.dylib

int grind(void)
{
  int i;
  int x;
  for(i = 0; i < 2000000000; i++) {
    x += i;
  }
  return x;
}

int grind2(void)
{
  pid_t pid;
  int status;
  if((pid = fork()) < 0) {
    perror("Fork");
    _exit(1);
  } else if(pid == 0) {
    _exit(grind());
  } else {
    waitpid(pid, &status, 0);
    return status;
  }
}
