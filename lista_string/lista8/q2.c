#include <stdio.h>
#include <string.h>

void criaStringFiltrada(const char *s1, const char *s2, char *s3) {
    int i, j, k, repetido;
    int pos = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        // Verifica se o caractere de s1 está em s2
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                break;
            }
        }

        // Se chegou ao fim de s2 sem encontrar o caractere, ele pode ser adicionado
        if (s2[j] == '\0') {
            repetido = 0;
            // Verifica se o caractere já foi adicionado a s3
            for (k = 0; k < pos; k++) {
                if (s3[k] == s1[i]) {
                    repetido = 1;
                    break;
                }
            }
            // Se não for repetido, adiciona a s3
            if (!repetido) {
                s3[pos++] = s1[i];
            }
        }
    }
    s3[pos] = '\0'; // Finaliza a string
}

int main() {
    char s1[100], s2[100], s3[100];

    printf("Digite a primeira string (s1): ");
    gets (s1);

    printf("Digite a segunda string (s2): ");
    gets (s2);

    criaStringFiltrada(s1, s2, s3);

    printf("\nString resultante (s3): %s\n", s3);

    return 0;
}
