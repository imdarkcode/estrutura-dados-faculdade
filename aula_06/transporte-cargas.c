#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Criar a estrutura da cidade
typedef struct cidade {
    char nome[50];
    int km;
    struct cidade *anterior;
    struct cidade *proximo;
}Cidade;

// Fun��o para inserir valor na lista
void inserir_na_posicao(Cidade **lista, int posicao, char nome[50], int km) {
    // Reservar espa�o na mem�ria
    Cidade *novo = malloc(sizeof(Cidade));

    // Verifica se a mem�ria foi alocada
    if(novo){
        novo -> km = km;
        strcpy(novo -> nome, nome);
        novo -> anterior = NULL;
        novo -> proximo = NULL;

        // Verifica se a lista estiver vazia
        if(*lista == NULL){
            *lista = novo;
            return;
        }

        Cidade *atual = *lista;
        Cidade *anterior = NULL;
        int indice = 0;

        // Percorre a lista at� achar a posi��o desejada ou o final da lista
        while(atual != NULL && indice < posicao){
            anterior = atual;
            atual = atual -> proximo;
            indice++;
        }

        // Verifica se a posi��o desejada for a primeira da lista
        if(anterior == NULL){
            novo -> proximo = *lista;
            (*lista) -> anterior = novo;
            *lista = novo;
        }
        else {
            anterior -> proximo = novo;
            novo -> anterior = anterior;
            novo -> proximo = atual;

            if(atual != NULL){
                atual -> anterior = novo;
            }
        }
    }
    else{
        printf("Erro ao alocar a mem�ria!");
    }
}

// Fun��o para exibir a lista
void exibir_lista(Cidade *lista) {
    printf("Rota:\n\n");

    int distanciaTotal = 0;

    while(lista) {
        // Verificar se a cidade n�o foi removida
        if (strcmp(lista -> nome, "Removido") != 0) {
            printf("Cidade: %s\n", lista -> nome);
            printf("Km: %d\n", lista -> km);
        }

        // Verificar se for o ultimo item da lista
        if (lista -> proximo != NULL || lista -> proximo != 0) {
            if (strcmp(lista -> proximo -> nome, "Removido") != 0) {
                printf("Distancia ate a proxima cidade: %d\n", lista -> proximo -> km - lista -> km);
            }
            distanciaTotal += lista -> proximo -> km - lista -> km;
        }
        else {
            printf("Distancia ate o centro de distribuicao: %d\n", lista -> km);
        }

        printf("\n");
        lista = lista -> proximo;
    }

    printf("Distancia total: %d\n", distanciaTotal * 2);
}

//Fun��o para remover item
void remover_item(Cidade *lista, char nome[50]) {
    while(lista) {
        if (strcmp(lista -> nome, nome) == 0) {
            strcpy(lista -> nome, "Removido");
            if (lista -> proximo == NULL) {
                lista -> km = lista -> anterior -> km;
            }
            else {
                lista -> km = lista -> anterior -> km;
            }
        }
        lista = lista -> proximo;
    }
}

int main(void) {
    // Iniciar uma lista vazia
    Cidade *rota = NULL;

    // Definir variaveis
    int opcao;

    int km;
    char nome[50];
    int posicao = 0;

    do {
        // Limpar a tela
        system("cls");

        // Mostrar o menu e pedir a op��o
        printf("------------------------------------\n");
        printf("Sistema de rota\n");
        printf("------------------------------------\n");

        printf("Informe a acao que deseja:\n");
        printf("[1] Cadastrar cidade\n");
        printf("[2] Mostrar rota\n");
        printf("[3] Remover cidade\n");
        printf("[0] Sair\n");
        scanf("%d", &opcao);

        // Executar a op��o digitada
        switch (opcao) {

        case 1:
            // Limpar a tela
            system("cls");

            // Pedir os dados ao usu�rio
            printf("------------------------------------\n");
            printf("Cadastrar cidade\n");
            printf("------------------------------------\n");

            printf("Nome: ");
            scanf("%s", nome);

            printf("Km: ");
            scanf("%d", &km);

            inserir_na_posicao(&rota, posicao, nome, km);
            posicao ++;

            printf("Cidade cadastrada!\n");
            printf("Pressione enter para retornar ao menu\n");
            getch();

        break;

        case 2:
            // Limpar a tela
            system("cls");

            // Chamar fun��o para exibir a lista
            exibir_lista(rota);

            printf("Pressione enter para retornar ao menu\n");
            getch();

        break;

        case 3:
            // Limpar a tela
            system("cls");

            // Pedir os dados ao usu�rio
            printf("------------------------------------\n");
            printf("Cadastrar cidade\n");
            printf("------------------------------------\n");

            printf("Nome: ");
            scanf("%s", nome);

            remover_item(rota, nome);

            printf("Pressione enter para retornar ao menu\n");
            getch();
        break;
        }
    }while(opcao != 0);

}
