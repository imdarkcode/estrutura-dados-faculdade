#include <stdio.h>

// Criar a estrutura do n�
typedef struct no {
    int valor;
    struct no *proximo;
}No;

void inserir(No **lista, int num) {
    // Reservar espa�o na mem�ria
    No *novo = malloc(sizeof(No));

    // Verifica se a mem�ria foi alocada
    if(!novo){
        printf("Erro ao alocar a mem�ria!");
        return;
    }

    novo -> valor = num;
    novo -> proximo = NULL;

    // Verifica se a lista estiver vazia
    if(*lista == NULL){
        *lista = novo;
        novo -> proximo = novo;
    }
    else {
        No *aux = *lista;

        while(aux -> proximo != *lista) {
            aux = aux -> proximo;
        }

        aux -> proximo = novo;
        novo -> proximo = *lista;
    }
}

// Fun��o para exibir a lista
void exibir_lista(No *lista) {

    printf(" %d ->", lista -> valor);
    lista = lista -> proximo;

}

int main(void) {
    // Iniciar uma lista vazia
    No *minha_lista = NULL;

    // Chamar fun��o para inserir valores na lista
    inserir(&minha_lista, 5);

    // Chamar fun��o para exibir a lista
    exibir_lista(minha_lista);
}
