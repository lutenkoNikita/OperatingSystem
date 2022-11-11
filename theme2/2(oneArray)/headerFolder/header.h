#ifndef __MYOWN_MACRO
#define __MYOWN_MACRO 1

#define LENGTH 5
#define ASCIIOFFSET 48
#define NEG(A) (A < 0) ? -1*A : A

typedef struct numberSymbol{
  char * numberStr;
  size_t indexSymbol;
  char   newSymbol;
} numberSymbol_t;

typedef struct elementOfMassive{
  double value;
  size_t index;
  size_t lengthOfMassive;
} dblelementOfMassive_t;


numberSymbol_t * createNumberType();
size_t lengthMassiveConvert(char * argString, size_t index);
dblelementOfMassive_t * firstNegativeElement(void * ptrMassive, size_t lengthOfMassive);
size_t average(void * ptrMassive, size_t lengthOfMassive);
double dblAbs(void * ptrMassive, dblelementOfMassive_t * ptrElement);

#endif
