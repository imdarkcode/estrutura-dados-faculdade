#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 100


typedef struct {
    int topo;
    char *itens[TAMANHO_MAXIMO];
}Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(Pilha *pilha) {
    return pilha->topo == TAMANHO_MAXIMO - 1;
}

void inserirElemento(Pilha *pilha, char elemento[50]) {
    if (pilhaCheia(pilha)) {
        printf("Historico cheio, nao foi possivel acessar a pagina.\n");
        printf("Pressione enter par voltar ao menu... ");
        getch();
        return;
    }

    pilha->topo++;
    pilha->itens[pilha->topo] = (char *)malloc(strlen(elemento) + 1);

    if (pilha->itens[pilha->topo] != NULL) {
        strcpy(pilha->itens[pilha->topo], elemento);
    }
    else {
        printf("Erro ao carregar a pagina.\n");
        printf("Pressione enter par voltar ao menu... ");
        getch();
    }
}

void excluirElemento(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Nao ha paginas anteriores.\n");
        printf("Pressione enter par voltar ao menu... ");
        getch();
        return;
    }

    pilha->topo--;
}

void exibirTopo(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Nenhuma pagina acessada\n");
        return;
    }

    printf("Pagina atual: %s\n", pilha->itens[pilha->topo]);
}

int main() {
    Pilha historico;
    inicializarPilha(&historico);
    int opcao;
    char elemento[50];
    int posicao, novoElemento;

    do {
        system("cls");
        printf("----- Menu -----\n");
        printf("1. Acessar nova pagina\n");
        printf("2. Voltar para pagina anterior\n");
        printf("0. Sair\n\n");
        exibirTopo(&historico);
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                printf("Digite o nome do site: ");
                scanf("%s", elemento);
                inserirElemento(&historico, elemento);
            break;

            case 2:
                system("cls");
                excluirElemento(&historico);
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
