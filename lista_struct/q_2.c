#include <stdio.h>

#define TAM 5

typedef struct{
        char nome[10];
        int dia;
        int mes;
    } Data;
    
int quant_mes(Data aniversario[], int mes){
    
    int i, cont=0;
     for (int i = 0; i < TAM; i++) {
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
            printf("Nome: %s", aniversario[i].nome);
        }
    }
}

void main()
{
    Data aniversario[TAM];
    int dia, dia2, mes, mes2, quant, mesConsulta;
    
    for (int i = 0; i < TAM; i++) {
        printf("\nDigite o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", aniversario[i].nome); 

        printf("Digite o dia do aniversário: ");
        scanf("%d", &aniversario[i].dia);

        printf("Digite o mês do aniversário: ");
        scanf("%d", &aniversario[i].mes);
    }
    
    printf("Pessoas que fazem aniversario no mês: ");
    scanf("%d", &mesConsulta);

    quant=quant_mes(aniversario, mesConsulta);
    printf("Quant de pessoas que fazem aniversário no mês %d: %d",mes, quant);
    
    printf("Entre com o dia 1: ");
    scanf("%d", &dia);
    printf("Entre com o mes 1: ");
    scanf("%d", &mes);
    printf("Entre com o dia 2: ");
    scanf("%d", &dia2);
    printf("Entre com o mes 2: ");
    scanf("%d", &mes2);


    exibirPessoas(aniversario, dia, dia2, mes, mes2);

}
