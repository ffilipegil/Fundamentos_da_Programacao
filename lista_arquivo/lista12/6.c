//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int uniao (char nomeArqA[], char nomeArqB[], char nomeArqC[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivoA[30], nomeArquivoB[30], nomeArquivoC[30];
	
	//lendo os nomes dos arquivos
	printf ("Nome do arquivo A: ");
	gets (nomeArquivoA);
	
	printf ("Nome do arquivo B: ");
	gets (nomeArquivoB);
	
	printf ("Nome do arquivo C: ");
	gets (nomeArquivoC);
	
	//chamando a função
	if (uniao (nomeArquivoA, nomeArquivoB, nomeArquivoC) == 1)
	{
		printf ("\n\nArquivo %s gerado com sucesso!\n", nomeArquivoC);
	}
	else
	{
		printf ("\n\nErro na geracao do arquivo %s!\n", nomeArquivoC);
	}
}

//implementação das funções
int uniao (char nomeArqA[], char nomeArqB[], char nomeArqC[])
{
	//declaração de variáveis
	FILE *arqA, *arqB, *arqC;
	int fimA, fimB, valorA, valorB;
	
	//tentando abrir os arquivos
	arqA = fopen (nomeArqA, "r");
	arqB = fopen (nomeArqB, "r");
	arqC = fopen (nomeArqC, "w");
	
	//verificando se houve erro
	if (!arqA || !arqB || !arqC)
	{
		fclose (arqA);
		fclose (arqB);
		fclose (arqC);
		
		return 0;
	}
	else
	{
		//iniciando as variáveis de controle de forma que sinalizem que não chegamos ao final dos arquivos
		fimA = 0;
		fimB = 0;
		
		//lendo o primeiro elemento do arquivo A		
		if (fscanf (arqA, "%d", &valorA) == EOF)
		{
			fimA = 1;
		}
		
		//lendo o primeiro elemento do arquivo B
		if (fscanf (arqB, "%d", &valorB) == EOF)
		{
			fimB = 1;
		}
		
		//enquanto existirem elementos nos dois arquivos
		while (!fimA && !fimB)
		{
			//verificando se o valor do primeiro arquivo é menor
			if (valorA < valorB)
			{
				fprintf (arqC, "%d\n", valorA);
				
				if (fscanf (arqA, "%d", &valorA) == EOF)
				{
					fimA = 1;
				}
			}
			else
			{
				//verificando se o valor do segundo arquivo é menor
				if (valorB < valorA)
				{
					fprintf (arqC, "%d\n", valorB);
					
					if (fscanf (arqB, "%d", &valorB) == EOF)
					{
						fimB = 1;
					}
				}
				else
				{
					//os valores dos dois arquivos são iguais
					fprintf (arqC, "%d\n", valorA);
					
					if (fscanf (arqA, "%d", &valorA) == EOF)
					{
						fimA = 1;
					}
					
					if (fscanf (arqB, "%d", &valorB) == EOF)
					{
						fimB = 1;
					}
				}
			}
		}
		
		//verificando se o primeiro arquivo terminou
		if (fimA == 1)  //ou apenas    if (fimA)
		{
			fprintf (arqC, "%d\n", valorB);
			
			while (fscanf (arqB, "%d", &valorB) != EOF)
			{
				fprintf (arqC, "%d\n", valorB);
			}
		}
		
		//verificando se o segundo arquivo terminou
		if (fimB == 1)  //ou apenas    if (fimB)
		{
			fprintf (arqC, "%d\n", valorA);
			
			while (fscanf (arqA, "%d", &valorA) != EOF)
			{
				fprintf (arqC, "%d\n", valorA);
			}
		}
		
		//fechando os arquivos
		fclose (arqA);
		fclose (arqB);
		fclose (arqC);
		
		return 1;
	}
}