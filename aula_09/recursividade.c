#include <stdio.h>

// Função recursiva

int recusividade(int n){
    if(n == 0) { // Verificar se a função chegou no final
        return 1;
    }
    else {
        return n * fatorial(n - 1); // Chamar a função com o valor menos 1
    }
}

// Função principal

void main() {
    int num = 5;
    printf("Fatorial de %d = %d", num, recusividade(num));
}
