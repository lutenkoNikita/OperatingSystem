#include <math.h>
#include <stdio.h>


double f(double x)
{
  double abs_x = (x > 0) ? x : -1*x;
  return exp((-1)*abs_x)*sin(x);
}

double g(double x)
{
  double abs_x = (x > 0) ? x : -1*x;
  return exp((-1)*abs_x)*cos(x);
}

int main()
{
  double argumentX;

  do{
    scanf("%lf", &argumentX);
  }while(!(argumentX >= -1 && argumentX <= 1));

  printf("f(%lf): %lf\n", argumentX, f(argumentX));
  printf("g(%lf): %lf", argumentX, g(argumentX));
}
