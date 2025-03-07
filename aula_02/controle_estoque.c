#include <stdio.h>
#include <string.h>

int main(void) {
    int opcao;

    char nome[100];
    int quantidade;
    float preco;

    char buscar[100];
    int vender;

    FILE *arquivo;
    FILE *arquivo_copia;

    do {
        // Limpar a tela
        system("cls");

        // Mostrar o menu e pedir a opção
        printf("------------------------------------\n");
        printf("Controle de estoque\n");
        printf("------------------------------------\n");

        printf("Informe a acao que deseja:\n");
        printf("[1] Cadastrar novo produto\n");
        printf("[2] Exibir lista de produtos\n");
        printf("[3] Buscar produto\n");
        printf("[4] Vender produto\n");
        printf("[5] Remover produto\n");
        printf("[0] Sair\n");
        scanf("%i", &opcao);

        switch (opcao) {

        case 1:
            // Abrir o arquivo para escrita
            arquivo = fopen("produtos.txt", "a");

            // Verificar se o arquivo existe
            if (!arquivo) {
                printf("Erro ao abrir o arquivo");
                getch();
                break;
            }

            // Limpar a tela
            system("cls");

            // Pedir os dados ao usuário
            printf("------------------------------------\n");
            printf("Informe as informacoes do produto\n");
            printf("------------------------------------\n");

            printf("Nome: ");
            scanf("%s", nome);

            printf("Quantidade: ");
            scanf("%i", &quantidade);

            printf("Valor: ");
            scanf("%f", &preco);

            // Escrever os dados no arquivo
            fprintf(arquivo, "%s %i %.2f\n", nome, quantidade, preco);

            // Fechar o arquivo
            fclose(arquivo);

            printf("Produto cadastrado!\n");
            printf("Pressione enter para voltar ao menu...\n");
            getch();
        break;

        case 2:
            // Abrir o arquivo para leitura
            arquivo = fopen("produtos.txt", "r");

            // Verificar se o arquivo existe
            if (!arquivo) {
                printf("Erro ao abrir o arquivo");
                getch();
                break;
            }

            // Limpar a tela
            system("cls");

            printf("------------------------------------\n");
            printf("Produtos cadastrados\n");
            printf("------------------------------------\n");

            // Ler as linhas do arquivo e mostrar somente os nomes
            while(fscanf(arquivo, "%s %i %f", nome, &quantidade, &preco) > 0) {
                printf("%s\n", nome);
            }

            // Fechar o arquivo
            fclose(arquivo);

            printf("Pressione enter para voltar ao menu...\n");
            getch();
        break;

        case 3:
            // Abrir o arquivo para leitura
            arquivo = fopen("produtos.txt", "r");

            // Verificar se o arquivo existe
            if (!arquivo) {
                printf("Erro ao abrir o arquivo");
                getch();
                break;
            }

            // Limpar a tela
            system("cls");

            printf("------------------------------------\n");
            printf("Informacoes do produto\n");
            printf("------------------------------------\n");

            // Pedir o nome do produto
            printf("Nome do produto: ");
            scanf("%s", buscar);

            // Procura a linha com o produto que o usuário digitou e mostra a quantidade e o preco
            while(fscanf(arquivo, "%s %i %f", nome, &quantidade, &preco) > 0) {
                if (strcmp(nome, buscar) == 0) {
                    printf("Quantidade no estoque: %i\n", quantidade);
                    printf("Valor de venda: %.2f\n", preco);
                    printf("Pressione enter para voltar ao menu...\n");
                    getch();
                }
            }
        break;

        case 4:
            // Abrir arquivo para leitura
            arquivo = fopen("produtos.txt", "r");

            // Abrir arquivo cópia para escrita
            arquivo_copia = fopen("copia.txt", "w");

            // Verificar se os arquivos existem
            if (!arquivo || !arquivo_copia) {
                printf("Erro ao abrir o arquivo");
                getch();
                break;
            }

            // Limpar a tela
            system("cls");

            printf("------------------------------------\n");
            printf("Vender produto\n");
            printf("------------------------------------\n");

            // Pedir o nome e quantidade que deseja vender
            printf("Nome: ");
            scanf("%s", buscar);

            printf("Quantidade de vendas: ");
            scanf("%i", &vender);

            // Copia as linhas do arquivo para o arquivo cópia e retira a quantidade do produto digitado
            while(fscanf(arquivo, "%s %i %f", nome, &quantidade, &preco) > 0) {
                if (strcmp(nome, buscar) == 0) {
                    fprintf(arquivo_copia, "%s %i %.2f\n", nome, quantidade - vender, preco);
                }
                else {
                    fprintf(arquivo_copia, "%s %i %.2f\n", nome, quantidade , preco);
                }
            }

            // Fecha os arquivos
            fclose(arquivo);
            fclose(arquivo_copia);

            // Remove o arquivo original
            remove("produtos.txt");

            // Renomeia o arquivo cópia
            rename("copia.txt", "produtos.txt");

            printf("Venda realizada!\n");
            printf("Pressione enter para voltar ao menu...\n");
            getch();
        break;

        case 5:
            // Abrir arquivo para leitura
            arquivo = fopen("produtos.txt", "r");

            // Abrir arquivo cópia para escrita
            arquivo_copia = fopen("copia.txt", "w");

            // Verificar se os arquivos existem
            if (!arquivo || !arquivo_copia) {
                printf("Erro ao abrir o arquivo");
                getch();
                break;
            }

            // Limpar a tela
            system("cls");

            printf("------------------------------------\n");
            printf("Remover produto\n");
            printf("------------------------------------\n");

            // Pedir o nome e quantidade que deseja vender
            printf("Nome: ");
            scanf("%s", buscar);

            // Copia as linhas do arquivo para o arquivo cópia menos a do produto digitado
            while(fscanf(arquivo, "%s %i %f", nome, &quantidade, &preco) > 0) {
                if (strcmp(nome, buscar) != 0) {
                    fprintf(arquivo_copia, "%s %i %.2f\n", nome, quantidade , preco);
                }
            }

            // Fecha os arquivos
            fclose(arquivo);
            fclose(arquivo_copia);

            // Remove o arquivo original
            remove("produtos.txt");

            // Renomeia o arquivo cópia
            rename("copia.txt", "produtos.txt");

            printf("Produto removido!\n");
            printf("Pressione enter para voltar ao menu...\n");
            getch();
        break;
        }
    }while(opcao != 0);
}
