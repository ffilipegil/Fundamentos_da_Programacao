#include <stdio.h>

void cria_arq(char nomeArquivo[], int a, int b){
    FILE *arq, *arq2, *arq3, *arq4;
    int i, num, anterior;

    arq=fopen(nomeArquivo, "r");
    arq2=fopen("menorA.txt", "w");
    arq3=fopen("maiorB.txt", "w");
    arq4=fopen("entreAB.txt", "w");

    if(arq || arq2 || arq3 || arq4){

        while(fscanf(arq, "%d", &num) != EOF){
            if(num<a && num!=anterior){
                fprintf(arq2, "%d\n", num);
            }
            else if(num>b && num!=anterior){
                fprintf(arq3, "%d\n", num);
            }
            else if(num!=anterior){
                fprintf(arq4, "%d\n", num);
            }
            anterior=num;
        }

        fclose (arq);
        fclose (arq2);
        fclose (arq3);
        fclose (arq4);

    }
    else{
        printf("\n\tErro na abertura do arquivo");
    }
}

void main ()
{

  char nomeArquivo[30]="clara.txt";
  int a,b;

  printf("\n\tDigite o elemento A: ");
  scanf("%d", &a);
  printf("\n\tDigite o elemento B: ");
  scanf("%d", &b);

  cria_arq(nomeArquivo, a, b);
  
}