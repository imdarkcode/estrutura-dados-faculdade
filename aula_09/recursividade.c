#include <stdio.h>

// Fun��o recursiva

int recusividade(int n){
    if(n == 0) { // Verificar se a fun��o chegou no final
        return 1;
    }
    else {
        return n * fatorial(n - 1); // Chamar a fun��o com o valor menos 1
    }
}

// Fun��o principal

void main() {
    int num = 5;
    printf("Fatorial de %d = %d", num, recusividade(num));
}
