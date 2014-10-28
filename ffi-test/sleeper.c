#include <unistd.h>
//gcc -dynamiclib sleeper.c -o libsleeper.dylib
unsigned int sleeper(unsigned int seconds)
{
  return sleep(seconds);
}
