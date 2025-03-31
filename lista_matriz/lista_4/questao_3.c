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

void criando_mat(int lin, int col, int m[lin][col]){

    int i,j;

    //percorrendo as linhas da matriz
	for (i=0;i<lin;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<col;j++)
		{
			m[i][j] = (i+j)+1;
		}
		
	}

}

void main ()
{
	//declaração de variáveis
	int mat[5][5];

    criando_mat(5, 5, mat);
    
	printf ("\n\nMatriz original:\n\n");
	exibirMatriz (5, 5, mat);

}