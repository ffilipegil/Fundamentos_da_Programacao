#include <stdio.h>
#include <string.h>

#define TAM 10  // número máximo de palavras

typedef struct {
    char palavra[15];
    int vogais;
    int consoantes;
} Palavra;

int eh_vogal(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void separa_frase(Palavra frase[], char string[]) {
    int i = 0, j = 0, k = 0;
    char c;

    while (string[i] != '\0') {
        c = string[i];

        // se for letra (considerando maiúsculas apenas)
        if ((c >= 'A' && c <= 'Z')) {
            frase[j].palavra[k] = c;

            // conta vogais e consoantes
            if (eh_vogal(c)) {
                frase[j].vogais++;
            } else {
                frase[j].consoantes++;
            }

            k++;
        }
        // se for separador, encerra a palavra atual
        else if (c == ' ' || c == ',' || c == '.' || c == '\n') {
            if (k > 0) {  // só avança se tiver construído alguma palavra
                frase[j].palavra[k] = '\0';  // finaliza a string da palavra
                j++;    // próxima palavra
                k = 0;  // reinicia índice da nova palavra
            }
        }

        i++;
    }

    // finaliza última palavra se não tiver separador no fim
    if (k > 0) {
        frase[j].palavra[k] = '\0';
    }
}

void exibe_string(Palavra frase[]) {
    int i = 0;

    while (strlen(frase[i].palavra) > 0 && i < TAM) {
        printf("\nPalavra %d: %s\n", i + 1, frase[i].palavra);
        printf("Vogais: %d\n", frase[i].vogais);
        printf("Consoantes: %d\n", frase[i].consoantes);
        i++;
    }
}

void main() {
    Palavra frase[TAM];
    char string[100];

    // zera os dados do vetor de structs
    for (int i = 0; i < TAM; i++) {
        frase[i].palavra[0] = '\0';
        frase[i].vogais = 0;
        frase[i].consoantes = 0;
    }

    printf("\nEntre com a frase (apenas maiúsculas): ");
    gets(string);  // permitido conforme o enunciado

    separa_frase(frase, string);
    exibe_string(frase);
}
