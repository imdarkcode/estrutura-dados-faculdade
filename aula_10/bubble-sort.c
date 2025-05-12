#include<stdio.h>

// Função de trocar valores

void trocar(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função Bubble Sort

void bubbleSort(int arr[], int n){
    int i, j;
    int trocado;

    for (i = 0; i < n - 1; i++) {
        trocado = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
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
    int array[6] = {2, 8, 6, 4, 1, 9};

    bubbleSort(array, 6);

    for(int i = 0; i < 6; i++){
        printf("%d", array[i]);
    }
}
