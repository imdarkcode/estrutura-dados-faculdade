#include <stdio.h>
#include <string.h>

int main(void) {

    // Definir as variaveis
    int contador = 0;
    int opcao;
    int dados[100][3];

    int voto;
    char genero[1];
    int idade;

    int id_genero;
    int faixa_idade;

    float votosC1 = 0;
    float votosC2 = 0;
    float votosNulo = 0;

    float votosM = 0;
    float votosF = 0;

    float votosIdade1 = 0;
    float votosIdade2 = 0;
    float votosIdade3 = 0;

    do {
        // Limpar a tela
        system("cls");

        // Mostrar o menu e pedir a opção
        printf("------------------------------------\n");
        printf("Sistema de votacao\n");
        printf("------------------------------------\n");

        printf("Informe a acao que deseja:\n");
        printf("[1] Votar em um candidato\n");
        printf("[2] Exibir dados da votacao\n");
        printf("[0] Sair\n");
        scanf("%i", &opcao);

        switch (opcao) {

        case 1:
            // Limpar a tela
            system("cls");

            printf("------------------------------------\n");
            printf("Informe seus dados\n");
            printf("------------------------------------\n");
            printf("Candidato 1 - 48\n");
            printf("Candidato 2 - 31\n");
            printf("------------------------------------\n");

            // Pedir os dados ao usuario
            printf("Numero do candidato: ");
            scanf("%i", &voto);

            dados[contador][0] = voto;

            printf("Seu genero (M/F): ");
            scanf("%s", genero);

            printf("Sua idade: ");
            scanf("%i", &idade);


            // Salvar o codigo do genero na matriz
            if (strcmp(genero, "M") == 0) {
                id_genero = 0;
            } else {
                id_genero = 1;
            }

            dados[contador][1] = id_genero;

            // Salvar o codigo da faixa etario na matriz
            if (idade <= 25) {
                faixa_idade = 0;
            }
            else if (idade > 25 && idade <= 30) {
                faixa_idade = 1;
            }
            else {
                faixa_idade = 2;
            }

            dados[contador][2] = faixa_idade;

            contador ++;

            printf("\nVoto registrado!\n");
            printf("Precione enter para voltar ao menu...\n");
            getch();
        break;

        case 2:
            // Zera os valores das variaveis
            votosC1 = 0;
            votosC2 = 0;

            votosM = 0;
            votosF = 0;

            votosIdade1 = 0;
            votosIdade2 = 0;
            votosIdade3 = 0;

            // Ler os valores da matriz e salva nas variaveis
            for(int m = 0; m < contador; m++) {
                if (dados[m][0] == 48) {
                    votosC1 ++;
                }
                else if (dados[m][0] == 31) {
                    votosC2 ++;
                }
                else {
                    votosNulo++;
                }

                if (dados[m][1] == 0) {
                    votosM ++;
                }
                else {
                    votosF ++;
                }

                if (dados[m][2] == 0) {
                    votosIdade1 ++;
                }
                else if (dados[m][2] == 1) {
                    votosIdade2 ++;
                }
                else {
                    votosIdade3 ++;
                }
            }

            // Limpar a tela
            system("cls");

            // Mostrar os resultados
            printf("------------------------------------\n");
            printf("Dados da votacao\n");
            printf("------------------------------------\n");

            printf("Total de votos: %i \n\n", contador);

            printf("Porcentagem de votos do candidato 1: %.0f%% \n", (votosC1/contador)*100);
            printf("Porcentagem de votos do candidato 2: %.0f%% \n", (votosC2/contador)*100);
            printf("Porcentagem de votos nulos: %.0f%% \n\n", (votosNulo/contador)*100);

            printf("Porcentagem de homens: %.0f%% \n", (votosM/contador)*100);
            printf("Porcentagem de mulheres: %.0f%% \n\n", (votosF/contador)*100);

            printf("Porcentagem de 18 a 25 anos: %.0f%% \n", (votosIdade1/contador)*100);
            printf("Porcentagem de 25 a 30 anos: %.0f%% \n", (votosIdade2/contador)*100);
            printf("Porcentagem de mais de 30 anos: %.0f%% \n\n", (votosIdade3/contador)*100);

            printf("Precione enter para voltar ao menu...\n");
            getch();
        }
    } while(opcao != 0);
}
