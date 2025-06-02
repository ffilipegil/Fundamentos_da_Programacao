#include <stdio.h>

void ordena(int lista[]) {
    int j,i, num_atual;

    for(i=1;i<6;i++){
        num_atual=lista[i];
        j=i-1;
        while (j>=0 && lista[j]>num_atual)
        {
            lista[j+1]=lista[j];
            j--;
            
        }
        lista[j+1]=num_atual;
       
    }
    for (i = 0; i < 6; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void main() {
  int lista[6]={4,9,5,4,8,1};

  ordena(lista);

}