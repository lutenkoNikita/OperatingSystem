#include <stdio.h>
#include <stdlib.h>

#include "../header/arraylist.h"


int main()
{
  unsigned char firstSymbol = 0;
  unsigned char secondSymbol = 0;
  unsigned char item;
  int transVal;
  size_t transIndex;

  dynamicArray_t * dnmcAr = createNewArray(5);

  while(1)
  {

    do{
      if(secondSymbol != '\n' && secondSymbol)
        while(getchar() != '\n');
      firstSymbol  = getchar();
      secondSymbol = getchar();

    }while(!(firstSymbol >= '0' && firstSymbol <= '7') || secondSymbol != '\n');

    item = firstSymbol - ASCIIOFFSET;
    secondSymbol = 0;
    switch(item)
    {
      case 0:
        return 0;
      case 1:
        writeDynamicArray(dnmcAr);
        break;
      case 2:

        printf("enter value: ");
        scanf("%d", &transVal);

        addNewElementTail(dnmcAr, transVal);
        while(getchar() != '\n');
        break;

      case 3:
        printf("enter value: ");
        scanf("%d", &transVal);

        printf("enter index: ");
        scanf("%lu", &transIndex);

        addNewElementMiddle(dnmcAr, transIndex, transVal);
        while(getchar() != '\n');
        break;
      case 4:
        printf("%lu\n", size(dnmcAr));
        break;
      case 5:
        printf("enter index: ");
        scanf("%lu", &transIndex);
        removeElement(dnmcAr, transIndex);
        while(getchar() != '\n');
        break;
      case 6:
        printf("enter value: ");
        scanf("%d", &transVal);

        printf("enter index: ");
        scanf("%lu", &transIndex);

        set(dnmcAr, transIndex, transVal);
        while(getchar() != '\n');
        break;
      case 7:
        printf("enter index: ");
        scanf("%lu", &transIndex);

        printf("%d\n", get(dnmcAr, transIndex));
        while(getchar() != '\n');
        break;
    }
  }
}
