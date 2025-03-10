#include <stdio.h>

// Definir tipo de dado nó

typedef struct no {
    int valor;
    struct no *proximo;
}No;

// Função de inserir valor na lista

void inserir_no_inicio(No **lista, int num) {
    No *novo = malloc(sizeof(No)); // Alocar espaço na memória para o valor

    // Verificar se foi alocado

    if(novo) {
        // Atribuir valores a lista e apontar para o próximo nó

        novo -> valor = num;
        novo -> proximo = *lista;
        *lista = novo;
    }
    else {
        printf("Erro ao alocar memória\n");
    }
}

// Função de exibir lista

void exibir_lista(No *lista) {
    printf("Lista:");

    while(lista) {
        printf(" %d ->", lista -> valor);
        lista = lista -> proximo;
    }

    printf("NULL\n");
}

int main(void) {
    No *minha_lista = NULL; // Iniciar lista vazia

    // Inserir valores

    inserir_no_inicio(&minha_lista, 3);
    inserir_no_inicio(&minha_lista, 7);
    inserir_no_inicio(&minha_lista, 1);

    exibir_lista(minha_lista); // Chamar função de exibir lista
}
