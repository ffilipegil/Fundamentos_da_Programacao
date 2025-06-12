#include <stdio.h>
#include <string.h>

#define TAM 10

typedef struct{;
        int cod_curso;
        float nota_enade;
        float idd;
        float doutores;
        float mestres;
        float regime_trabalho;
        float organizacao;
        float infraestrutura;
        float oportunidades;
        int num_alunos;
        float cpc_cont;
        int cpc_faixa;
        char classf[15];
    } Cursos;

void preencher_cursos(Cursos faeterj[]){
    FILE* cursos;
    int i=0;

    cursos=fopen ("cursos.txt", "r");

    if (cursos != NULL)  
    {
    while (i<TAM && fscanf(cursos, "%d|%f|%f|%f|%f|%f|%f|%f|%f|%d",
                  &faeterj[i].cod_curso,
                  &faeterj[i].nota_enade,
                  &faeterj[i].idd,
                  &faeterj[i].doutores,
                  &faeterj[i].mestres,
                  &faeterj[i].regime_trabalho,
                  &faeterj[i].organizacao,
                  &faeterj[i].infraestrutura,
                  &faeterj[i].oportunidades,
                  &faeterj[i].num_alunos) == 10) 
    {
        printf("\n\tCurso %d lido: codigo %d, Enade %.2f\n", i+1, faeterj[i].cod_curso, faeterj[i].nota_enade);
        i++;
    }

    printf("\n\tOs dados foram processados corretamente!\n");

    fclose (cursos);
    }
    else
    {
        printf("\n\tErro ao abrir o arquivo.\n");
    }

}
      
void calc_cpc_classf(Cursos faeterj[]){
    int i;

    for (i = 0; i < TAM; i++) {
        faeterj[i].cpc_cont=(faeterj[i].nota_enade*0.20)+(faeterj[i].idd*0.35)+(faeterj[i].doutores*0.15)+(faeterj[i].mestres*0.075)+
                            (faeterj[i].regime_trabalho*0.075)+(faeterj[i].organizacao*0.075)+(faeterj[i].infraestrutura*0.05)+(faeterj[i].oportunidades*0.025);

        if (faeterj[i].cpc_cont>=0.945)
        {
            faeterj[i].cpc_faixa=2;
            strcpy(faeterj[i].classf, "CPC Insatisfatorio");

            if(faeterj[i].cpc_cont>=1.945)
            {
                faeterj[i].cpc_faixa=3;
                strcpy(faeterj[i].classf, "CPC Satisfatorio");
            }
            if(faeterj[i].cpc_cont>=2.945)
            {
                faeterj[i].cpc_faixa=4;
            }
            if(faeterj[i].cpc_cont>=3.945)
            {
                faeterj[i].cpc_faixa=5;
            }
        }
        else
        {
            faeterj[i].cpc_faixa=1;
            strcpy(faeterj[i].classf, "CPC Insatisfatorio");
        } 
        
    }

}

void exibe_curso(Cursos faeterj[]){
    int i;
    printf("\n\t======== Dados por Cursos FAETERJ-Rio =========\n");
    for (i = 0; i < TAM; i++) 
    {
        printf("\n\tCódigo do Curso: %d\n\tCPC Contínuo %.2f\n\tCPC Faixa %d\n\tClassificação: %s\n",
                faeterj[i].cod_curso, faeterj[i].cpc_cont, faeterj[i].cpc_faixa, faeterj[i].classf);
    }
    
}

void exibe_curso_faixa(Cursos faeterj[]){
    int i, faixa, encontrou_curso;

    printf("\n\t======== Dados por CPC Faixa FAETERJ-Rio =========\n");


    for(faixa=1; faixa<=5; faixa++)
    {
        printf("\n\tCursos FAETERJ-Rio com CPC Faixa %d\n", faixa);
        encontrou_curso = 0;

        for (i = 0; i < TAM; i++) 
        {
            if(faeterj[i].cpc_faixa==faixa){
                printf("\n\tCodigo do Curso: %d\n\tCPC Continuo: %.2f\n", faeterj[i].cod_curso, faeterj[i].cpc_cont);
                encontrou_curso=1;
            }
        }
        if (!encontrou_curso) 
        {
            printf("\n\tNenhum curso FAETERJ-Rio com CPC Faixa %d.\n", faixa);
        }
    }
    
}


void main(){
    Cursos faeterj[TAM];
    int resp;

    printf("\n\tDigite [1] para adicionar um novo curso ou digite [2] para processar os dados: ");
    scanf("%d", &resp);

    if(resp==1)
    {
        adicionar_curso();
    }
    else
    {
        preencher_cursos(faeterj);
        calc_cpc_classf(faeterj);
        exibe_curso(faeterj);
        exibe_curso_faixa(faeterj);
        calc_igc();
    }

}