#include <stdio.h>

void exibirMatriz (int lin, int col, int m[lin][col])
{
  //declaração de variáveis
  int i, j;

  //percorrendo as linhas da matriz
  for (i=0;i<lin;i++)
  {
    //percorrendo as colunas da matriz
    for (j=0;j<col;j++)
    {
      printf ("%3d ", m[i][j]);
    }

    printf ("\n");
  }
}

void preencherMatrizAleatorio (int lin, int col, int m[lin][col], int limite)
{
  //declaração de variáveis
  int i, j;

  srand(time(NULL));

  //percorrendo as linhas da matriz
  for (i=0;i<lin;i++)
  {
    //percorrendo as colunas da matriz
    for (j=0;j<col;j++)
    {
      m[i][j] = rand()%limite;
    }
  }	
}

int troca_col(int lin, int col, int m[lin][col], int coluna1, int coluna2){
    int i,i2, aux[i];

  if((coluna1<0) || (coluna2<0) || (coluna1>=col) || (coluna2>=col)){
        return 0;
  }

  for (i=0;i<lin;i++)
  {
    aux[i] = m[i][coluna1];
  }
  for (i=lin, i2=0;i>=0;i--,i2++)
  {
    m[i][coluna1] = m[i2][coluna2];
  }
  for (i=0;i<lin;i++)
  {
    m[i][coluna2] = aux[i];
  }

  return 1;
}

void main ()
{
  //declaração de variáveis
  int mat[5][5], coluna1, coluna2, confirma_troca;

  preencherMatrizAleatorio(5,5,mat,100);

  exibirMatriz (5, 5, mat);

    printf ("\nDigite o número da coluna que você quer trocar: ");
    scanf("%d", &coluna1);
    printf ("\nDigite o número da outra coluna que você quer trocar: ");
    scanf("%d", &coluna2);

    confirma_troca =troca_col(5,5,mat,coluna1,coluna2);

    printf("\n %d", confirma_troca);
  printf ("\n\nMatriz com a troca:\n\n");
  exibirMatriz (5, 5, mat);

}
