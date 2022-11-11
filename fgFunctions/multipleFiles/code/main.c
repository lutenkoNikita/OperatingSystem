#include <stdio.h>
#include "../headerFolder/header.h"

int main()
{
  double argumentX;

  do{
    scanf("%lf", &argumentX);
  }while(!(argumentX >= -1 && argumentX <= 1));

  printf("f(%lf): %lf\n", argumentX, f(argumentX));
  printf("g(%lf): %lf\n", argumentX, g(argumentX));
}
