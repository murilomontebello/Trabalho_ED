#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "FILA.h"


int main()
{
setlocale(LC_ALL, "Portuguese");
int menu;
int codigo,novoCodigo;
char nome[30],proj[30];
No *listaConcluidas;
No *listaPendente;
Fila *tarefa;
data dataIni;
data dataFim;

tarefa = CriaFila();
listaConcluidas = NULL;
listaPendente = NULL;

do{
    printf("Digite o nmero referente a funcionalidade desejada:\n");
    printf("1 - Adicionar Tarefa\n");
    printf("2 - Modificar Tarefa\n");
    printf("3 - Concluir Tarefa\n");
    printf("4 - Atualizao do Status\n");
    printf("5 - Tarefas Pendentes\n");
    printf("6 - Tarefas Concluidas\n");
    printf("7 - Tarefas Concludas com e sem Atrasos\n");
    printf("8 - Sair do Programa\n");
    scanf("%d",&menu);

    switch(menu){

            case 1:

                /*Adiciona uma tarefa a fila de tarefas*/


                printf("\nOp��o 1 escohida\n");

                printf("Qual o codigo: ");
                scanf("%d",&codigo);

                printf("Qual o nome da tarefa: ");
                fflush(stdin);
                gets(nome);

                printf("Qual o projeto da tarefa: ");
                fflush(stdin);
                gets(proj);

                printf("Qual o dia de inicio da tarefa: ");
                scanf("%d",&dataIni.dia);

                printf("Qual o mes de inicio da tarefa: ");
                scanf("%d",&dataIni.mes);

                printf("Qual o ano de inicio da tarefa: ");
                scanf("%d",&dataIni.ano);

                printf("Qual o dia de fim da tarefa: ");
                scanf("%d",&dataFim.dia);

                printf("Qual o mes de fim da tarefa: ");
                scanf("%d",&dataFim.mes);

                printf("Qual o ano de fim da tarefa: ");
                scanf("%d",&dataFim.ano);

                InsereFila(tarefa,codigo,nome,proj,dataIni,dataFim);

                system("pause");
                system("cls");

                break;

            case 2:
                printf("\nOp��o 2 escohida\n");

                printf("Qual o codigo para ser modificado: ");
                scanf("%d",&codigo);

                printf("Qual o novo codigo: ");
                scanf("%d",&novoCodigo);

                printf("Qual o novo nome: ");
                fflush(stdin);
                gets(nome);

                printf("Qual o novo nome do projeto: ");
                fflush(stdin);
                gets(proj);

                printf("Qual o novo dia de inicio da tarefa: ");
                scanf("%d",&dataIni.dia);

                printf("Qual o novo mes de inicio da tarefa: ");
                scanf("%d",&dataIni.mes);

                printf("Qual o novo ano de inicio da tarefa: ");
                scanf("%d",&dataIni.ano);

                printf("Qual o novo dia de fim da tarefa: ");
                scanf("%d",&dataFim.dia);

                printf("Qual o novo mes de fim da tarefa: ");
                scanf("%d",&dataFim.mes);

                printf("Qual o novo ano de fim da tarefa: ");
                scanf("%d",&dataFim.ano);

                ModificaTarefa(tarefa,codigo,novoCodigo,nome,proj,dataIni,dataFim);

                system("pause");
                system("cls");

                break;

            case 3:

                printf("\nOp��o 3 escohida\n");

                listaConcluidas = ConcluiTarefa(listaConcluidas,tarefa);

                printf("\nTarefa concluida!!!");

                system("pause");
                system("cls");

                break;

            case 4:
                printf("\nOp��o 4 escohida\n");

                listaPendente = atualizaEstatus(tarefa,listaPendente);

                printf("\nAgora a tarefa est� pendente");

                system("pause");
                system("cls");
                break;


            case 5:
                printf("\nOp��o 5 escohida\n");

                printf("\n\nLISTA PENDENTE\n");
                imprime(listaPendente);
                printf("\nFILA\n");
                imprimeFila(tarefa);

                system("pause");
                system("cls");
                break;

            case 6:
                printf("\nOp��o 6 escohida\n");

                imprime(listaConcluidas);

                system("pause");
                system("cls");
                break;

            case 7:
                printf("\nOp��o 7 escohida\n");

                imprimeConcluido(listaConcluidas);

                system("pause");
                system("cls");
                break;

            case 8:
                printf("\nOp��o 8 escohida\n");

                return 0;
                break;
            case 9:
                printf("\nFila de tarefas: ");
                imprimeFila(tarefa);

                printf("\nLista de tarefas concluidas:");
                imprime(listaConcluidas);

                printf("\nLista de tarefas pendentes:");
                imprime(listaPendente);

                system("pause");
                system("cls");
                break;

            default:
                printf("\nDigite uma opcao valida\n");
        }
    }
   while(menu);

        return 0;
}
