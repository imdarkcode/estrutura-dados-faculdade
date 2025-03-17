#include <stdio.h>

// Criar a estrutura do nó
typedef struct no {
    int valor;
    struct no *anterior;
    struct no *proximo;
}No;

// Função para inserir valor na lista
void inserir_na_posicao(No **lista, int posicao, int num) {
    // Reservar espaço na memória
    No *novo = malloc(sizeof(No));

    // Verifica se a memória foi alocada
    if(novo){
        novo -> valor = num;
        novo -> anterior = NULL;
        novo -> proximo = NULL;

        // Verifica se a lista estiver vazia
        if(*lista == NULL){
            *lista = novo;
            return;
        }

        No *atual = *lista;
        No *anterior = NULL;
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
void exibir_lista(No *lista) {
    printf("Lista:");

    while(lista) {
        printf(" %d ->", lista -> valor);
        lista = lista -> proximo;
    }

    printf("NULL\n");
}

int main(void) {
    // Iniciar uma lista vazia
    No *minha_lista = NULL;

    // Chamar função para inserir valores na lista
    inserir_na_posicao(&minha_lista, 0, 3);
    inserir_na_posicao(&minha_lista, 2, 4);
    inserir_na_posicao(&minha_lista, 1, 7);
    inserir_na_posicao(&minha_lista, 4, 13);

    // Chamar função para exibir a lista
    exibir_lista(minha_lista);
}
