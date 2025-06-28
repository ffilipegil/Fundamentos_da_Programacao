#include <stdio.h>

int desc_comuns(char nomeArquivo[], char nomeArquivo2[]){
    FILE *arq,*arq2;
    int num, num2, cont=0;

    arq=fopen(nomeArquivo, "r");

    if(arq){

        while(fscanf(arq, "%d", &num) != EOF){  
            arq2 = fopen(nomeArquivo2, "r");  
            if (!arq2) {
                fclose(arq);
                return -1;
            }
            while(fscanf(arq2, "%d", &num2) != EOF){
                if(num==num2){
                    cont++;
                }
            }
        }

        fclose(arq);
        fclose(arq2);

        return cont;

    }
    else{
        return -1;
    }

}

void main ()
{

  char nomeArquivo[30]="arquivo.txt", nomeArquivo2[30]="arquivoA.txt" ;
  int elem_iguais=0;

  elem_iguais=desc_comuns(nomeArquivo, nomeArquivo2);

    switch (elem_iguais)
	{
		case -1: printf ("\n\tErro na abertura do arquivo.");
		         break;
		         
		case  0: printf ("\n\tOs arquivos não apresentam elementos comuns");
		         break;
				 
		default: printf ("\n\tOs arquivos tem %d elemento(s) comun(s)", elem_iguais);	
   }
  
}