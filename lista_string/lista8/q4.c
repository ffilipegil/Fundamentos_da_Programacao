#include <stdio.h>
#include <string.h>

int retirando_interv(char string[], int posicao1, int posicao2) {
    int i, j;

    posicao1--;
    posicao2--;

    // Verificação se a posição é inválida
    if ((posicao1 < 0) || (posicao1 > strlen(string)) || (posicao2 < 0) || (posicao2 > strlen(string))) {
        return 0; // posição inválida
    }

    // Começar a copiar pulando o intervalo
    for (i = posicao1, j = posicao2 + 1; string[j] != '\0'; i++, j++) {
        string[i] = string[j];
    }
    string[i] = '\0'; // finalizar a nova string

    return 1; 
}

void main() {
    char string[20];
    int posicao1, posicao2, resp;

    printf("Entre com a string: ");
    gets(string);

    printf("Posição inicial do intervalo de rerirada: ");
    scanf("%d", &posicao1);
    printf("Posição inicial do intervalo de rerirada: ");
    scanf("%d", &posicao2);

    resp = retirando_interv(string, posicao1, posicao2);

    if (resp == 1) {
        printf("\nString: %s\n", string);
    } else {
        printf("\nPosição inválida.\n");
    }
}