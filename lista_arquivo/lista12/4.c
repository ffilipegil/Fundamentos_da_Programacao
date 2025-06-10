#include <stdio.h>

//implementação das funções
int verifOrdem (char nomeArq[])
{
  //declaração de variáveis
  FILE* arq;  //passo 1: declarar uma variável FILE*
  int anterior, atual;

  //passo 2: associar a variável a um arquivo em disco + abrir o arquivo 
  arq = fopen (nomeArq, "r");  //r - read, w - write, a - append

  //passo 3: verificando se o arquivo foi aberto
  if (arq != NULL)   //ou apenas:  if (arq)
  {
    fscanf (arq, "%d", &anterior);
    //passo 4: manipulando o arquivo
    while (fscanf (arq, "%d", &atual) != EOF)  //end of file   
    {

		if (atual<anterior)
		{
            return 0;
		}
        else{
            anterior=atual;
        }
      
    }

    //passo 5: fechar o arquivo
    fclose (arq);

    return 1;
  }
  else
  {
    return -1;
  }	
}

//main
void main ()
{
  //declaração de variáveis
  char nomeArquivo[30];
  int resp;

  printf ("Nome do arquivo: ");
  gets (nomeArquivo);

  resp=verifOrdem(nomeArquivo);

  switch (resp)
	{
		case -1: printf ("\n\nErro na abertura do arquivo %s.", nomeArquivo);
		         break;
		         
		case  0: printf ("\n\nO arquivo %s não está ordenado!", nomeArquivo);
		         break;
				 
		default: printf ("\n\nO arquivo %s está ordenado", nomeArquivo);	
   }
  
}