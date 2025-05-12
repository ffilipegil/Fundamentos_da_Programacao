#include <stdio.h>
#include <string.h>

int verif_distintos(char string[],int carac_distintos){  
  int i, j, aux_string[20], cont;
  
 
  for (i = 0; string[i] != '\0'; i++) {
    if(string[i]!=string[i-1]){
      carac_distintos++;
      aux_string[i]=string[i];
      cont=0;
      for(j=0;aux_string[j] != '\0';j++){
        if(aux_string[j]==string[i]){
          cont++;
          if(cont>1){
            carac_distintos--;

          }
        }
      }
    }
  }
  return carac_distintos;
}

void main(){
  //declaração de variáveis
  char string[20];
  int carac_distintos=0;

  //lendo a string
  printf ("Entre com a string: ");
  gets (string);

  //chamando a função 'stringTamanho'
  carac_distintos=verif_distintos(string,carac_distintos);

  printf ("\nA String: %s\n", string);
  printf ("\nTem %d carcteres distintos\n", carac_distintos);

}