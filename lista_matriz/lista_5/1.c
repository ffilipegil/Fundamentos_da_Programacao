#include <stdio.h>

//implementação das funções
int somaElementosMatriz (int n, int matriz[n][n])
{
	//declaração de variáveis
	int i, j, somaAbaixo = 0, somaAcima = 0, somaDiagonal = 0;
	
	//varrendo as linhas da matriz
	for (i=0;i<n;i++)
	{
		//varrendo as colunas da matriz
		for (j=0;j<n;j++)
		{
			//verificando se o elemento m[i][j] está abaixo da diagonal principal
			if (i > j)
			{
				somaAbaixo += matriz[i][j];
			}
			else
			{
				//verificando se o elemento m[i][j] está acima da diagonal principal
				if (j > i)
				{
					somaAcima += matriz[i][j];
				}
				else
				{
					//o elemento m[i][j] pertence à diagonal principal
					somaDiagonal += matriz[i][j];
				}
			}
		}
	}
	
	//verificando se as somas são iguais
	if ((somaAbaixo == somaAcima) && (somaAbaixo == somaDiagonal))
	{
		return 1;
	}
	else
	{
		return 0;
	}
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

void main ()
{
	//declaração de variáveis
	int mat1[6][6];
	int mat2[5][5] = {{6,3,1,2,6},
	                  {1,3,5,4,2},
					  {3,4,4,2,2},
					  {5,9,1,9,3},
					  {4,0,2,1,8}};
					  
	//preenchendo a matriz 'mat1' com números aleatórios	
	preencherMatrizAleatorio (6, 6, mat1, 10);
	
	//exibindo a matriz 'mat1'
	exibirMatriz (6, 6, mat1);
	
	//chamando a função para 'mat1'
	if (somaElementosMatriz (6, mat1) == 1)
	{
		printf ("\n\nA matriz 1 atende a regra apresentada!\n");
	}
	else
	{
		printf ("\n\nA matriz 1 NAO atende a regra apresentada!\n");
	}
	
	//exibindo a matriz 'mat2'
	exibirMatriz (5, 5, mat2);
	
	//chamando a função para 'mat2'
	if (somaElementosMatriz (5, mat2) == 1)
	{
		printf ("\n\nA matriz 2 atende a regra apresentada!\n");
	}
	else
	{
		printf ("\n\nA matriz 2 NAO atende a regra apresentada!\n");
	}
}