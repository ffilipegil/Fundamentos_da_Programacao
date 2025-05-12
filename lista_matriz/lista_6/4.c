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
void exibirVetor (int tam, int vetor[tam])
{
  int i;

  for (i=0;i<tam;i++)
  {
    printf ("%d ", vetor[i]);
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
void multiplos(int lin, int col, int mat[lin][col], int vet_multiplos_l[lin], int vet_multiplos_c[col]) {
  
  int i, j;

  for(i=0;i<lin;i++){
    vet_multiplos_l[i]=0;
    for(j=1;j<col;j++){
      if(
        mat[i][j]%mat[i][0]==0){
        vet_multiplos_l[i]++;
      }
    }
  }
  for(j=0;j<col;j++){
    vet_multiplos_c[j]=0;
    for(i=1;i<lin;i++){
      if(mat[i][j]%mat[0][j]==0){
        vet_multiplos_c[j]++;
      }
    }
  }

}

void main() {
  int mat[5][5], vet_multiplos_l[5], vet_multiplos_c[5] ;

  preencherMatrizAleatorio(5, 5, mat, 20);

  printf("Matriz:\n");
  exibirMatriz(5, 5, mat);

  multiplos(5, 5, mat, vet_multiplos_l, vet_multiplos_c);

  printf("\nQuantidade de Míltiplos do primeiro número da linha:\n");
  exibirVetor(5, vet_multiplos_l);
  printf("\nQuantidade de Míltiplos do primeiro número da coluna:\n");
  exibirVetor(5, vet_multiplos_c);
}