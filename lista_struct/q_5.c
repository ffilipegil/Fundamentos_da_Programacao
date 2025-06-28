#include <stdio.h>
#include <string.h>

#define TAM 3

typedef struct{
        char nome[10];
        char genero;
        int idade;
    } Pessoas;

void preencher_grupo(Pessoas grupinho[]){
    int i;

    for (i = 0; i < TAM; i++) {
        printf("\n\tDigite o nome da pessoa %d: ", i + 1);
        gets (grupinho[i].nome);
        printf("\n\tDigite a idade da pessoa %d: ", i + 1);
        scanf(" %d", &grupinho[i].idade);
        printf("\n\tDigite o genero da pessoa %d (M ou F): ", i + 1);
        scanf(" %c", &grupinho[i].genero);
        getchar();

    }
}

int verif_ordem(Pessoas grupinho[]){
    int i, aux;

    for (i = 0; i < TAM-1; i++) {
        if(grupinho[i].idade>grupinho[i+1].idade){
            return 0;
        }
        if(grupinho[i].idade==grupinho[i+1].idade){
            if(strcmp(grupinho[i].nome, grupinho[i+1].nome) > 0){
                return 0;
            }
        }
    }

    return 1;
}

void main(){
    Pessoas grupinho[TAM];
    int resp;

    preencher_grupo(grupinho);

    resp=verif_ordem(grupinho);

    if(resp==1){
        printf("\n\tO grupinho esta ordenado");
    }
    else{
        printf("\n\tO grupinho nao esta ordenado");
    }
}