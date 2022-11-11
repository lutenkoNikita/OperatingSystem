#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <unistd.h>

#define MAXLINE

utsname * initializationStructUtsname(struct utsname * ptr)
{
  if(!ptr) return NULL;


  return ptr;
}

int main()
{
  char * nameNetwork = (char *)calloc(MAXLINE, sizeof(char));

  if(!name)
    return -1;

  if(!gethostname(nameNetwork, MAXLINE))
  {
    printf("nameNetwork: %s\n", nameNetwork);
  }else
    printf("error\n");

  struct utsname * nameStruct = (struct utsname *)malloc(sizeof(struct utsname));
  if(!nameStruct)
    return -1;

    uname(nameStruct);

    if(errno != -1)
    {
      printf("%s: \n", nameStruct -> sysname);
      printf("%s: \n", nameStruct -> nodename);
      printf("%s: \n", nameStruct -> release);
      printf("%s: \n", nameStruct -> version);
      printf("%s: \n", nameStruct -> machine);

    }else
      printf("error\n");


}
