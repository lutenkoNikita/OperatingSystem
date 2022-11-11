#include <stdlib.h>
#include <stdio.h>

#define MAXBUFF 256
#define FAILURE -1
#define SUCCESS 0

typedef struct string{

  size_t maxCapacity;
  size_t currentCapacity;
  unsigned char * string;
  unsigned char currentSymbol;

} string_t;

string_t * createString()
{
  string_t * tmpString = (string_t *)malloc(sizeof(string_t));

  tmpString -> maxCapacity = MAXBUFF;
  tmpString -> currentCapacity = 0;
  tmpString -> string = (unsigned char*)calloc(tmpString -> maxCapacity, sizeof(char));

  return tmpString;
}

char * uniteStrings(string_t * first, string_t * second)
{
  char * resultString = (char *)calloc(first -> currentCapacity + second -> currentCapacity + 2, sizeof(char));
  size_t i = 0;
  while(i < first -> currentCapacity )
  {
    resultString[i] =  (first -> string)[i];
    //printf("%c", resultString[i]);
    i++;
  }
  resultString[first -> currentCapacity] = '=';
  i = 0;
  while(i < second -> currentCapacity )
  {
    resultString[first -> currentCapacity + i + 1] =  (second -> string)[i];
    //printf("%c", resultString[first -> currentCapacity + i + 1]);
    i++;
  }
  resultString[first -> currentCapacity + second -> currentCapacity + 1] = '\0';

  //printf("%d", resultString[first -> currentCapacity + second -> currentCapacity + 1]);

  return resultString;
}

int main()
{
  string_t * name  = createString();

  while( (name -> currentSymbol= getchar()) != '\n' && name -> currentCapacity != name -> maxCapacity - 1)
  {
  //  printf("%d %c\n", name -> currentSymbol, name -> currentSymbol);
    (name -> string)[name -> currentCapacity] = name -> currentSymbol;
    name -> currentCapacity++;

  }
  (name -> string)[name -> currentCapacity] = '\0';

  //printf("%lu %s\n", name -> currentCapacity, name -> string);
  string_t * value = createString();

  while( (value -> currentSymbol= getchar()) != '\n' && value -> currentCapacity != value -> maxCapacity - 1)
  {
    //printf("%d %c\n", value -> currentSymbol, value -> currentSymbol);
    (value -> string)[value -> currentCapacity] = value -> currentSymbol;
    value -> currentCapacity++;

  }
  (value -> string)[value -> currentCapacity] = '\0';
//  printf("%lu %s\n", value -> currentCapacity, value -> string);

  char * resultString = uniteStrings(name, value);

  switch(putenv(resultString))
  {
    case FAILURE:
      printf("no\n");
      break;
    case SUCCESS:
      printf("yes\n");
      break;
  }

}
