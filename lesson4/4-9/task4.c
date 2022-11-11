#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char ** environ;
int main()
{

  char ** massive = environ;
  while(massive)
  {
    printf("massive[%d]: %s\n", (massive++ - environ), *massive);
  }
}
