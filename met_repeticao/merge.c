#include <stdio.h>

void junta_lista(int lista[6], int inicio, int meio, int fim) {
  int n1 = meio - inicio;
  int n2 = fim - meio;
  int i,j,k, topo_dir=0, topo_esq=0, direita[n2], esquerda[n1];

  for (i = 0; i < n1; i++){
    esquerda[i] = lista[inicio + i];
  }
  for (j = 0; j < n2; j++){
    direita[j] = lista[meio + j];
  }  
  for(k=inicio; k<fim; k++){
    if(topo_esq>=n1){
      lista[k]=direita[topo_dir];
      topo_dir++;
    }
    else if(topo_dir>=n2){
      lista[k]=esquerda[topo_esq];
      topo_esq++;
    }
    else if(esquerda[topo_esq]<direita[topo_dir]){
      lista[k]=esquerda[topo_esq];
      topo_esq++;
    }
    else{
      lista[k]=direita[topo_dir];
      topo_dir++;
    }
    
  }

}

void divide_lista(int lista[6], int inicio, int fim) {
  int meio;
  
  if(fim-inicio>1){
    meio=(fim+inicio)/2;
    divide_lista(lista, inicio, meio);
    divide_lista(lista, meio, fim);
    junta_lista(lista,inicio, meio, fim);
  }
}

void main() {
  int lista[6]={4,9,5,4,8,1};

  divide_lista(lista,0,6);

  printf("Vetor ordenado: ");
  for (int i = 0; i < 6; i++) {
      printf("%d ", lista[i]);
  }
  printf("\n");
}