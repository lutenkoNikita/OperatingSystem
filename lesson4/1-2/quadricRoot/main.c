#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../headerFolder/header.h"


int main(int argc, char ** argv)
{

  if(argc != 4)
    return -1;

  data_t * __info = initializeDataType(argc);

  if(!__info)
   exit(1);

  size_t checkedWord = 0;

  for(__info -> currentWord = 1; __info -> currentWord < argc; __info -> currentWord++)
  {
    size_t lengthOfWord = strlen(argv[__info -> currentWord]);

    __info -> currentSymbol = __info -> existedDote = 0;

    while(__info -> currentSymbol < lengthOfWord)
    {

      if((__ZERO_FLAG(__info -> currentSymbol)) && __CHECK_SIGN(argv[__info -> currentWord][__info -> currentSymbol]) && lengthOfWord < 2)
        break;
      if((__ZERO_FLAG(__info -> currentSymbol)) && !(__CHECK_FIRST_SYMBOL(argv[__info -> currentWord][__info -> currentSymbol])))
        break;


      if(!(__ZERO_FLAG(__info -> currentSymbol)) &&
      !(__CHECK_STATE(argv[__info -> currentWord][__info -> currentSymbol], __info -> existedDote, argv[__info -> currentWord][__info -> currentSymbol - 1])))
        break;
      else if(__DOTE_SYMBOL(argv[__info -> currentWord][__info -> currentSymbol] == '.') && __ZERO_FLAG(__info -> existedDote))
        __info -> existedDote = 1;

      __info -> currentSymbol++;
    }

    if(__info -> currentSymbol == lengthOfWord)
    {
      (__info -> massiveWords)[checkedWord] = argv[__info -> currentWord];
      checkedWord++;
    }
  }

  if(checkedWord < 3)
    exit(1);

  // for(size_t i = 0; i < checkedWord; i++)
  //   printf("%s ", (__info -> massiveWords)[i]);
  // printf("\n");

  //printf("%lf %lf %lf\n", convertStringToDouble((__info -> massiveWords)[0]), convertStringToDouble((__info -> massiveWords)[1]), convertStringToDouble((__info -> massiveWords)[2]));

  ratio_t * ratioData = initializeRatioType(convertStringToDouble((__info -> massiveWords)[0]), convertStringToDouble((__info -> massiveWords)[1]), convertStringToDouble((__info -> massiveWords)[2]));

  double * vectorDouble = solution(ratioData);

  if(vectorDouble[2] < 0)
    printf("There's no any solution\n");
  else if(__ZERO_FLAG(vectorDouble[1]) && __ZERO_FLAG(vectorDouble[2]))
    printf("There's one root. First %lf\n", vectorDouble[0]);
  else
    printf("There're two roots. First %lf, Second %lf\n", vectorDouble[0], vectorDouble[1]);
}
