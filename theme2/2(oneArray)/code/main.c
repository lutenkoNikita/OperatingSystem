#include <stdio.h>
#include <stdlib.h>
#include "../headerFolder/header.h"

int main(int argc, char ** argv)
{
  numberSymbol_t * _ptr_number_t = createNumberType();
  printf("Length can consist of fifth symbols\nEnter length of array: ");
  _ptr_number_t -> newSymbol = getchar();

  do{
    if(_ptr_number_t -> indexSymbol != 0 || (_ptr_number_t -> newSymbol == '\n' && _ptr_number_t -> indexSymbol == 0))
      _ptr_number_t -> newSymbol = getchar();

    if(_ptr_number_t -> indexSymbol >= LENGTH - 1 && _ptr_number_t -> newSymbol != '\n')
    {
      while(getchar() != '\n');
      for(int i = 0; i < LENGTH; i++)
        (_ptr_number_t -> numberStr)[i] = '\0';
      _ptr_number_t -> newSymbol = '\n';
      _ptr_number_t -> indexSymbol = 0;
    }
    else if(_ptr_number_t -> indexSymbol == 0 && _ptr_number_t -> newSymbol == '0')
    {
      while(getchar() != '\n');
      for(int i = 0; i < LENGTH; i++)
        (_ptr_number_t -> numberStr)[i] = '\0';
      _ptr_number_t -> newSymbol = '\n';
      _ptr_number_t -> indexSymbol = 0;
    }
    else if(!(_ptr_number_t -> newSymbol >= '0' && _ptr_number_t -> newSymbol <= '9') && _ptr_number_t -> newSymbol != '\n')
    {
      while(getchar() != '\n');
      for(int i = 0; i < LENGTH; i++)
        (_ptr_number_t -> numberStr)[i] = '\0';
      _ptr_number_t -> newSymbol = '\n';
      _ptr_number_t -> indexSymbol = 0;

    }
    else if(_ptr_number_t -> newSymbol != '\n')
    {
        (_ptr_number_t -> numberStr)[_ptr_number_t -> indexSymbol] = _ptr_number_t -> newSymbol;
        (_ptr_number_t -> indexSymbol)++;
    }
  }while(_ptr_number_t -> newSymbol != '\n' || (_ptr_number_t -> newSymbol == '\n' && _ptr_number_t -> indexSymbol == 0));


  size_t lengthMassive = 0;
  do
  {
    lengthMassive = lengthMassiveConvert(_ptr_number_t -> numberStr, --(_ptr_number_t -> indexSymbol));
  }while(lengthMassive == 0);

  double dblMassive[lengthMassive];

  double currentValue;
  char resultWriting, flagWriting;

  for(size_t i = 0; i < lengthMassive; i++)
  {
    resultWriting = flagWriting = 0x0;

    do{
      if(flagWriting)
        while(getchar() != '\n');

      resultWriting = scanf("%lf", &currentValue);
      flagWriting |= 0x1;
    }while(!resultWriting);

    dblMassive[i] = currentValue;
  }

  for(size_t i = 0; i < lengthMassive; i++)
  {
    printf("%lf ", dblMassive[i]);
  }
  printf("\n");

  /*average*/

  size_t resultAverage = average(dblMassive, lengthMassive);
  printf("Count: %lu\n", resultAverage);
  /*negative*/
  dblelementOfMassive_t * negElement = firstNegativeElement((void *)dblMassive, lengthMassive);

  if(!negElement)
  {
    printf("There isn't a negative element\n");
    return 1;
  }

  printf("Negative element:\n\tvalue:%lf,\n\tindex:%lu\n", negElement -> value, negElement -> index);

  double finalResult = dblAbs(dblMassive, negElement);
  printf("\tsum:%lf\n", finalResult);

  return 0;
}
