#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <string.h>

/* FUNÇÕES DE MANIPULAÇÃO DE PFILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA ESTÁ VAIZA

void InsereFila (Fila* f, int v) INSERÇÃO

int RetiraFila (Fila* f) REMOÇÃO

Fila* liberaFila (Fila* f) LIBERA A FILA

void imprimeFila (Fila* f)IMPRIME A FILA
*/

typedef struct data
{
    int dia;
    int mes;
    int ano;

}data;
typedef struct nos
{
    int codigo;
    char nome[30];
    char proj[30];
    data inicio;
    data fim;
    int status;
    struct nos *prox;
}No;

typedef struct fila
{
    No * ini;
    No * fim;
} Fila;

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

}


Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

No* ins_fim (No* fim, int A,char b[],char c[], data d, data e)
{
    No* p = (No*) malloc(sizeof(No));
    p->codigo = A;
    strcpy(p->nome,b);
    strcpy(p->proj,c);
    p->inicio = d;
    p->fim = e;
    p->status = 0;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int a,char *b,char *c, data d, data e)
{
    f->fim = ins_fim(f->fim,a,b,c,d,e);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

No* retira_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

No* RetiraFila (Fila* f)
{
    No* v;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    v = f->ini;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;
    return v;
}

void imprimeData (data f){

    printf("%d/%d/%d",f.dia,f.mes,f.ano);
}



void imprimeFila (Fila* f)
{
    No* q;
    printf("\n\t\t");
    for (q=f->ini; q!=NULL; q=q->prox)
    {
        printf("\ncodigo:%d",q->codigo);
        printf("\nNome da tarefa:%s - ",q->nome);
        printf("\nNome do projeto:%s - ",q->proj);
        printf("\ninicio:");
        imprimeData(q->inicio);
        printf("\nfim:");
        imprimeData(q->fim);
        printf("\nStatus:%d - ",q->status);

    }
    printf("\n");
}


Fila* liberaFila (Fila* f)
{
    No* q = f->ini;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

void ModificaTarefa(Fila* f,int codigo,int nVal,char *nome,char *proj, data DataIni, data DataFim){
    No* atual = f->fim;
    int contador = 0;

    while(atual !=NULL){
        if(contador == codigo){
            atual->codigo = nVal;
            strcpy(atual->nome,nome);
            strcpy(atual->proj,proj);
            atual->inicio = DataIni;
            atual->fim = DataFim;
            return;
        }
        atual = atual->prox;
    }
}
/*
No* inicializa(){
    No* f = (No*) malloc(sizeof(No));
    f->prox = NULL;
    return f;
}

int verificaVaziaLista(No* lista){
    if(lista!=NULL){
        return 0;
    }else{
        return 1;
    }
}

No* ConcluiTarefa(No* lista,Fila* f,int codigo){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo = RetiraFila(f);
    novoNo->prox = NULL;
    if(lista == NULL){
        novoNo->prox = lista;
        return novoNo;
    }

    No* aux = lista;

    while(aux->prox !=NULL && aux->fim->dia + aux->fim->ano + aux->fim->mes  <= novoNo->fim->dia + novoNo->fim->ano + novoNo->fim->mes){
        aux = aux->prox;
    }

    novoNo->prox = aux->prox;
    aux->prox = novoNo;

    return aux;
}
*/
#endif // FILA_H_INCLUDED
