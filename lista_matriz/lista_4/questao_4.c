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

int verificando_simetria(int lin, int col, int mat[lin][col], int Mt[col][lin]){

  int i,j;

  for ( i = 0; i < lin; i++){
      for (j=0;j<col;j++){
        Mt[j][i] = mat[i][j];
      }
  }

  for (i=0;i<lin;i++){

      for (j=0;j<col;j++)
      {
        if(mat[i][j]!=Mt[i][j]){
          return 0;
        }
      }
    }

  return 1;
}
void main ()
{
  //declaração de variáveis
  int mat[3][3] = {{1,2,3},
                  {2,3,4},
                  {3,4,5}};
  int resp, Mt[3][3];

  printf("Matriz:\n");
  exibirMatriz(3,3,mat);

  resp=verificando_simetria(3,3,mat, Mt);

  if (resp == 1){
    printf ("\nA matriz é simétrica");
  }
  else{
    printf ("\nA matriz não é simétrica");
  }

}