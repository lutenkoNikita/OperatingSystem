#ifndef ARRAYLIST
#define ASCIIOFFSET 48

typedef struct dynamicArray
{
    int  *  array;
    size_t  lengthOfMassive;
} dynamicArray_t;

void writeDynamicArray(dynamicArray_t * ptrStruct);
size_t size(dynamicArray_t * ptrStruct);
int get(dynamicArray_t * ptrStruct, size_t index);
int set(dynamicArray_t * ptrStruct, size_t index, int newValue);
dynamicArray_t * removeElement(dynamicArray_t * ptrStruct, size_t index);
dynamicArray_t * addNewElementMiddle(dynamicArray_t * ptrStruct, size_t index, int newValue);
dynamicArray_t * addNewElementTail(dynamicArray_t * ptrStruct, int newValue);
dynamicArray_t * createNewArray(size_t initialSize);

#endif
