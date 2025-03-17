#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Criar a estrutura veiculo
typedef struct veiculo {
    int vaga;
    char motorista[50];
    char placa[7];
    char telefone[14];

    struct veiculo *anterior;
    struct veiculo *proximo;
}Veiculo;

// Função para inserir valor na lista
void inserir_na_posicao(Veiculo **lista, int posicao, char motorista[50], char placa[7], char telefone[14]) {

    // Reservar espaço na memória
    Veiculo *novo = malloc(sizeof(Veiculo));

    // Verifica se a memória foi alocada
    if(novo){
        novo -> vaga = posicao;
        strcpy(novo -> motorista, motorista);
        strcpy(novo -> placa, placa);
        strcpy(novo -> telefone, telefone);
        novo -> anterior = NULL;
        novo -> proximo = NULL;

        // Verifica se a lista estiver vazia
        if(*lista == NULL){
            *lista = novo;
            return;
        }

        Veiculo *atual = *lista;
        Veiculo *anterior = NULL;
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
void exibir_lista(Veiculo *lista) {
    printf("------------------------------------\n");
    printf("Vagas ocupadas\n");
    printf("------------------------------------\n");

    while(lista) {
        printf("Vaga: %d\n", lista -> vaga);
        printf("Motorista: %s\n", lista -> motorista);
        printf("Placa: %s\n", lista -> placa);
        printf("Telefone: %s\n\n", lista -> telefone);

        lista = lista -> proximo;
    }
}

int main(void) {
    // Iniciar uma lista vazia
    Veiculo *estacionamento = NULL;

    // Definir variaveis
    int opcao;

    int vaga;
    char motorista[50];
    char placa[7];
    char telefone[14];

    int vagas_disponiveis[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    do {
        // Limpar a tela
        system("cls");

        // Mostrar o menu e pedir a opção
        printf("------------------------------------\n");
        printf("Estacionamento\n");
        printf("------------------------------------\n");

        printf("Informe a acao que deseja:\n");
        printf("[1] Inserir veiculo\n");
        printf("[2] Mostrar vagas ocupadas\n");
        printf("[0] Sair\n");
        scanf("%i", &opcao);

        // Executar a opção digitada
        switch (opcao) {

        case 1:
            // Limpar a tela
            system("cls");

            // Pedir os dados ao usuário
            printf("------------------------------------\n");
            printf("Informe os dados do veiculo\n");
            printf("------------------------------------\n");

            printf("Vaga: ");
            scanf("%d", &vaga);

            printf("Nome do motorista: ");
            scanf("%s", motorista);

            printf("Placa: ");
            scanf("%s", placa);

            printf("Telefone: ");
            scanf("%s", telefone);

            // Verificar se a vaga está ocupada
            if (vagas_disponiveis[vaga] == 0){
                // Chamar função para inserir valores na lista
                inserir_na_posicao(&estacionamento, vaga, motorista, placa, telefone);
                vagas_disponiveis[vaga] = 1;
                printf("\nVeiculo cadastrado!\n");

            }
            else if (vagas_disponiveis[vaga] == 1){
                printf("\nVaga indisponivel!\n");
            }

            printf("Pressione enter para retornar ao menu\n");
            getch();

        break;

        case 2:
            // Limpar a tela
            system("cls");

            // Chamar função para exibir a lista
            exibir_lista(estacionamento);

            printf("Pressione enter para retornar ao menu\n");
            getch();
        break;
        }
    }while(opcao != 0);

}
