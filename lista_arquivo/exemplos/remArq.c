//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int removerValoresArquivo (char nomeArq[], int velho);
//int copiarArquivo (char nomeArqOrigem[], char nomeArqDestino[]);

//main
void main ()
{
  //declaração de variáveis
  char nomeArq[30];
  int valor, retorno;

  //lendo os dados
  printf ("Nome do arquivo: ");
  gets (nomeArq);

  printf ("Valor a ser removido: ");
  scanf ("%d", &valor);

  //chamando a função
  retorno = removerValoresArquivo (nomeArq, valor);

  switch (retorno)
  {
    case -1: printf ("\n\nErro na abertura do arquivo!\n");
             break;
    case  0: printf ("\n\nO numero %d nao foi encontrado no arquivo!\n", valor);
             break;
    default: printf ("\n%d remocoes realizadas!", retorno);
  }
}

//implementação das funções
int removerValoresArquivo (char nomeArq[], int velho)
{
  //declaração de variáveis
  FILE *arq, *tmp;
  int numero, cont = 0;

  //abrindo os arquivos
  arq = fopen (nomeArq, "r");
  tmp = fopen ("temp.txt", "w");

  //verificando se houve erro na abertura dos arquivos
  if ((!arq) || (!tmp))
  {
    fclose (arq);
    fclose (tmp);

    return -1;
  }
  else
  {
    //lendo todos os valores do arquivo original
    while (fscanf (arq, "%d", &numero) != EOF)
    {
      //se não for o valor a ser removido...
      if (numero != velho)
      {
        fprintf (tmp, "%d\n", numero);
      }
      else
      {
        //se for o valor a ser removido ...

        cont++;
      }
    }

    //fechando os arquivos
    fclose (arq);
    fclose (tmp);

    //copiando o arquivo temporário para o original
    //copiarArquivo ("temp.txt", nomeArq);

    remove (nomeArq);
    rename ("temp.txt", nomeArq);

    return cont;
  }
}


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