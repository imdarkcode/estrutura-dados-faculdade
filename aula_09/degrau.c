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

void subirDegrau(Pilha *pilha, int degrauAtual, int quantDegrau){
    if(degrauAtual > quantDegrau) {
        pilha->topo--;
        descerDegrau(pilha);
        return 1;
    }
    else {
        if (pilhaCheia(pilha)) {
            printf("Erro: Pilha cheia, elemento não inserido.\n");
            return;
        }

        pilha->topo++;
        pilha->itens[pilha->topo] = degrauAtual;
        printf("Voce subiu para o degrau %d.\n", pilha->itens[pilha->topo]);
        subirDegrau(pilha, degrauAtual + 1, quantDegrau);
    }

}

void descerDegrau(Pilha *pilha){
    if (pilhaVazia(pilha)) {
        printf("Voce desceu o ultimo degrau.");
        return;
    }

    printf("Voce desceu para o degrau %d.\n", pilha->itens[pilha->topo]);
    pilha->topo--;
    descerDegrau(pilha);
}


// Função principal

int main() {
    Pilha minhaPilha;
    inicializarPilha(&minhaPilha);
    int degrauAtual = 1, quantDegrau;

    printf("Quantidade de degraus: ");
    scanf("%d", &quantDegrau);

    subirDegrau(&minhaPilha, degrauAtual, quantDegrau);

    return 0;
}

