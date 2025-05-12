#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 100

// Estrutura da pilha

typedef struct {
    int topo;
    int itens[TAMANHO_MAXIMO];
}Pilha;

// Função para inicializar a pilha

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

// Função para vcerificar se a pilha esta vazia

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para verificar de a pilha esta cheia

int pilhaCheia(Pilha *pilha) {
    return pilha->topo == TAMANHO_MAXIMO - 1;
}

// Função recursiva

void inserirPrato(Pilha *pilha, int prato, int quantPratos){
    if(prato > quantPratos) {
        lavarPrato(pilha);
        return 1;
    }
    else {
        if (pilhaCheia(pilha)) {
            printf("Erro: Pilha cheia, elemento não inserido.\n");
            return;
        }

        pilha->topo++;
        pilha->itens[pilha->topo] = prato;
        printf("Prato %d foi sujo.\n", pilha->itens[pilha->topo]);
        inserirPrato(pilha, prato + 1, quantPratos);
    }
}

void lavarPrato(Pilha *pilha){
    if (pilhaVazia(pilha)) {
        printf("Todos os pratos foram lavados.");
        return;
    }

    printf("Prato %d foi lavado.\n", pilha->itens[pilha->topo]);
    pilha->topo--;
    lavarPrato(pilha);
}

// Função principal

int main() {
    Pilha minhaPilha;
    inicializarPilha(&minhaPilha);
    int prato = 1, quantPratos;

    printf("Quantidade de pratos: ");
    scanf("%d", &quantPratos);

    inserirPrato(&minhaPilha, prato, quantPratos);

    return 0;
}
