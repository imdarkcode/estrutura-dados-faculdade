#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    // Criar ponteiro do arquivo
    FILE *arquivo;

    // Definir as variáveis
    char nome[30];
    char email[30];
    int idade;
    char frase[100];
    int opcao;

    do {
        // Limpar a tela
        system("cls");

        // Mostrar o menu e pedir a opção
        printf("------------------------------------\n");
        printf("Cadastro de usuario\n");
        printf("------------------------------------\n");

        printf("Informe a acao que deseja:\n");
        printf("[1] Cadastrar usuario\n");
        printf("[2] Mostrar usuarios\n");
        printf("[0] Sair\n");
        scanf("%i", &opcao);

        // Executar a opção digitada
        switch (opcao) {

        case 1:
            // Limpar a tela
            system("cls");

            // Abrir arquivo para escrita
            arquivo = fopen("usuarios.txt", "a");

            // Verificar se abriu o arquivo
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo");
                return 0;
            }

            // Pedir os dados ao usuário
            printf("------------------------------------\n");
            printf("Informe os dados o usuario\n");
            printf("------------------------------------\n");

            printf("Nome: ");
            scanf("%s", nome);

            printf("Idade: ");
            scanf("%i", &idade);

            printf("Email: ");
            scanf("%s", email);

            printf("\nUsuario cadastrado!\n");
            printf("Pressione enter para retornar ao menu\n");
            getch();

            // Escrever no arquivo
            fprintf(arquivo, "Nome: %s \nIdade: %i \nEmail: %s\n\n", nome, idade, email);

            // Fechar o arquivo
            fclose(arquivo);
        break;

        case 2:
            // Limpar a tela
            system("cls");

            // Abrir o arquivo para leitura
            arquivo = fopen("usuarios.txt", "r");

            printf("------------------------------------\n");
            printf("Usuarios cadastrados\n");
            printf("------------------------------------\n");

            // Ler e mostrar as linhas do arquivo
            while (fgets(frase, 100, arquivo) != NULL) {
                printf("%s", frase);
            }

            printf("Pressione enter para retornar ao menu\n");
            getch();

            // Fechar o arquivo
            fclose(arquivo);
        break;
        }
    }while(opcao != 0);
}


