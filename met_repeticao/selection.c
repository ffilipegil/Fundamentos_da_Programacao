#include <stdio.h>

void ordena(int lista[5]) {
  int i,j, pos_min, aux;

  for(j=0;j<5-1;j++){
  pos_min=j;
    for(i=j;i<5;i++){
      if(lista[i]<lista[pos_min]){
        pos_min=i;
      } 
  }
  if(lista[j]>lista[pos_min]){
      aux=lista[j];
      lista[j]=lista[pos_min];
      lista[pos_min]=aux;
    }
    for (i = 0; i < 5; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
  }
  
}

void main() {
  int lista[5]={1,5,7,8,3};

  ordena(lista);
  
}