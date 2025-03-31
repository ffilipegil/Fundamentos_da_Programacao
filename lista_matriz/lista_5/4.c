#include <stdio.h>

//implementação das funções
int verificarOrdenacao (int lin, int col, int m[lin][col])
{
	//declaração de variáveis
	int anterior = m[0][0],	//iniciando 'anterior' com o primeiro elemento da matriz
	    i, j;
	
	//percorrendo as linhas da matriz
	for (i=0;i<lin;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<col;j++)
		{
			//verificando se dois 'elementos desordenados' foram encontrados
			if (m[i][j] < anterior)
			{
				return 0;
			}
			
			//atualizando o anterior
			anterior = m[i][j];
		}
	}
	
	return 1;		
}

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

//main
void main ()
{
	//declaração de variáveis
	int mat1[10][6];
	int mat2[4][3] = {{1,3,4},
	                  {4,5,7},
					  {10,15,18},
					  {18,19,20}};
					  
	//preenchendo a matriz 'mat1' com números aleatórios	
	preencherMatrizAleatorio (10, 6, mat1, 10);
	
	//exibindo a matriz 'mat1'
	exibirMatriz (10, 6, mat1);
	
	//chamando a função para 'mat1'
	if (verificarOrdenacao (10, 6, mat1) == 1)
	{
		printf ("\n\nOs elementos da matriz 1 estao ordenados!\n");
	}
	else
	{
		printf ("\n\nOs elementos da matriz 1 NAO estao ordenados!\n");
	}

	//exibindo a matriz 'mat2'
	exibirMatriz (4, 3, mat2);
	
	//chamando a função para 'mat2'
	if (verificarOrdenacao (4, 3, mat2) == 1)
	{
		printf ("\n\nOs elementos da matriz 2 estao ordenados!\n");
	}
	else
	{
		printf ("\n\nOs elementos da matriz 2 NAO estao ordenados!\n");
	}
}