#include <stdlib.h>
#include<stdio.h>
#include <string.h>

// Função de trocar valores

void trocar(int linha_a[], int linha_b[]) {
    int temp0 = linha_a[0];
    int temp1 = linha_a[1];
    linha_a[0] = linha_b[0];
    linha_a[1] = linha_b[1];
    linha_b[0] = temp0;
    linha_b[1] = temp1;
}

// Função Bubble Sort

void bubbleSort(int contas[][2], int n){
    int i, j;
    int trocado;

    for (i = 0; i < n - 1; i++) {
        trocado = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (contas[j][1] > contas[j + 1][1]) {
                trocar(&contas[j], &contas[j + 1]);
                trocado = 1;
            }
        }

        if (trocado == 0) {
            break;
        }
    }

}

// Função principal

int main(void){
    int contas[6][2] = {{0, 10}, {1, 15}, {2, 5}, {3, 12}, {4, 8}, {5, 7}};
    char nomes[6][20] = {"Conta de Luz", "Cartao de Credito", "Aluguel", "Internet", "Conta de Agua", "Condominio"};

    bubbleSort(contas, 6);

    for(int i = 0; i < 6; i++){
        printf("%s - dia %d\n", nomes[contas[i][0]], contas[i][1]);
    }
}
