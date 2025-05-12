#include <stdio.h>
#include <string.h>

int verif_palindromo(char string[]){  
  int i, j;

  for(i=0,j=strlen(string)-1; i<=((strlen(string))/2); i++, j--){     
    if(string[i] != string[j]){      
      return 1;
    }
  }
  return 0;
}

void main(){
  //declaração de variáveis
  char string[20];
  int resp;

  //lendo a string
  printf ("Entre com a string: ");
  gets (string);

  //chamando a função 'stringTamanho'
  resp=verif_palindromo(string);

  if(resp==0){
    //exibindo o resultado
    printf ("\n\nA string %s é um palíndromo!\n\n", string);
  }
  else{
    printf ("\n\nA string %s não é um palíndromo!\n\n", string);
  }
  
}