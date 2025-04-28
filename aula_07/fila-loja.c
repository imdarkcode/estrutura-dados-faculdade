#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da fila
struct No{
    char nome[50];
    struct No *proximo;
};

// Estrutura da fila
struct Fila{
    struct No *frente, *tras;
};

// Criar novo nó na fila
struct No *novoNo(char nome[50]){
    struct No *temp = (struct No*)malloc(sizeof(struct No));
    strcpy(temp -> nome, nome);
    temp -> proximo = NULL;
    return temp;
};

// Criar nova fila
struct Fila *criarFila(){
    struct Fila *fila = (struct Fila*)malloc(sizeof(struct Fila));
    fila -> frente = fila -> tras = NULL;
    return fila;
};

// Inserir elemento na fila
void inserirElemento(struct Fila *fila, char nome[50]){
    struct No *temp = novoNo(nome);

    // Verificar se a lista está vazia
    if (fila -> tras == NULL){
        fila -> frente = fila -> tras = temp;
    }

    // Adicionar nó no final da fila
    fila -> tras -> proximo = temp;
    fila -> tras = temp;

    printf("Cliente adicionado: %s\n", temp -> nome);
};

// Remover elemento da fila
int removerElemento(struct Fila *fila){
    // Verificar se a lista está vazia
    if (fila -> frente == NULL){
        return -1;
    }

    // Guarda o nó da frente e move o ponteiro para o proximo nó
    struct No *temp = fila -> frente;
    printf("Cliente chamado: %s\n", temp -> nome);
    fila -> frente = fila -> frente -> proximo;

    // Se a frente for NULL o tras também deve ser
    if (fila -> frente == NULL){
        fila -> tras = NULL;
    }

    free(temp);
};

// Exibir fila
void exibirFila(struct Fila *fila) {
    struct No *temp = fila -> frente;
    printf("Fila: ");

    while (temp != NULL){
        printf("%s ", temp -> nome);
        temp = temp -> proximo;
    }

    printf("\n");
};

// Função principal
int main(){
    // Criar fila
    struct Fila *fila = criarFila();

    // Inserir elementos na fila
    inserirElemento(fila, "Joao");
    inserirElemento(fila, "Guilherme");
    inserirElemento(fila, "Maria");

    // Exibir fila
    exibirFila(fila);

    // Remover elemento
    removerElemento(fila);

    // Exibir fila
    exibirFila(fila);

    // Remover elemento
    removerElemento(fila);

    // Exibir fila
    exibirFila(fila);

    return 0;
};



