#include <stdio.h>

//protótipos das funções
int escreverArquivo (char nomeArq[], int a, int b);

//main
void main ()
{
  //declaração de variáveis
  int valor1, valor2;
  char nomeArquivo[30];

  //lendo os dados
  printf ("Nome do arquivo: ");
  gets (nomeArquivo);

  printf ("Entre com o intervalo: ");
  scanf ("%d %d", &valor1, &valor2);

  if (escreverArquivo (nomeArquivo, valor1, valor2) == 1)
  {
    printf ("\n\nArquivo %s criado com sucesso!\n", nomeArquivo);
  }	
  else
  {
    printf ("\n\nErro na abertura do arquivo %s!\n", nomeArquivo);
  }
}

//implementação das funções
int escreverArquivo (char nomeArq[], int a, int b)
{
  //declaração de variáveis
  int i;
  FILE* arq;  //passo 1: declarar uma variável FILE*

  //passo 2: associar a variável a um arquivo em disco + abrir o arquivo 
  arq = fopen (nomeArq, "w");  //r - read, w - write, a - append

  //passo 3: verificando se o arquivo foi aberto
  if (arq != NULL)   //ou apenas:  if (arq)
  {
    //passo 4: manipulando o arquivo

    for (i=a;i<=b;i++)
    {
      fprintf (arq, "%d\n", i);
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