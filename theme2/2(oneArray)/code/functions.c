#include <stdlib.h>
#include "../headerFolder/header.h"

numberSymbol_t * createNumberType()
{
  numberSymbol_t * tmp = (numberSymbol_t *)malloc(sizeof(numberSymbol_t));

  tmp -> numberStr = (char *)calloc(LENGTH, sizeof(char));
  tmp -> indexSymbol  = 0;
  tmp -> newSymbol = 0;

  return tmp;
}

size_t lengthMassiveConvert(char * argString, size_t index)
{

  size_t result = 0;
  size_t dec = 1;

  while(index != ((size_t)-1))
  {
    if(!(argString[index] >= '0' && argString[index] <= '9'))
      return 0;

    result += (argString[index] - ASCIIOFFSET)*dec;
    dec *= 10;
    index--;
  }

  return result;
}

dblelementOfMassive_t * firstNegativeElement(void * ptrMassive, size_t lengthOfMassive)
{
  for(size_t i = 0; i < lengthOfMassive; i++)
  {
    if(*(((double *)ptrMassive) + i) < 0)
    {
        dblelementOfMassive_t * tmp = (dblelementOfMassive_t *)malloc(sizeof(dblelementOfMassive_t));
        tmp -> value = *(((double *)ptrMassive) + i);
        tmp -> index = i;
        tmp -> lengthOfMassive = lengthOfMassive;

        return tmp;
    }
  }

  return NULL;
}

size_t average(void * ptrMassive, size_t lengthOfMassive)
{
  double average = 0;
  for(size_t i = 0; i < lengthOfMassive; i++)
    average += *((double *)ptrMassive + i);
  average /= (double)lengthOfMassive;

  size_t count = 0;
  for(size_t i = 0; i < lengthOfMassive; i++)
    if(*((double *)ptrMassive + i) > average) count++;

  return count;
}

double dblAbs(void * ptrMassive, dblelementOfMassive_t * ptrElement)
{
  double sumResult = 0;

  for(size_t i = ptrElement -> index + 1; i < ptrElement -> lengthOfMassive; i++)
    sumResult += NEG(((double *)ptrMassive)[i]);

  return sumResult;
}
