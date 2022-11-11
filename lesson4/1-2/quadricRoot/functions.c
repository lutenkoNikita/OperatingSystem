#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../headerFolder/header.h"

data_t * initializeDataType(int argc)
{
  data_t * tmpData = (data_t *)malloc(sizeof(data_t));

  if(!tmpData)
    return NULL;

  for(size_t i = 0; i < sizeof(data_t); i++)
    *((char *)tmpData + i) = 0;

  tmpData -> massiveWords = (char **)calloc(argc, sizeof(char *));


  if(!(tmpData -> massiveWords))
  {
    free(tmpData);
    return NULL;
  }

  return tmpData;
}

double calculateDegree(double degree)
{
  double result = 1.0;
  for(int i = 0; i > degree; i--)
    result /= 10;

  return result;
}

double convertStringToDouble(char * ptrString)
{
    int lengthOfString = 0;
    int positionOfDote = 0;
    int   sign = 1;
    char * savePointerString = ptrString;

    while(*savePointerString)
    {
      if(__MINUS_SYMBOL(*savePointerString))
        sign = -1;

      if(__DOTE_SYMBOL(*savePointerString))
          positionOfDote = lengthOfString;

      savePointerString++;
      lengthOfString++;
    }

    if(!positionOfDote)
      positionOfDote = lengthOfString - 1;

    int minDegree = positionOfDote - lengthOfString + 1;


    double base = calculateDegree(minDegree);
    double result = 0;

    for(int i = lengthOfString - 1; i >= 0; i--)
    {
      if(__DOTE_SYMBOL(ptrString[i]) || __PLUS_SYMBOL(ptrString[i]))
        continue;

      if(__MINUS_SYMBOL(ptrString[i]))
      {
        result *= -1;
        continue;
      }

      result += (ptrString[i] - __ASCII_OFFSET) * base;
      base *= 10;

    }

    return result;
}

ratio_t * initializeRatioType(double a, double b, double c)
{
  ratio_t * tmpRatio = (ratio_t *)malloc(sizeof(ratio_t));

  tmpRatio -> A = a;
  tmpRatio -> B = b;
  tmpRatio -> C = c;

  return tmpRatio;
}

double * solution(ratio_t * ratio)
{
  double * tmp = (double *)malloc(3 * sizeof(double));
  if(!tmp)
    return NULL;

  if(ratio -> A == 0)
  {
    tmp[0] = -1*(ratio -> C) / ratio -> B;
    tmp[1] = 0;
    tmp[2] = 0;

    return tmp;
  }


  double discret = ((ratio -> B * ratio -> B) - 4 * ratio -> A * ratio -> C);

  if(discret < 0)
  {
    tmp[2] = discret;
    return tmp;
  }

  discret = sqrt(discret);
  tmp[0] = (-1*(ratio -> B) + discret) / 2 * ratio -> A;
  tmp[1] = (-1*(ratio -> B) - discret) / 2 * ratio -> A;
  tmp[2] = discret;

  return tmp;
}
