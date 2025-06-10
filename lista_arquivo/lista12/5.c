#include <stdio.h>

//implementação das funções
int desc_maior(char nomeArqO[], int limite, int *valor){

  FILE* arqO;  //passo 1: declarar uma variável FILE*
  int maior=-1,numero, alterouMaior;

  //passo 2: associar a variável a um arquivo em disco + abrir o arquivo 
  //r - read, w - write, a - append
  arqO = fopen (nomeArqO, "r");

  //passo 3: verificando se o arquivo foi aberto
  if (arqO != NULL)   //ou apenas:  if (arq)
  { 
    //passo 4: manipulando o arquivo
    while (fscanf (arqO, "%d", &numero) != EOF)  //end of file   
        {
        if (numero<limite)
        {
            if (numero>maior)
            {
                maior = numero;
					
				alterouMaior = 1;
            }
        }
        
    }
    //passo 5: fechar o arquivo
    fclose (arqO);

  }
  else
  {
    printf ("\n\nErro na abertura do arquivo.");
  }
  if (alterouMaior == 1)
	{
	  *valor = maior;
	  return 1;
	}
  else
  {
	return 0;
  }	
}

void ordena (char nomeArqO[], char nomeArqD[])
{
  //declaração de variáveis
  FILE* arqD;  //passo 1: declarar uma variável FILE*
  int valor, limite=99999;

  //passo 2: associar a variável a um arquivo em disco + abrir o arquivo 
  //r - read, w - write, a - append
  arqD = fopen (nomeArqD, "w");

  //passo 3: verificando se o arquivo foi aberto
  if (arqD != NULL)   //ou apenas:  if (arq)
  {
    
    //passo 4: manipulando o arquivo
    while (desc_maior(nomeArqO, limite, &valor)==1)
    {      
        
        fprintf (arqD, "%d\n", valor);

        limite=valor;
    }
    //passo 5: fechar o arquivo
    fclose (arqD);

    printf ("\n\nOrdenação bem sucedida!");
  }
  else
  {
    printf ("\n\nErro na abertura do arquivo.");
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