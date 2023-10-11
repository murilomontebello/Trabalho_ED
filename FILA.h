#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <string.h>

/* FUN��ES DE MANIPULA��O DE PFILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA EST� VAIZA

void InsereFila (Fila* f, int v) INSER��O

int RetiraFila (Fila* f) REMO��O

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
    data Dfim;
    int status;
    struct nos *prox;
}No;

typedef struct fila
{
    No * ini;
    No * fim;
} Fila;

void imprimeData (data f){

    printf("%d/%d/%d",f.dia,f.mes,f.ano);
}

void imprimeFila (Fila* f)
{
    No* q;
    printf("\n");
    if(f->fim == NULL && f->ini == NULL){
        printf("Fila Vazia");
    }else{
        for (q=f->ini; q!=NULL; q=q->prox){
            printf("\n\n\tCodigo:%d",q->codigo);
            printf("\n\tNome da tarefa:%s",q->nome);
            printf("\n\tNome do projeto:%s",q->proj);
            printf("\n\tInicio:");
            imprimeData(q->inicio);
            printf("\n\tFim:");
            imprimeData(q->Dfim);
            printf("\n\tStatus:%d\n",q->status);

        }
    }

    printf("\n");
}

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
    p->Dfim = e;
    p->status = 0;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista n�o estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int a,char *b,char *c, data d, data e)
{
    f->fim = ins_fim(f->fim,a,b,c,d,e);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}


No* RetiraFila(Fila *f)
{
    No *V=NULL;
    if (VaziaFila(f))
    {
        printf("\n\nFila vazia.\n");
    }
    else
    {
        V = f->ini;
        f->ini= f->ini->prox;
        if(f->ini==NULL)
        {
            f->fim=NULL;
        }

        V->prox=NULL;
    }
     return V;
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
            atual->Dfim = DataFim;
            return;
        }
        atual = atual->prox;
    }
}

void imprime(No *aux){

    No *q = aux;

    if(q!=NULL){

        while (q != NULL) {
            printf("\n\n\tCodigo:%d",q->codigo);
            printf("\n\tNome da tarefa:%s",q->nome);
            printf("\n\tNome do projeto:%s",q->proj);
            printf("\n\tInicio:");
            imprimeData(q->inicio);
            printf("\n\tFim:");
            imprimeData(q->Dfim);
            printf("\n\tStatus:%d\n\n",q->status);
            q = q->prox;
        }
    }else{
        printf("\nLista Vazia !!!\n");
    }
}

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

No* ConcluiTarefa(No* lista,Fila* f){

    No* novoNo = (No*)malloc(sizeof(No));
    novoNo = RetiraFila(f);
    novoNo->prox = NULL;

    if(lista == NULL){
        return novoNo;
    }

    No *aux = lista;
    No *aux2 = NULL;

    while((aux !=NULL) && (aux->Dfim.ano > novoNo->Dfim.ano)){
        aux2 = aux;
        aux = aux->prox;
    }

    while((aux !=NULL) && (aux->Dfim.mes > novoNo->Dfim.mes)){
        aux2 = aux;
        aux = aux->prox;
    }

    while((aux !=NULL) && (aux->Dfim.dia > novoNo->Dfim.dia)){
        aux2 = aux;
        aux = aux->prox;
    }

    novoNo->prox = aux;
    aux2->prox = novoNo;

    return lista;
}

No* atualizaEstatus(Fila* f,No* lista){
    No* atual = (No*)malloc(sizeof(No));
    atual = RetiraFila(f);
    atual->status = -1;
    atual->prox = NULL;

    if(lista == NULL){

        return atual;

    }else{

        No *aux = lista;

        while(aux->prox != NULL){

            aux = aux->prox;

        }

        aux->prox = atual;
        return lista;
    }
}

#endif // FILA_H_INCLUDED
