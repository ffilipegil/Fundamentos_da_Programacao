/*
    ALUNOS:
    FILIPE SOARES DA SILVA GIL 
    PAULO HENRIQUE
*/

#include <stdio.h>
#include <string.h>

#define TAM 10

typedef struct{
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
        char classf[25];
    } Cursos;

void adic_curso(Cursos faeterj[]){
    FILE* cursos;
    int i=0;
    int num_cursos;

    cursos=fopen ("cursos.txt", "a");
    
    if (cursos != NULL)  
    {
        printf("\n\tQuer adicionar quantos cursos?: ");
        scanf("%d", &num_cursos);
        
        while (i<num_cursos) 
        {
            printf("\n\tDigite o codigo do curso: ");
            scanf("%d", &faeterj[i].cod_curso);
        
            printf("\n\tDigite a nota do Enade: ");
            scanf("%f", &faeterj[i].nota_enade);
        
            printf("\n\tDigite o IDD: ");
            scanf("%f", &faeterj[i].idd);
        
            printf("\n\tDigite a proporçao de doutores: ");
            scanf("%f", &faeterj[i].doutores);
        
            printf("\n\tDigite a proporçao de mestres: ");
            scanf("%f", &faeterj[i].mestres);
        
            printf("\n\tDigite o regime de trabalho: ");
            scanf("%f", &faeterj[i].regime_trabalho);
        
            printf("\n\tDigite a nota de organizaçao didatico-pedagogica: ");
            scanf("%f", &faeterj[i].organizacao);
        
            printf("\n\tDigite a nota de infraestrutura: ");
            scanf("%f", &faeterj[i].infraestrutura);
        
            printf("\n\tDigite a nota de oportunidades de ampliaçao da formaçao: ");
            scanf("%f", &faeterj[i].oportunidades);
        
            printf("\n\tDigite o numero de alunos: ");
            scanf("%d", &faeterj[i].num_alunos);
            
            fprintf(cursos, "\n%d|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%d", faeterj[i].cod_curso, faeterj[i].nota_enade, faeterj[i].idd, faeterj[i].doutores,
                    faeterj[i].mestres, faeterj[i].regime_trabalho, faeterj[i].organizacao, faeterj[i].infraestrutura, faeterj[i].oportunidades, faeterj[i].num_alunos);
            
            i++;
        }
        
        printf("\n\tCurso adicionado com sucesso ao arquivo!\n");
        
        fclose(cursos);

    }
    else
    {
        
       printf("\n\tErro na abertura do arquivo\n");
        
    }
}


int preencher_cursos(Cursos faeterj[]){
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
                  &faeterj[i].num_alunos) == 10 ) 
    {
        i++;
    }

    printf("\n\tOs dados foram processados corretamente!\n");

    fclose (cursos);

    return i;

    }
    else
    {
       return -1;
    }

}
      
void calc_cpc_classf(Cursos faeterj[], int qtd_cursos){
    int i;

    for (i = 0; i < qtd_cursos; i++) 
    {
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

void exibe_curso(Cursos faeterj[], int qtd_cursos){
    int i;
    printf("\n\t======== Dados por Cursos FAETERJ-Rio =========\n");
    for (i = 0; i < qtd_cursos; i++) 
    {
        printf("\n\tCodigo do Curso: %d\n\tCPC Continuo %.2f\n\tCPC Faixa %d\n\tClassificaçao: %s\n",
                faeterj[i].cod_curso, faeterj[i].cpc_cont, faeterj[i].cpc_faixa, faeterj[i].classf);
    }
    
}

void exibe_curso_faixa(Cursos faeterj[], int qtd_cursos){
    int i, faixa, encontrou_curso;

    printf("\n\t======== Dados por CPC Faixa FAETERJ-Rio =========\n");


    for(faixa=1; faixa<=5; faixa++)
    {
        printf("\n\tCursos FAETERJ-Rio com CPC Faixa %d\n", faixa);
        encontrou_curso = 0;

        for (i = 0; i < qtd_cursos; i++) 
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

void calc_exibe_igc(Cursos faeterj[], int qtd_cursos){
    int i, igc_faixa, total_alun=0;
    float soma=0.0, igc_cont;

    for(i=0; i<qtd_cursos; i++){
        if(faeterj[i].cod_curso!=0){
            soma+=faeterj[i].cpc_cont*faeterj[i].num_alunos;
            total_alun+=faeterj[i].num_alunos;
        }
    }
    
    igc_cont=soma/total_alun;
    
    printf("\n\t========== IGC da FAETERJ-Rio ==========\n");
    printf("\n\tIGC Continuo: %.2f\n", igc_cont);
    
    if (igc_cont>=0.945)
        {
            igc_faixa=2;

            if(igc_cont>=1.945)
            {
                igc_faixa=3;
            }
            if(igc_cont>=2.945)
            {
                igc_faixa=4;
            }
            if(igc_cont>=3.945)
            {
                igc_faixa=5;
            }
        }
        else
        {
            igc_faixa=1;
        }
    
        printf("\n\tIGC Faixa: %d\n", igc_faixa);
        
        if(igc_faixa >= 3){
            printf("\n\tClassificaçao: IGC Satisfatorio\n");
        } else {
            printf("\n\tClassificaçao: IGC Insatisfatorio\n");
        }
    
}

void main(){
    Cursos faeterj[TAM];
    int resp=1, qtd_cursos=0;
    
    while(resp==1 || resp==2){
        printf("\n\tDigite [1] para adicionar um novo curso, digite [2] para processar os dados ou qualquer numero para encerrar: ");
        scanf("%d", &resp);

        if (resp == 2) 
        {
            qtd_cursos=preencher_cursos(faeterj);
            
            switch (qtd_cursos)
        	{
        		case -1: printf ("\n\tErro na abertura do arquivo.\n");
        		         break;
        		         
        		case  0: printf ("\n\tO arquivo não tem nenhum curso preenchido\n");
        		         break;
        				 
        		default: calc_cpc_classf(faeterj, qtd_cursos);
        		         exibe_curso(faeterj, qtd_cursos);
        		         exibe_curso_faixa(faeterj, qtd_cursos);
        		         calc_exibe_igc(faeterj, qtd_cursos);
           }
            
        } 
        else if(resp==1)
        {
           adic_curso(faeterj);
        }
    }

}