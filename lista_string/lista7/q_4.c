#include <stdio.h>
#include <string.h>

void exclui_carac(char string[], char carac) {  
  int i, j = 0;

  for (i = 0; string[i] != '\0'; i++) {     
    if (string[i] != carac) {
      string[j] = string[i];
      j++;
    }
  }

  string[j] = '\0'; // Finaliza a nova string
}

void main(){
  //declaração de variáveis
  char string[20], carac;

  //lendo a string
  printf ("\n\tEntre com a string: ");
  gets (string);
  printf ("\n\tString: %s", string);
  printf ("\n\tQuer retirar qual caracter?: ");
  scanf("%c", &carac);

  //chamando a função 'stringTamanho'
  exclui_carac(string, carac);

  printf ("\n\tA string ficou assim %s\n", string);

}