#include <stdio.h>

//protótipos das funções
int lerArquivo (char nomeArq[]);

//main
void main ()
{
  //declaração de variáveis
  char nomeArquivo[30];

  //lendo os dados
  printf ("Nome do arquivo: ");
  gets (nomeArquivo);

  if (lerArquivo (nomeArquivo) == 0)
  {
    printf ("\n\nErro na abertura do arquivo %s!\n", nomeArquivo);
  }
}

//implementação das funções
int lerArquivo (char nomeArq[])
{
  //declaração de variáveis
  FILE* arq;  //passo 1: declarar uma variável FILE*
  char ch;

  //passo 2: associar a variável a um arquivo em disco + abrir o arquivo 
  arq = fopen (nomeArq, "r");  //r - read, w - write, a - append

  //passo 3: verificando se o arquivo foi aberto
  if (arq != NULL)   //ou apenas:  if (arq)
  {
    //passo 4: manipulando o arquivo
    while (fscanf (arq, "%c", &ch) != EOF)  //end of file
    {
      printf ("%c", ch);
    }

    //passo 5: fechar o arquivo
    fclose (arq);

    return 1;
  }
  else
  {
    return 0;
  }	
}