#include <stdio.h>

//implementação das funções
int contarCaracter (char nomeArq[], char caracter)
{
  //declaração de variáveis
  FILE* arq;  //passo 1: declarar uma variável FILE*
  char ch;
  int cont=0;

  //passo 2: associar a variável a um arquivo em disco + abrir o arquivo 
  arq = fopen (nomeArq, "r");  //r - read, w - write, a - append

  //passo 3: verificando se o arquivo foi aberto
  if (arq != NULL)   //ou apenas:  if (arq)
  {
    //passo 4: manipulando o arquivo
    while (fscanf (arq, "%c", &ch) != EOF)  //end of file
    {
        if (ch==caracter)
        {
           cont++;
        }
      
    }

    //passo 5: fechar o arquivo
    fclose (arq);

    return cont;
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
  char nomeArquivo[30], caracter;
  int num_carac;

  //lendo os dados
  printf ("Nome do arquivo: ");
  gets (nomeArquivo);
  printf ("Caracter a ser buscado: ");
  scanf(" %c", &caracter);

  num_carac = contarCaracter (nomeArquivo, caracter);

  switch (num_carac)
	{
		case -1: printf ("\n\nErro na abertura do arquivo %s.", nomeArquivo);
		         break;
		         
		case  0: printf ("\n\nO arquivo %s não tem esse caracter!", nomeArquivo);
		         break;
				 
		default: printf ("\n\nHa %d caractere(s) no arquivo %s", num_carac, nomeArquivo);	
   }
  
}