#include <math.h>
#include "../headerFolder/header.h"
double f(double x)
{
  double abs_x = (x > 0) ? x : -1*x;
  return exp((-1)*abs_x)*sin(x);
}
