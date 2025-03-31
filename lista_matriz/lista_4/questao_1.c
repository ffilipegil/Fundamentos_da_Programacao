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

void transposta(int lin, int col, int M[lin][col], int Mt[col][lin]){
    
    int i,j;

    for ( i = 0; i < lin; i++)
    {
        for (j=0;j<col;j++)
		{
			Mt[j][i] = M[i][j];
		}
    }
    
}

void main ()
{
	//declaração de variáveis
	int mat[10][5], matT[5][10];

	//preenchendo a matriz 'mat' de forma aleatória
	preencherMatrizAleatorio (10, 5, mat, 100);
	
	//chamando a função
	transposta (10, 5, mat, matT);
	
	//exibindo as matrizes
	printf ("\n\nMatriz original:\n\n");
	exibirMatriz (10, 5, mat);

	printf ("\n\nMatriz transposta:\n\n");
	exibirMatriz (5, 10, matT);
}