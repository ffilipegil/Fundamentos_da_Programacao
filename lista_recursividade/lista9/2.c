#include <stdio.h>

void transf_binario(int numero) {

int resto;

    if(numero>0){
        resto=numero%2;
        transf_binario(numero/2);
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

    transf_binario(numero);
}
