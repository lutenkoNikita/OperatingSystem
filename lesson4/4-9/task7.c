#include <stdlib.h>
#include <stdio.h>

#define FAILURE -1
#define SUCCESS 0

int main(int argc, char ** argv)
{
  if(argc < 2)
  {
    clearenv();
    return 0;
  }

  switch(unsetenv(argv[1]))
  {
    case 0:
      printf("success\n");
      break;
    case -1:
      printf("fail\n");
      break;
  }
}
