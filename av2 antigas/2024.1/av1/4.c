#include <stdio.h>
#include <string.h>

#define TAM 100

// Struct para armazenar os dados dos alunos
typedef struct {
    int matricula;
    char nome[50];
    float av1;
    float av2;
    float media;
} Aluno;

// Função que separa os alunos em vetores distintos
void classificarAlunos(Aluno turma[], int n, Aluno vetAprovados[], int *tamAprov,
                        Aluno vetReprovados[], int *tamReprov,
                        Aluno vetAVF[], int *tamAVF) {
    int i;
    *tamAprov = 0;
    *tamReprov = 0;
    *tamAVF = 0;

    for (i = 0; i < n; i++) {
        turma[i].media = (turma[i].av1 + turma[i].av2) / 2;

        if (turma[i].media >= 6.0) {
            vetAprovados[(*tamAprov)++] = turma[i];
        } else if (turma[i].media < 4.0) {
            vetReprovados[(*tamReprov)++] = turma[i];
        } else {
            vetAVF[(*tamAVF)++] = turma[i];
        }
    }
}

// Função para imprimir os alunos de um vetor
void imprimirVetor(Aluno vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Matrícula: %d | Nome: %s | Média: %.2f\n",
               vetor[i].matricula, vetor[i].nome, vetor[i].media);
    }
}

void main() {
    Aluno turma[TAM], vetAprovados[TAM], vetReprovados[TAM], vetAVF[TAM];
    int n, i;
    int tamAprov, tamReprov, tamAVF;

    printf("Informe o número de alunos: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Matrícula: ");
        scanf("%d", &turma[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]", turma[i].nome); // lê com espaços
        printf("Nota AV1: ");
        scanf("%f", &turma[i].av1);
        printf("Nota AV2: ");
        scanf("%f", &turma[i].av2);
    }

    // Classifica os alunos
    classificarAlunos(turma, n, vetAprovados, &tamAprov,
                      vetReprovados, &tamReprov,
                      vetAVF, &tamAVF);

    // Exibe os resultados
    imprimirVetor(vetAprovados, tamAprov);
    imprimirVetor(vetReprovados, tamReprov);
    imprimirVetor(vetAVF, tamAVF);

}
