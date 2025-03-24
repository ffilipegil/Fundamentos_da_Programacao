#include <stdio.h>
#include <string.h>

void criando_sub_str(char string[], int p, int n, char substr[]){
    
    int i, j, tam;

    tam=strlen(string);
	
    if ((n <= 0) || (n > tam) || (p < 0) || (p >= tam))
    {
        substr[0]='\0';
    }
    else
    {
        //percorrendo a string
        for (i=p,j=0; (j<n) && (string[i]!='\0');i++,j++)
        {
            substr[j]=string[i];
        }
        substr[j] = '\0';
    }  
	
}

void main (){
    //declaração de variáveis
    char string[20], substr[20];
    int posicao, quant;
        
    //lendo a string
    printf ("Entre com a string: ");
    gets (string);
        
    printf ("\nPosicao onde comeca a substring: ");
	scanf ("%d", &posicao);
	
	printf ("\nQuantidade de caracteres na substring: ");
	scanf ("%d", &quant);
	
	//chamando a função
	criando_sub_str (string, posicao, quant, substr);
	
	//exibindo o resultado
	printf ("\nsubstring = %s.", substr);
}