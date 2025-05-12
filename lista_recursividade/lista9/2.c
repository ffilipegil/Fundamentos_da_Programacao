#include <stdio.h>

void trans_binario(int numero) {

int resto;

    if(numero>0){
        resto=numero%2;
        trans_binario(numero/2);
        printf("%d", resto);
    }
    else{
        return;
    }
}

void main() {
    int numero;

    printf("Entre com um número: ");
    scanf("%d", &numero);

    trans_binario(numero);
}
