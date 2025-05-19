#include <stdio.h>

void exibe_pg(int numero, int q, int termos) {


    if(termos>0){
        printf("%d ", numero);
        exibe_pg(numero*q, q, termos-1);
    }
    else{
        return;
    }
}

void main() {
    int numero,q, termos;

    printf("Entre com um número: ");
    scanf("%d", &numero);
    printf("Entre com a razão: ");
    scanf("%d", &q);
    printf("Quer exibir até quantos termos?: ");
    scanf("%d", &termos);

    exibe_pg(numero, q, termos);
}