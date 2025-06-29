#include <stdio.h>

int desc_maior(char nomeArqO[], int limite, int *valor){
  FILE* arqO;
  int maior=-1, numero, alterouMaior;

  arqO=fopen(nomeArqO,"r");

  if(arqO){
    while(fscanf(arqO, "%d", &numero) != EOF){
      if(numero<limite){
        if(numero>maior){
          maior=numero;
          alterouMaior=1;
        }
      }
    }
    fclose(arqO);
  }
  else{
    printf("\n\nErro na abertura do arquivo.");
  }

  if(alterouMaior==1){
    *valor=maior;
    return 1;
  }
  else{
    return 0;
  }

}

void ordena(char nomeArqO[], char nomeArqD[]){
  FILE* arqD;
  int limite=999999, valor;

  arqD=fopen(nomeArqD, "w");

  if(arqD){
    while(desc_maior(nomeArqO, limite, &valor)==1){
      fprintf(arqD, "%d\n", valor);
      limite=valor;
    }
    9

    printf("\n\tOrdenação bem sucedida");
  }
  else{
    printf("\n\tErro na abertura");
  }

}

//main
void main ()
{
  //declaração de variáveis
  char nomeArquivo[30], nomeArquivo2[30];

  printf ("Nome do arquivo origem: ");
  gets (nomeArquivo);
  printf ("Nome do arquivo destino: ");
  gets (nomeArquivo2);

  ordena(nomeArquivo, nomeArquivo2);
  
}