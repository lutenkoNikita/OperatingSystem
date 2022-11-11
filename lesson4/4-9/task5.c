#include <stdlib.h>
#include <stdio.h>

#define MAXBUFF 256
typedef struct string{

  size_t maxCapacity;
  size_t currentCapacity;
  unsigned char * nameVariable;
  unsigned char currentSymbol;

} string_t;

string_t * createString()
{
  string_t * tmpString = (string_t *)malloc(sizeof(string_t));

  tmpString -> maxCapacity = MAXBUFF;
  tmpString -> currentCapacity = 0;
  tmpString -> nameVariable = (unsigned char*)calloc(tmpString -> maxCapacity, sizeof(char));

  return tmpString;
}


int main()
{
  string_t * str0 = createString();

  while( (str0 -> currentSymbol= getchar()) != '\n' && str0 -> currentCapacity != str0 -> maxCapacity - 1)
  {
    printf("%d %c\n", str0 -> currentSymbol, str0 -> currentSymbol);
    (str0 -> nameVariable)[str0 -> currentCapacity] = str0 -> currentSymbol;
    str0 -> currentCapacity++;

  }

  (str0 -> nameVariable)[str0 -> maxCapacity - 1] = '\0';

  char * result = getenv(str0 -> nameVariable);

  switch((int)result)
  {
    case 0:
      printf("no\n");
      break;

    default:

      if(!result[0])
      {
        printf("empty string\n");
        break;
      }

      printf("VALUE: %s\n", result);
      break;
  }
}
