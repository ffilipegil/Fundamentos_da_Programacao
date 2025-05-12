#include <stdio.h>

void desc_multiplos(int numero_inicial, int valor, int atual) {
    if (atual > valor) {
        return; // Caso base: parou
    }
    else {
        printf("%d ", atual); // Exibe o múltiplo atual
        desc_multiplos(numero_inicial, valor, atual + numero_inicial); // Chamada recursiva
    }
}

void main() {
    int numero, valor;

    printf("Quer saber os múltiplos de qual número?: ");
    scanf("%d", &numero);
    printf("Até qual valor?: ");
    scanf("%d", &valor);

    printf("\n\tMúltiplos: ");
    desc_multiplos(numero, valor, numero); // inicializa atual = numero
    printf("\n");
}
