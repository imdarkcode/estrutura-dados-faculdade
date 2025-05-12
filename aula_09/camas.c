#include <stdio.h>

// Função recursiva

void arrumarCama(int quarto, int quantQuartos){
    if(quarto > quantQuartos) {
        printf("Todas as camas foram arrumadas.");
        return 1;
    }
    else {
        printf("Cama do quarto %d foi arrumada.\n", quarto);
        arrumarCama(quarto + 1, quantQuartos);
    }
}

// Função principal

int main() {
    int quarto = 1, quantQuartos;

    printf("Quantidade de quartos: ");
    scanf("%d", &quantQuartos);

    arrumarCama(quarto, quantQuartos);

    return 0;
}
