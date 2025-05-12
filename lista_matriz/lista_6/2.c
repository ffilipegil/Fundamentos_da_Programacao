#include <stdio.h>

void exibirMatriz(int lin, int col, int m[lin][col]) {
  // declaração de variáveis
  int i, j;

  // percorrendo as linhas da matriz
  for (i = 0; i < lin; i++) {
    // percorrendo as colunas da matriz
    for (j = 0; j < col; j++) {
      printf("%3d ", m[i][j]);
    }

    printf("\n");
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
void trocando_colunas(int lin, int col, int mat[lin][col], int col1, int col2) {
  int i, col_aux[5],k;

  col1--;
  col2--;

  
  for(k=0; k<=(col2-col1);k++){
      for(i=0;i<lin;i++){
        col_aux[i]=mat[i][col1];
        mat[i][col1]=mat[i][col2];
    
      }
      for(i=0;i<lin;i++){
    
        mat[i][col2]=col_aux[i];
    
      }
      col1++;
      col2--;
      
    }

}

void main() {
  int mat[5][5];
  int col1, col2;

  preencherMatrizAleatorio(5, 5, mat, 100);

  printf("Matriz:\n");
  exibirMatriz(5, 5, mat);

  printf("\n\nColuna que será trocada: ");
  scanf("%d", &col1);

  // lendo o valor a ser buscado na linha
  printf("\nColuna que você deseja trocar pela anterior: ");
  scanf("%d", &col2);

  trocando_colunas(5, 5, mat, col1, col2);

  printf("Matriz Trocada:\n");
  exibirMatriz(5, 5, mat);
}