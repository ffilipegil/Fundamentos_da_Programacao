#include <stdio.h>

int stringTamanho(char string[]){  
  int i, cont=0;
  
  for(i=0; string[i] != '\0'; i++){ 
    cont++;
  }
  
  return cont;
}

void stringCopia(char str1[], char str2[]){
  int i;

  for(i=0; str2[i] != '\0'; i++){ 
    str1[i]=str2[i];
  }

  str1[i] = '\0'; 
  
}

void stringConcatena(char str1[], char str2[]){
  int i,j;

  for (i=stringTamanho(str1),j=0;str2[j]!='\0';i++,j++)
    {
      str1[i] = str2[j];
    }
    
    str1[i] = '\0'; 
  
}


int stringComparacao(char str1[], char str2[]){
  int i;

  for (i=0; str1[i]!='\0' || str2[i]!='\0';i++)
    {
      if (str1[i] < str2[i])
        {
          return -1;
        }
        else if(str1[i] > str2[i])
        {
          return 1;
        }
    }

  str1[i] = '\0'; 
  
  return 0;

}  

void main ()
{
  //declaração de variáveis
  char string1[20], string2[20], string3[20], string4[20];
  int quant, resp;

  //lendo a string
  printf ("Entre com a string: ");
  gets (string1);

  //chamando a função 'stringTamanho'
  quant = stringTamanho (string1);

  //exibindo o resultado
  printf ("\n\nA string %s possui %d caracteres!\n\n", string1, quant);

  //lendo outra string
  printf ("Entre com outra string: ");
  gets (string2);

  //chamando a função 'stringCopia'
  stringCopia (string3, string2);

  //exibindo as strings
  printf ("\n\nApos a copia: string1 = %s, string2 = %s, string3 = %s\n\n", string1, string2, string3);

  //chamando a função 'stringConcatena'
  stringConcatena (string3, string1);

  //exibindo as strings
  printf ("\n\nApos a concatenacao: string1 = %s, string2 = %s, string3 = %s\n\n", string1, string2, string3);

  //copiando string2 para string4
  stringCopia (string4, string2);

  //testando a função 'stringComparacao'
  printf ("\nComparando %s com %s: %d\n", string1, string2, stringComparacao(string1, string2));
  printf ("\nComparando %s com %s: %d\n", string4, string2, stringComparacao(string4, string2));
  printf ("\nComparando %s com %s: %d\n", string2, string3, stringComparacao(string2, string3));

}