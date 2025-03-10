#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir tipo de dado veiculo

typedef struct veiculo {
    char motorista[50];
    char placa[7];
    char telefone[14];

    struct veiculo *proximo;
}Veiculo;

// Fun��o de inserir veiculo na lista

void inserir_veiculo(Veiculo **lista, char motorista[50], char placa[7], char telefone[14]) {
    Veiculo *novo = malloc(sizeof(Veiculo)); // Alocar espa�o na mem�ria

    // Verificar se foi alocado

    if(novo) {
        // Atribuir valores e apontar para o proximo espa�o da lista
        strcpy(novo -> motorista, motorista);
        strcpy(novo -> placa, placa);
        strcpy(novo -> telefone, telefone);
        novo -> proximo = *lista;
        *lista = novo;
    }
    else {
        printf("Erro ao alocar mem�ria\n");
    }
}

// Fun��o de exibir lista

void exibir_lista(Veiculo *lista) {
    printf("------------------------------------\n");
    printf("Vagas ocupadas\n");
    printf("------------------------------------\n");

    int contador = 0;

    while(lista) {
        printf("Vaga: %i\n", contador);
        printf("Motorista: %s\n", lista -> motorista);
        printf("Placa: %s\n", lista -> placa);
        printf("Telefone: %s\n\n", lista -> telefone);
        lista = lista -> proximo;
        contador ++;
    }
}

int main(void) {
    // Criar lista varia
    Veiculo *minha_lista = NULL;

    int opcao;

    char motorista[50];
    char placa[7];
    char telefone[14];

    do {
        // Limpar a tela
        system("cls");

        // Mostrar o menu e pedir a op��o
        printf("------------------------------------\n");
        printf("Estacionamento\n");
        printf("------------------------------------\n");

        printf("Informe a acao que deseja:\n");
        printf("[1] Inserir veiculo\n");
        printf("[2] Mostrar vagas ocupadas\n");
        printf("[0] Sair\n");
        scanf("%i", &opcao);

        // Executar a op��o digitada
        switch (opcao) {

        case 1:
            // Limpar a tela
            system("cls");

            // Pedir os dados ao usu�rio
            printf("------------------------------------\n");
            printf("Informe os dados do veiculo\n");
            printf("------------------------------------\n");

            printf("Nome do motorista: ");
            scanf("%s", motorista);

            printf("Placa: ");
            scanf("%s", placa);

            printf("Telefone: ");
            scanf("%s", telefone);

            printf("\nVeiculo cadastrado!\n");
            printf("Pressione enter para retornar ao menu\n");
            getch();

            // Chamar a fun��o de inserir valor na lista
            inserir_veiculo(&minha_lista, motorista, placa, telefone);

        break;

        case 2:
            // Limpar a tela
            system("cls");

            // Chamar a fun��o de exibir a lista
            exibir_lista(minha_lista);

            printf("Pressione enter para retornar ao menu\n");
            getch();
        break;
        }
    }while(opcao != 0);
}
