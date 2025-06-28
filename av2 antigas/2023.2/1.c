#include <stdio.h>

void ordena(char nomeArq[]){
    FILE *arq, *arq1, *arq2;
    int numero, num_anterior=-1;

    arq=fopen(nomeArq, "r");
    arq1=fopen("novo.txt", "w");
    arq2=fopen("descartados.txt", "w");

    if(arq && arq1 && arq2){
        while(fscanf(arq,"%d", &numero) != EOF){
            if(numero>num_anterior){
                fprintf(arq1,"%d\n", numero);
            }
            else{
                fprintf(arq2,"%d\n", numero);
            }
            num_anterior=numero;
        }

        fclose(arq);
        fclose(arq1);
        fclose(arq2);

        printf("\n\tArquivos gerados com sucesso.\n");

    }
    else{
        printf("\n\tErro ao abir o arquvivo");
    }

}

void main ()
{

  char nomeArquivo[30]="original.txt";

  ordena(nomeArquivo);
  
}