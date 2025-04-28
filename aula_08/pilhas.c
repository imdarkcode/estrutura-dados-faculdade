#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 100

//Definir estrutura da pilha
typedef struct {
    int topo; // Último indice da pilha
    int itens[TAMANHO_MAXIMO]; // Array com os itens da pilha
}Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1; // Inicializar ocm o topo -1 indicando que a pilha esta vazia
}

// Função para vcerificar se a pilha esta vazia
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para verificar de a pilha esta cheia
int pilhaCheia(Pilha *pilha) {
    return pilha->topo == TAMANHO_MAXIMO - 1;
}

// Função para inserir um elemento na pilha
void inserirElemento(Pilha *pilha, int elemento) {
    if (pilhaCheia(pilha)) {
        printf("Erro: Pilha cheia, elemento não inserido.\n");
        return;
    }

    pilha->topo++; // Incrementa o topo
    pilha->itens[pilha->topo] = elemento; // Insere o elemento na posição do topo
    printf("Elemento %d inserido na pilha.\n", elemento);
}

// Função para editar um elemento da pilha
void editarElemento(Pilha *pilha, int posicao, int novoElemento) {
    if (posicao < 0 || posicao > pilha->topo) {
        printf("Erro: Posição inválida.\n");
        return;
    }

    pilha->itens[posicao] = novoElemento; // Altera o elemento na posição especificada
    printf("Elemento na posição %d editado para %d.\n", posicao, novoElemento);
}

// Função para excluir o elemento do topo da pilha
void excluirElemento(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha vazia, nenhum elemento para excluir.\n");
        return;
    }

    printf("Elemento %d excluído da pilha.\n", pilha->itens[pilha->topo]);
    pilha->topo--; // Decrementa o topo para excluir o elemento
}

// Função para exibir todos os elementos da pilha
void exibirPilha(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Elementos na pilha:\n");

    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d\n", pilha->itens[i]);
    }
}

int main() {
    Pilha minhaPilha;
    inicializarPilha(&minhaPilha);
    int opcao;
    int elemento, posicao, novoElemento;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Editar elemento\n");
        printf("3. Excluir elemento\n");
        printf("4. Exibir pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                inserirElemento(&minhaPilha, elemento);
            break;

            case 2:
                printf("Digite a posição do elemento a ser editado: ");
                scanf("%d", &posicao);
                printf("Digite o novo valor do elemento: ");
                scanf("%d", &novoElemento);
                editarElemento(&minhaPilha, posicao, novoElemento);
            break;

            case 3:
                excluirElemento(&minhaPilha);
            break;

            case 4:
                exibirPilha(&minhaPilha);
            break;

            case 0:
                printf("Encerrando o programa...\n");
            break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
