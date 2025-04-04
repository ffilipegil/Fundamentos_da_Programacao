#include <stdio.h>
#include <string.h>

int conta_distintos(char string[]){
    int i, j, carac_distintos=0;
    char string_aux[20];

    strcpy(string_aux,string);

    for (i=0;string[i]!='\0'; i++)
    {
          if (string[i]!=string[i-1])
        {
          carac_distintos++;

          for(j=0;j<carac_distintos; j++)
          {
            if(string[i]==string_aux[j-1]){
              carac_distintos--;

            }
          }
        }
    }

  return carac_distintos;
}

void main (){
    char string[20], carac_distintos;

    //lendo a string
    printf ("Entre com a string: ");
    gets (string);

    carac_distintos=conta_distintos(string);

    printf ("\nSTRING: %s", string);
    printf ("\nCaracteres Distintos: %d", carac_distintos);
}