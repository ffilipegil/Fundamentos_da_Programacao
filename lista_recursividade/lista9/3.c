#include <stdio.h>

void trans_binario(int numero, int q, int termos) {


    if(termos>0){
        printf("%d ", numero);
        trans_binario(numero*q, q, termos-1);
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

    trans_binario(numero, q, termos);
}