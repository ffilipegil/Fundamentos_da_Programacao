#include <stdio.h>
#include <string.h>

int verif_palindromo(char palavra1[], int i, int j) {

    if(i>=j){
        return 1;
    }
    if(palavra1[i]!=palavra1[j]){
        return 0;
    }

    verif_palindromo(palavra1, i+1, j-1);
}

void main() {
    char string1[20];
    int i=0, resp;

    printf ("Entre com a string: ");
    gets (string1);
    int j=strlen(string1)-1;

    resp=verif_palindromo(string1,i,j);

    if(resp==0){
        //exibindo o resultado
        printf ("\n\nA string %s não é um palíndromo!\n\n", string1);
      }
      else{
        printf ("\n\nA string %s é um palíndromo!\n\n", string1);
      }

}