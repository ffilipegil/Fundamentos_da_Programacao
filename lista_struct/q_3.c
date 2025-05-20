#include <stdio.h>
#include <string.h>
#define TAM 3

typedef struct{
        char nome[10];
        int matricula;
        char genero;
        float salario;
    } Funcionario;

void lerFuncionarios(Funcionario empresa[]){
    int i;

    for(i=0;i<TAM;i++){
      
      printf("\n\tMatrícula do funcionário: ");
      scanf("%d", &empresa[i].matricula);    
      printf("\n\tDigite o nome do funcionário %d: ",empresa[i].matricula);
      scanf(" %[^\n]", empresa[i].nome);
      printf("\n\tGenero do funcionário %d(M ou F): ",empresa[i].matricula);
      scanf(" %c", &empresa[i].genero);
      printf("\n\tSalário do funcionário %d: ",empresa[i].matricula );
      scanf("%f", &empresa[i].salario);
    }
}
void exibePorGenero(Funcionario empresa[], char genero){
  int i, j=0;
  Funcionario temp;
  
  for (i = 0; i < TAM; i++) {
    if (empresa[i].genero == genero) {
        temp = empresa[i];
        empresa[i] = empresa[j];
        empresa[j] = temp;
        j++;
    }
  }

  printf("\nFuncionários após reordenar pelo gênero '%c':\n", genero);
  for (i = 0; i < TAM; i++) {
    printf("\t%d - %s - %c - R$ %.2f\n",
           empresa[i].matricula,
           empresa[i].nome,
           empresa[i].genero,
           empresa[i].salario);
  }
}
void main()
{
  Funcionario empresa[TAM];
  char genero;

  lerFuncionarios(empresa);

  printf("\n\tQuer saber a ordem dos funcionários por qual genero?(M ou F): ");
  scanf(" %c", &genero);

  exibePorGenero(empresa, genero);

}