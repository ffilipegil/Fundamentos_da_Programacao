//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int copiarArquivo (char nomeArqOrigem[], char nomeArqDestino[]);

//main
void main ()
{
  //declaração de variáveis
  char nomeArqOrigem[30], nomeArqDestino[30];

  //lendo os dados
  printf ("Nome do arquivo origem: ");
  gets (nomeArqOrigem);

  fflush (stdin);

  printf ("Nome do arquivo origem: ");
  gets (nomeArqDestino);

  if (copiarArquivo (nomeArqOrigem, nomeArqDestino) == 0)
  {
    printf ("\n\nErro na abertura dos arquivos!\n");
  }
  else
  {
    printf ("\n\nCopia realizada com sucesso!\n");
  }
}

//implementação das funções
int copiarArquivo (char nomeArqOrigem[], char nomeArqDestino[])
{
  //declaração de variáveis
  FILE *arqO, *arqD;  //passo 1: declarar uma variável FILE*
  char ch;

  //passo 2: associar a variável a um arquivo em disco + abrir o arquivo 
  arqO = fopen (nomeArqOrigem, "r");  //r - read, w - write, a - append
  arqD = fopen (nomeArqDestino, "w"); 

  //passo 3: verificando se o arquivo foi aberto
  if (arqO && arqD)   //ou apenas:  if (arq)
  {
    //passo 4: manipulando o arquivo
    while (fscanf (arqO, "%c", &ch) != EOF)  //end of file
    {
      fprintf (arqD, "%c", ch);
    }

    //passo 5: fechar o arquivo
    fclose (arqO);
    fclose (arqD);

    return 1;
  }
  else
  {
    /*if (!arqO)
    {
      fclose (arqD);
    }

    if (!arqD)
    {
      fclose (arqO);
    }*/

    fclose (arqO);
    fclose (arqD);

    return 0;
  }	
}