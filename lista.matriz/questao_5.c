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

void exibirVetor(int tam, int soma_col[tam])
{
	//declaração de variáveis
	int i;
	
	//percorrendo as linhas da matriz
	for (i=0;i<tam;i++)
	{	
		printf ("%d ", soma_col[i]);
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

void soma_colunas(int lin, int col, int m[lin][col], int soma_col[col]){

    int i,j;

    //percorrendo as coluas da matriz
	for (j=0;j<col;j++)
	{
        soma_col[j]=0;
		//percorrendo as linhas da matriz
		for (i=0;i<lin;i++)
		{
			soma_col[j]+=m[i][j];
		}
	}

}

void main ()
{
	//declaração de variáveis
	int mat[10][5], soma_col[5];

    //preenchendo a matriz 'mat' de forma aleatória
	preencherMatrizAleatorio (10, 5, mat, 100);

    soma_colunas(10, 5, mat, soma_col);

    printf ("\n\nVetor Soma das Colunas:\n\n");
	exibirVetor (5, soma_col);
    
	printf ("\n\nMatriz original:\n\n");
	exibirMatriz (10, 5, mat);

}