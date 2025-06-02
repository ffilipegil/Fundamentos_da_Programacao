#include <stdio.h>

int particao(int lista[], int inicio, int fim){
  int pivo=lista[fim];
  int i=inicio, j, aux;

  for(j=inicio;j<fim;j++){
    if(lista[j]<pivo){
      aux=lista[j];
      lista[j]=lista[i];
      lista[i]=aux;
      i++;
    }
  }
    aux=lista[i];
    lista[i]=lista[fim];
    lista[fim]=aux;

    return i;
}

void ordena(int lista[], int inicio, int fim) {
  int pos;
  if(inicio<fim){
    pos=particao(lista,inicio, fim);
    ordena(lista,inicio, pos-1);
    ordena(lista,pos+1, fim);
  }
}

void main() {
  int lista[6]={4,9,5,4,8,1};

  ordena(lista, 0, 5);

  printf("Vetor ordenado: ");
  for (int i = 0; i < 6; i++) {
      printf("%d ", lista[i]);
  }
  printf("\n");
}