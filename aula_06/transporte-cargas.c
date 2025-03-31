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

// Função para inserir valor na lista
void inserir_na_posicao(Cidade **lista, int posicao, char nome[50], int km) {
    // Reservar espaço na memória
    Cidade *novo = malloc(sizeof(Cidade));

    // Verifica se a memória foi alocada
    if(novo){
        // Inserir valores
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

        // Percorre a lista até achar a posição desejada ou o final da lista
        while(atual != NULL && indice < posicao){
            anterior = atual;
            atual = atual -> proximo;
            indice++;
        }

        // Verifica se a posição desejada for a primeira da lista
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
        printf("Erro ao alocar a memória!");
    }
}

// Função para exibir a lista
void exibir_lista(Cidade *lista) {
    printf("Rota:\n\n");

    int distanciaTotal = 0;

    while(lista) {
        // Verificar se a cidade não foi removida
        if (strcmp(lista -> nome, "Removido") != 0) {
            printf("Cidade: %s\n", lista -> nome);
            printf("Km: %d\n", lista -> km);
        }

        // Verificar se for o ultimo item da lista
        if (lista -> proximo != NULL || lista -> proximo != 0) {
            // Verificar se o proximo item foi removido
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

//Função para remover item
void remover_item(Cidade *lista, char nome[50]) {
    while(lista) {
        // Verificar se o nome do item for igual ao digitado
        if (strcmp(lista -> nome, nome) == 0) {
            // Mudar o nome do item para removido e o km para o valor do anterior
            strcpy(lista -> nome, "Removido");
            lista -> km = lista -> anterior -> km;
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

        // Mostrar o menu e pedir a opção
        printf("------------------------------------\n");
        printf("Sistema de rota\n");
        printf("------------------------------------\n");

        printf("Informe a acao que deseja:\n");
        printf("[1] Cadastrar cidade\n");
        printf("[2] Mostrar rota\n");
        printf("[3] Remover cidade\n");
        printf("[0] Sair\n");
        scanf("%d", &opcao);

        // Executar a opção digitada
        switch (opcao) {

        case 1:
            // Limpar a tela
            system("cls");

            // Pedir os dados ao usuário
            printf("------------------------------------\n");
            printf("Cadastrar cidade\n");
            printf("------------------------------------\n");

            printf("Nome: ");
            scanf("%s", nome);

            printf("Km: ");
            scanf("%d", &km);

            // Chamar função para inserir valor
            inserir_na_posicao(&rota, posicao, nome, km);
            posicao ++;

            printf("Cidade cadastrada!\n");
            printf("Pressione enter para retornar ao menu\n");
            getch();

        break;

        case 2:
            // Limpar a tela
            system("cls");

            // Chamar função para exibir a lista
            exibir_lista(rota);

            printf("Pressione enter para retornar ao menu\n");
            getch();

        break;

        case 3:
            // Limpar a tela
            system("cls");

            // Pedir os dados ao usuário
            printf("------------------------------------\n");
            printf("Cadastrar cidade\n");
            printf("------------------------------------\n");

            printf("Nome: ");
            scanf("%s", nome);

            // Chamar função para remover item
            remover_item(rota, nome);

            printf("Pressione enter para retornar ao menu\n");
            getch();
        break;
        }
    }while(opcao != 0);

}
