#include <stdio.h>

//implementação das funções
void gerando_matriz3(int lin, int col, int m[lin][col], int m2[lin][col]){

    int i,j, soma=0,k;

    for (i=0;i<lin;i++)
	{
		for (j=0;j<col;j++)
		{
			if(m2[i][j]==0){
                m2[i][j]=m[i][j];
            }
            else{
                soma=0;
                for (k=0;k<lin;k++){
		
                    if(m2[i][j]==1){
                    soma+=m[i][k];
                }
                }
                for (k=0;k<col;k++)
                {
                    if(m2[i][j]==1){
                        soma+=m[k][j];
                    }
                }
                soma-=m[i][j];

                m2[i][j]=soma;
            }         
        }
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

//main
void main ()
{
	//declaração de variáveis
	int mat1[5][5];
	int mat2[5][5] = {{0,1,0,1,0},
	                  {1,0,1,0,1},
					  {0,1,0,1,0},
					  {1,0,1,0,1}};
					  
	//preenchendo a matriz 'mat1' com números aleatórios	
	preencherMatrizAleatorio (5,5, mat1, 10);
	
	//exibindo a matriz 'mat1'
    printf ("\nMatriz 1: \n");
	exibirMatriz (5, 5, mat1);

    printf ("\n\nMatriz 2: \n");
    exibirMatriz (5, 5, mat2);
	
	gerando_matriz3(5,5,mat1,mat2);

    printf ("\n\nMatriz 3: \n");
    exibirMatriz (5, 5, mat2);
}