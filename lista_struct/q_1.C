#include <stdio.h>
#include <string.h>

#define TAM 3

typedef struct{
        char modelo[10];
        char placa[10];
        char marca[10];
        char cor[10];
        float quilometragem;
        int ano;
        float valor;
        char tipo[10];
    } Carros;

void preencherCarros(Carros concecionaria[]){
    int i;

    for (i = 0; i < TAM; i++) {
        printf("\n\tDigite o modelo do carro %d: ", i + 1);
        scanf(" %[^\n]", concecionaria[i].modelo);
        printf("\n\tDigite a placa do carro %d (XXX0X00): ", i + 1);
        scanf(" %[^\n]", concecionaria[i].placa);
        printf("\n\tDigite a marca do carro %d: ", i + 1);
        scanf(" %[^\n]", concecionaria[i].marca); 
        printf("\n\tDigite a cor do carro %d: ", i + 1);
        scanf(" %[^\n]", concecionaria[i].cor); 
        printf("\n\tDigite a quilometragem do carro %d: ", i + 1);
        scanf(" %f", &concecionaria[i].quilometragem); 
        printf("\n\tDigite o ano do carro %d: ", i + 1);
        scanf(" %d", &concecionaria[i].ano); 
        printf("\n\tDigite o valor do carro %d: ", i + 1);
        scanf(" %f", &concecionaria[i].valor); 
        printf("\n\tDigite o tipo do carro %d (Usado ou 0km): ", i + 1);
        scanf(" %[^\n]", concecionaria[i].tipo); 

    }

}

void exibirCarros(Carros concecionaria[], char modelo[], int ano1, int ano2, float valor){
    int i;

     for (int i = 0; i < TAM; i++) {
        if (strcmp(concecionaria[i].modelo, modelo) == 0) {
            if (concecionaria[i].ano >= ano1 && concecionaria[i].ano <= ano2)
            {
                if (concecionaria[i].valor<=valor)
                {
                    printf("\n\tCarro: %s\n\tPlaca: %s\n\tMarca: %s\n\tCor: %s\n\tQuilometragem: %.2f\n\tAno de Fabricação: %d\n\tValor: %.2f\n\tTipo: %s\n", concecionaria[i].modelo, concecionaria[i].placa, concecionaria[i].marca, concecionaria[i].cor, concecionaria[i].quilometragem, concecionaria[i].ano, concecionaria[i].valor, concecionaria[i].tipo);
                }
                
            }
            
        }
    }

}

void reajust_valor(Carros concecionaria[], float porcent_sobre_valor){
    int i;

     for (int i = 0; i < TAM; i++) {
        if (concecionaria[i].quilometragem == 0) {
            concecionaria[i].valor+=(concecionaria[i].valor*(porcent_sobre_valor/100));
            printf("\n\tCarro: %s\n\tPlaca: %s\n\tMarca: %s\n\tCor: %s\n\tQuilometragem: %.2f\n\tAno de Fabricação: %d\n\tValor Reajustado: %.2f\n\tTipo: %s\n", concecionaria[i].modelo, concecionaria[i].placa, concecionaria[i].marca, concecionaria[i].cor, concecionaria[i].quilometragem, concecionaria[i].ano, concecionaria[i].valor, concecionaria[i].tipo);
        }
    }

}

void excluir_veic(Carros concecionaria[], char placa[]) {
    int i, j, encontrado = 0;

    for (i = 0; i < TAM; i++) {
        if (strcmp(concecionaria[i].placa, placa) == 0) {
            encontrado = 1;
            // "Remove" o carro movendo os próximos para trás
            for (j = i; j < TAM - 1; j++) {
                concecionaria[j] = concecionaria[j + 1];
            }

            // Zera o último, pois foi movido
            strcpy(concecionaria[TAM - 1].modelo, "");
            strcpy(concecionaria[TAM - 1].placa, "");
            strcpy(concecionaria[TAM - 1].marca, "");
            strcpy(concecionaria[TAM - 1].cor, "");
            concecionaria[TAM - 1].quilometragem = 0;
            concecionaria[TAM - 1].ano = 0;
            concecionaria[TAM - 1].valor = 0;
            strcpy(concecionaria[TAM - 1].tipo, "");

            printf("\n\tVeículo com placa %s foi removido do estoque.\n", placa);
            break;
        }
    }

    if (!encontrado) {
        printf("\n\tPlaca não encontrada.\n");
    }
    
    printf("\n\tVeículos restantes após remoção:\n");

    for (int i = 0; i < TAM; i++) {
        if (strcmp(concecionaria[i].modelo, "") != 0) {
            printf("\n\tCarro: %s\n\tPlaca: %s\n", concecionaria[i].modelo, concecionaria[i].placa);
        }
    }

}


void main()
{
    Carros concecionaria[TAM];
    char modelo[10], placa[10];
    float valor, porcent_sobre_valor;
    int ano1, ano2;

    preencherCarros(concecionaria);

    printf("\n\tQuer ver qual modelo de carro?: ");
    scanf(" %[^\n]", modelo);
    printf("\n\tA partir de qual ano de fabricação?: ");
    scanf("%d", &ano1);
    printf("\n\tE até qual ano de fabricação?: ");
    scanf("%d", &ano2);
    printf("\n\tAté qual valor(R$)?: ");
    scanf("%f", &valor);

    exibirCarros(concecionaria, modelo, ano1, ano2, valor);
    
    printf("\n\tQuer reajustar o valor dos carros 0k em quantos %?: ");
    scanf("%f", &porcent_sobre_valor);
    
    reajust_valor(concecionaria, porcent_sobre_valor);
    
    printf("\n\tQuer tirar o veículo com qual placa?(XX0X00): ");
    scanf(" %[^\n]", placa);
    
    excluir_veic(concecionaria, placa);


}