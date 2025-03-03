#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char palavra[16], palavraFinal[16], letrasUsuario[26];

  int errosMax = 6, curErros, rodando = 1, vidas = 0;

  printf("Insira a palavra secreta: ");
  fgets(palavra, 26, stdin);
  system("clear");

  int letrasPalavra = strlen(palavra);

  do {
    printf("Descubra qual e a palavra:\n");
    int acerto = 0, indiceLetras = 0;
    for (int i = 0; i <= strlen(letrasUsuario); i++) {
      for (int j = 0; j <= letrasPalavra; j++) {
        if (letrasUsuario[i] == palavra[j]) {
          palavraFinal[j] = letrasUsuario[i];
          acerto++;
        } else {
          palavraFinal[j] = '_';
        }
      }
    }
    printf("%s", palavraFinal);

    printf("Digite uma letra: ");
    scanf("%c", &letrasUsuario[indiceLetras]);
    indiceLetras++;

    if (acerto == 0) {
      printf("\nVocê errou!\n");
      curErros++;
    } else {
      printf("\nVocê acertou!\n");
    }

    if (curErros >= errosMax) {
      rodando = 0;
    }
    vidas = errosMax - curErros;

    printf("Você tem %d vidas\n\n", vidas);

  } while (rodando == 1);

  return 0;
}
