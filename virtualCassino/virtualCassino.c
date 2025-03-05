#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void Play(int bet) {
  char *C = (char *)malloc(1000 * sizeof(char));
  C[0] = 'Q';
  C[1] = 'J';
  C[2] = 'K';
  printf("Shuffling...");

  srand(time(NULL));

  for (int i = 0; i < 5; i++) {
    int x = rand() % 3;
    int y = rand() % 3;
    int temp = C[x];

    C[x] = C[y];
    C[y] = temp;
  }
  int playerGuess;

  printf("What's the position of the queen - 1, 2 or 3? ");
  scanf("%d", &playerGuess);

  if (C[playerGuess - 1] == 'Q') {
    cash += 3 * bet;
    printf("You won! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2],
           cash);
  } else {
    cash -= bet;
    printf("You lose! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1],
           C[2], cash);
  }
  free(C);
}

int main() {
  int bet;

  printf("-----Welcome to the Virtual Cassino-----\n\n");
  printf("Total cash = %d\n", cash);

  while (cash > 0) {
    printf("What's your bet? $");
    scanf("%d", &bet);
    if (bet == 0 || bet > cash)
      break;
    Play(bet);
    printf("\n**********************************\n");
  }

  return 0;
}
