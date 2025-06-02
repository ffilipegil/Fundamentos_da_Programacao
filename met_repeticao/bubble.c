#include <stdio.h>

void ordena(int lista[]) {
  int i,j, pos_min, aux;

  for(j=0;j<5-1;j++){
    for(i=0;i<5-1;i++){
      if(lista[i]>lista[i+1]){
        aux=lista[i];
        lista[i]=lista[i+1];
        lista[i+1]=aux;
      } 
    }
    for (i = 0; i < 5; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
  }
}

void main() {
  int lista[5]={4,9,5,4,8};

  ordena(lista);
}