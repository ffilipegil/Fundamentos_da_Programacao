#include <stdio.h>
#include <string.h>

void gera_substring(char string[],int p,int n, char substring[]){  
  int i, j;

  if(p>strlen(string) || n<1){
    substring[0] = '\0';
  }
  else{
    for (i = p, j = 0; string[i] != '\0' && j < n; i++, j++) {
      substring[j] = string[i];
    }
    substring[i] = '\0';
  }
  
}

void main(){
  //declaração de variáveis
  char string[20], substring[20];
  int resp,p,n;

  //lendo a string
  printf ("Entre com a string: ");
  gets (string);
  
  printf ("Quer começar a substring da onde?: ");
  scanf("%d", &p);
  printf ("Quer ver quantos caracteres?: ");
  scanf("%d", &n);
  //chamando a função 'stringTamanho'
  gera_substring(string,p,n, substring);

  printf ("\nString: %s\n", string);

  printf ("\nSubstring: %s\n", substring);


}