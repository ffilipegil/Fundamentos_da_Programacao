#include <stdio.h>
#include <string.h>

int cria_substring(char string[], char s1[], char s2[], int posicao) {
    int i, j;

    // Verificação se a posição é inválida
    if (posicao < 0 || posicao > strlen(string)) {
        return 0; // posição inválida
    }

    for (i = 0; i < posicao; i++) {
        s1[i] = string[i];
    }
    s1[i] = '\0'; 

    for (j = 0; string[posicao] != '\0'; j++, posicao++) {
        s2[j] = string[posicao];
    }
    s2[j] = '\0'; 

    return 1; 
}

void main() {
    char string[20], s1[20], s2[20];
    int posicao, resp;

    printf("Entre com a string: ");
    gets(string);

    printf("Posição que vai separar a string: ");
    scanf("%d", &posicao);

    resp = cria_substring(string, s1, s2, posicao);

    if (resp == 1) {
        printf("\nString 1: %s\n", s1);
      string2string2printf("\nString 2: %s\n", s2);
    } else {
        printf("\nPosição inválida.\n");
    }
}