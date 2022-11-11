#include <stdio.h>
#include <stdlib.h>
#include "../header/arraylist.h"

void writeDynamicArray(dynamicArray_t * ptrStruct)
{
  printf("Array: ");
  for(size_t i = 0; i < ptrStruct -> lengthOfMassive; i++)
    printf("%d ", (ptrStruct -> array)[i]);

  printf("\nSize: %lu\n", ptrStruct -> lengthOfMassive);
  printf("Address of array: [%p]\n", ptrStruct -> array);
  printf("Address of structure: [%p]\n", ptrStruct);

  printf("\n");
}

size_t size(dynamicArray_t * ptrStruct)
{
    return ptrStruct -> lengthOfMassive;
}

int get(dynamicArray_t * ptrStruct, size_t index)
{
    if(index < 0 || index >= ptrStruct -> lengthOfMassive)
    {
      printf("error\n");
      return -1;
    }
    return (ptrStruct -> array)[index];
}

int set(dynamicArray_t * ptrStruct, size_t index, int newValue)
{
    if(index < 0 || index >= ptrStruct -> lengthOfMassive)
      return -1;

    (ptrStruct -> array)[index] = newValue;
    return 0;
}

dynamicArray_t * removeElement(dynamicArray_t * ptrStruct, size_t index)
{
  if(index < 0 || index >= ptrStruct -> lengthOfMassive)
    return NULL;
  int * tmpDynamicArray = (int *)calloc(ptrStruct -> lengthOfMassive - 1, sizeof(int));

  if(!tmpDynamicArray)
    return NULL;

  for(size_t i = 0; i < ptrStruct -> lengthOfMassive - 1; i++)
    tmpDynamicArray[i] = (i < index) ? (ptrStruct -> array)[i] : (ptrStruct -> array)[i + 1];

  free(ptrStruct -> array);
  ptrStruct -> array = tmpDynamicArray;
  ptrStruct -> lengthOfMassive--;

  return ptrStruct;
}

dynamicArray_t * addNewElementMiddle(dynamicArray_t * ptrStruct, size_t index, int newValue)
{
  if(index < 0 || index > ptrStruct -> lengthOfMassive)
    return NULL;

  int * tmpNewDynamicArray = (int *)calloc(ptrStruct -> lengthOfMassive + 1, sizeof(int));

  if(!tmpNewDynamicArray)
    return NULL;

  for(size_t i = 0; i < ptrStruct -> lengthOfMassive + 1; i++)
    tmpNewDynamicArray[i] = (i < index) ? (ptrStruct -> array)[i] : (ptrStruct -> array)[i - 1];
  tmpNewDynamicArray[index] = newValue;

  free(ptrStruct -> array);
  ptrStruct -> array = tmpNewDynamicArray;
  ptrStruct -> lengthOfMassive++;

  return ptrStruct;
}

dynamicArray_t * addNewElementTail(dynamicArray_t * ptrStruct, int newValue)
{
  ptrStruct -> array = (int *)realloc(ptrStruct -> array, (ptrStruct -> lengthOfMassive + 1)*sizeof(int));

  if(!ptrStruct -> array)
    return NULL;

  ptrStruct -> lengthOfMassive++;
  (ptrStruct -> array)[ptrStruct -> lengthOfMassive - 1] = newValue;

  return ptrStruct;
}


dynamicArray_t * createNewArray(size_t initialSize)
{
  dynamicArray_t * tmpStruct = (dynamicArray_t *)malloc(sizeof(dynamicArray_t));
  if(!tmpStruct)
    return NULL;

  int * tmpDynamicArray = (int *)calloc(initialSize, sizeof(int));
  if(!tmpDynamicArray)
    return NULL;

  tmpStruct -> array = tmpDynamicArray;
  tmpStruct -> lengthOfMassive = initialSize;

  return tmpStruct;

}
