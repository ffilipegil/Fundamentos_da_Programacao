#include <stdio.h>

int desc_quant_carac(char nomeArquivo[], int elemento){
    FILE* arq;
    int num, cont=0;

    arq=fopen(nomeArquivo, "r");

    if(arq){
        while(fscanf(arq,"%d",&num) != EOF){
            if(num==elemento){
                cont++;
            }
        }

        fclose(arq);

        return cont;
    }
    else{
        return -1;
    }

}

void main ()
{

  char nomeArquivo[20]="clara.txt";
  int quant_carac=0, elemento;

  printf("\n\tQuer saber a ocorrência de qual elemento?: ");
  scanf("%d", &elemento);

  quant_carac=desc_quant_carac(nomeArquivo, elemento);

  switch (quant_carac)
	{
		case -1: printf ("\n\tErro na abertura do arquivo.");
		         break;
		         
		case  0: printf ("\n\tO arquivos não apresenta esse elemento");
		         break;
				 
		default: printf ("\n\tO arquivo tem %d ocorrência(s) desse elemento", quant_carac);	
   }
  
}