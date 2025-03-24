#include <stdio.h>
#include <string.h>

// Criar a estrutura do jogador
typedef struct jogador {
    char nome[50];
    struct no *proximo;
}Jogador;

void inserir(Jogador **lista, char nome[50]) {
    // Reservar espaço na memória
    Jogador *novo = malloc(sizeof(Jogador));

    // Verifica se a memória foi alocada
    if(!novo){
        printf("Erro ao alocar a memória!");
        return;
    }

    strcpy(novo -> nome, nome);
    novo -> proximo = NULL;

    // Verifica se a lista estiver vazia
    if(*lista == NULL){
        *lista = novo;
        novo -> proximo = novo;
    }
    else {
        Jogador *aux = *lista;

        while(aux -> proximo != *lista) {
            aux = aux -> proximo;
        }

        aux -> proximo = novo;
        novo -> proximo = *lista;
    }
}

// Função para exibir a lista
void exibir_partida(Jogador *lista, int rodada) {

    printf("Partida: %d\n\n", rodada);

    for (int i = 0; i < rodada - 1; i++) {
        lista = lista -> proximo;
    }

    for (int i = 1; i <= 6; i++) {

        if (i == 1) {
            printf("%s - Dealer\n", lista -> nome);
        }
        else if (i == 2) {
            printf("%s - Small Blind\n", lista -> nome);
        }
        else if (i == 3) {
            printf("%s - Big Blind\n", lista -> nome);
        }
        else {
            printf("%s\n", lista -> nome);
        }

        lista = lista -> proximo;
    }

    printf("\n");
}

int main(void) {
    // Iniciar uma lista vazia
    Jogador *jogadores = NULL;

    // Definir variáveis
    int rodada = 1;

    // Chamar função para inserir os jogadores na lista
    inserir(&jogadores, "Jogador 1");
    inserir(&jogadores, "Jogador 2");
    inserir(&jogadores, "Jogador 3");
    inserir(&jogadores, "Jogador 4");
    inserir(&jogadores, "Jogador 5");
    inserir(&jogadores, "Jogador 6");

    // Chama a função para exibir a rodada
    for (int i = 0; i <= 6; i++) {
        exibir_partida(jogadores, rodada);
        rodada++;
    }
}
