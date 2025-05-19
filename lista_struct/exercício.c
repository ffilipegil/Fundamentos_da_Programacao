#include <stdio.h>
#include <string.h>

typedef struct{
        char nome[10];
        int av1;
        int av2;
        float media;
        int situacao;
    } Aluno;
    
void preencherTurma(Aluno turma[], int n){
    int i;
    
    for(i=0;i<n;i++){
        printf("\n\tDigite o nome do aluno %d: ", i + 1);
        scanf(" %[^\n]", turma[i].nome);

        printf("\n\tDigite a nota da AV1: ");
        scanf("%d", &turma[i].av1);

        printf("\n\tDigite a nota da AV2: ");
        scanf("%d", &turma[i].av2);
    }
}

void calcMedESituacoes(Aluno turma[], int n){
    
    int i;
    
    for(i=0;i<n;i++){
        turma[i].media = (turma[i].av1 + turma[i].av2) / 2.0;
        
         if (turma[i].media >= 6.0) {
            turma[i].situacao = 1;
        } else if (turma[i].media < 4.0) {
            turma[i].situacao = 2;
        } else {
            turma[i].situacao = 3;
        }
    }
}

void exibirSituacao(Aluno turma[], int n, int opcao){
    
    int i;
    
    printf("\n\tAlunos com situação %d:\n", opcao);
    for (int i = 0; i < n; i++) {
        if (turma[i].situacao == opcao) {
            printf("\tNome: %s | Média: %.2f\n", turma[i].nome, turma[i].media);
        }
    }
}

void main()
{
    Aluno turma[10];
    int n, opcao;
    
    printf("\n\tQuantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    preencherTurma(turma, n);
    calcMedESituacoes(turma, n);

    printf("\n\tDigite a situação que deseja consultar:");
    printf("\n\t1 - Aprovado\n\t2 - Reprovado\n\t3 - Em AVF");
    printf("\n\tSua opção: ");
    scanf("%d", &opcao);

    exibirSituacao(turma, n, opcao);

}
