#include <stdio.h>
#include <string.h>

int verif_palindromo(char string[]){
    int i, j;
	
	//percorrendo a string
	for (i=0,j=strlen(string)-1;i<j;i++,j--)
	{
		if (string[i] != string[j])
		{
			return 0;
		}
	}
	
	return 1;
}

void main ()
{
    {
        //declaração de variáveis
        char string[20];
        
        //lendo a string
        printf ("Entre com a string: ");
        gets (string);
        
        //chamando a função
        //if (palindromo (string) == 1)  
        //ou apenas:
        if (verif_palindromo(string))
        {
            printf ("\nA string %s e um palindromo!\n", string);
        }
        else
        {
            printf ("\nA string %s não e um palindromo!\n", string);
        }
    }
	
}
