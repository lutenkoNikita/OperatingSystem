#ifndef __QUADRATIC_ROOT
#define __QUADRATIC_ROOT 1

#define __TOP_BORDER(a)    ((a) <= '9')
#define __BOTTOM_BORDER(a) ((a) >= '0')
#define __MINUS_SYMBOL(a)  ((a) == '-')
#define __PLUS_SYMBOL(a)   ((a) == '+')
#define __DOTE_SYMBOL(a)   ((a) == '.')
#define __ZERO_FLAG(a)     ((a) ==  0 )


#define __CHECK_SIGN(a)         (__MINUS_SYMBOL(a) || __PLUS_SYMBOL(a))
#define __CHECK_DOTE(a, b, c)   (__DOTE_SYMBOL(a) && __ZERO_FLAG(b) && __CHECK_NUMBER(c))
#define __CHECK_NUMBER(a)       (__BOTTOM_BORDER(a) && __TOP_BORDER(a))
#define __CHECK_FIRST_SYMBOL(a) (__MINUS_SYMBOL(a) || __PLUS_SYMBOL(a) ||  __CHECK_NUMBER(a))
#define __CHECK_STATE(a, b, c)  (__CHECK_NUMBER(a) || __CHECK_DOTE((a), (b), (c)))
#define __ASCII_OFFSET 48

typedef struct data
{
    size_t   numberOfSymbols;
    size_t   currentSymbol;
    size_t   currentWord;
    size_t   existedDote;
    char **  massiveWords;
} data_t;

typedef struct ratio{
  double A;
  double B;
  double C;
} ratio_t;


data_t * initializeDataType(int argc);
ratio_t * initializeRatioType(double a, double b, double c);
double calculateDegree(double degree);
double convertStringToDouble(char * ptrString);
double * solution(ratio_t * ratio);

#endif
