#include <stdio.h>

void main() {
  int i;
  FILE *arq;

  //passo 2: associar a variável a um arquivo em disco + abrir o arquivo 
  arq = fopen ("teste.txt", "r");  //r - read, w - write, a - append

  //passo 3: verificando se o arquivo foi aberto
    if (arq != NULL)   //ou apenas:  if (arq)
    {
      //passo 4: manipulando o arquivo

      for (i=1;i<=1000;i++)
      {
        fprintf (arq, "%d\n", i);
      }

      //passo 5: fechar o arquivo
      fclose (arq);
    }
    else
    {
      printf ("\n\nErro na abertura do arquivo!");
    }
  
}