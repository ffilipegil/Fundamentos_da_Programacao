#include <stdio.h>

#define TAM 5

typedef struct{
        char nome[10];
        int dia;
        int mes;
    } Data;

void preencherDatas(Data aniversario[]){
    int i;
    
    for (i = 0; i < TAM; i++) {
        printf("\n\tDigite o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", aniversario[i].nome); 

        printf("\tDigite o dia do aniversário: ");
        scanf("%d", &aniversario[i].dia);

        printf("\tDigite o mês do aniversário: ");
        scanf("%d", &aniversario[i].mes);
    }
    
}
    
int quant_mes(Data aniversario[], int mes){
    
    int i, cont=0;

    for (i = 0; i < TAM; i++) {
        if (aniversario[i].mes == mes) {
            cont++;
        }
    }
    
    return cont;
}

void exibirPessoas(Data aniversario[],int dia, int dia2, int mes, int mes2){
    int i;
    
     for (int i = 0; i < TAM; i++) {
        if (aniversario[i].dia >= dia && aniversario[i].mes >= mes && aniversario[i].dia <= dia2 && aniversario[i].mes <= mes2) {
            printf("\n\tNome: %s", aniversario[i].nome);
        }
    }
}

void main()
{
    Data aniversario[TAM];
    int dia, dia2, mes, mes2, quant, mesConsulta;

    preencherDatas(aniversario);
    
    printf("\n\tPessoas que fazem aniversario no mês: ");
    scanf("%d", &mesConsulta);

    quant=quant_mes(aniversario, mesConsulta);
    printf("\n\tQuantidade de pessoas que fazem aniversário no mês %d: %d",mesConsulta, quant);

    printf("\n\n\tEntre com as datas para exibir quem faz aniversário em um determinado intervalo!");
    printf("\n\tEntre com o dia inicial: ");
    scanf("%d", &dia);
    printf("\tEntre com o mes inicial: ");
    scanf("%d", &mes);
    printf("\tEntre com o dia final: ");
    scanf("%d", &dia2);
    printf("\tEntre com o mes final: ");
    scanf("%d", &mes2);


    exibirPessoas(aniversario, dia, dia2, mes, mes2);

}
