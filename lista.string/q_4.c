#include <stdio.h>
#include <string.h>

void rem_caracteres(char string[], char caracter){
    
    int i, j;

    char strAux[strlen(string)+1];

    for (i=0, j=0; string[i]; i++)
    {
        if (string[i] != caracter)
		{
			strAux[j] = string[i];
			j++;
		}
    }
    
    strAux[j] = '\0';
	
	//copiando 'strAux' para a string original
	strcpy (string, strAux);
	
}

void main (){
    //declaração de variáveis
    char string[20], letra;
        
    //lendo a string
    printf ("Entre com a string: ");
    gets (string);

    printf ("\nLetra a ser removida: ");
	scanf ("%c", &letra);

	printf ("\n\nAntes da remocao: %s", string);

	rem_caracteres(string, letra);

	//exibindo a string depois da remoção
	printf ("\n\nDepois da remocao: %s", string);
        
}