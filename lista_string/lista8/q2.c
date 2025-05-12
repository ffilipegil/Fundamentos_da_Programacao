#include <stdio.h>
#include <string.h>

void cria_string(char string[], char string2[], char string3[]){
  int i, j, diferente, k = 0, repetido;

  for (i = 0; string[i] != '\0'; i++) {
    diferente = 0;
    for (j = 0; string2[j] != '\0'; j++) {
      if (string[i] != string2[j]) {
        diferente++;
      }
    }
    if (diferente == strlen(string2)) {

      repetido = 0;
      for (j = 0; j < k; j++) {
        if (string[i] == string3[j]) {
          repetido = 1;
          break;
        }
      }
      if (!repetido) {
        string3[k] = string[i];
        k++;
      }
    }
  }
  string3[k] = '\0';
}

void main(){
  //declaração de variáveis
  char string[20], string2[20], string3[20];

  //lendo a string
  printf ("Entre com a string: ");
  gets (string);
  printf ("Entre com outra string: ");
  gets (string2);

  cria_string(string,string2, string3);
  
  printf ("\nString 3: %s\n", string3);
}