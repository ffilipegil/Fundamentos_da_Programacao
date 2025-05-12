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

int busca_num(int lin, int col, int m[lin][col], int num, int linha){

    int j;

    linha--;

   //percorrendo as colunas da "linha"
	for (j=0;j<col;j++){

		if (m[linha][j] == num){
                return 1;
        }
            
	}
	
    return 0;
}

void main ()
{
	//declaração de variáveis
	int mat[10][5], linha, num, resp;

	//preenchendo a matriz 'mat' de forma aleatória
	preencherMatrizAleatorio (10, 5, mat, 100);
	
    //lendo a linha desejada
	printf ("\n\nLinha: ");
	scanf ("%d", &linha);
	
	//lendo o valor a ser buscado na linha
	printf ("\n\nValor a ser buscado: ");
	scanf ("%d", &num);

	//chamando a função
    resp = busca_num(10, 5, mat, num, linha);

    if (resp = 1){
        printf ("\nO número foi encontrado");
    }
    else{
        printf ("\nO número não foi achado");
    }
    
    //exibindo as matrizes
    
	printf ("\n\nMatriz original:\n\n");
	exibirMatriz (10, 5, mat);

}