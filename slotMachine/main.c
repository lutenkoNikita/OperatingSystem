#include <stdio.h>
#include <stdlib.h>

#define __FINE          666
#define __JACKPOT       777
#define __SHOW__SCREEN  100
#define __SIZE__MASSIVE 205


int main()
{
  srand(1);
  int massivePrize[__SIZE__MASSIVE] = {0, 111, 222, 333, 444};
  for(size_t i = 5; i < __SIZE__MASSIVE - 1; i++)
    massivePrize[i] = (i < 105) ? 500 + (i - 5): 700 + (i - 105);
  massivePrize[204] = 777;

  int balance = 5000;
  int randomNumber;
  printf("History:\n");
  printf("To show screen a next stage, it has to pay 100 coins\n");
  while(1)
  {
    printf("your balance: %d\n", balance);
    printf("Random number: %d\n", randomNumber = rand() % 778);

    balance -= __SHOW__SCREEN;
    if(balance <= 0)
    {
      printf("game over\n");
      return 0;
    }
    for(size_t i = 0; i < __SIZE__MASSIVE; i++)
    {
      if(massivePrize[i] == randomNumber)
      {
        balance = (balance) ? balance + randomNumber : balance + 100;
        break;
      }
    }
    if(randomNumber == 777)
    {
      printf("you won, your balance: %d\n", balance);
      return 0;
    }

    if(randomNumber == 666)
    {
      printf("penalty, you lose 666 coins");
      balance -= randomNumber;
    }


  }
}
