#include<stdio.h>

int isPrimo(int x)  {
    if (x == 2 || x == 1) return 1;

    for(int i = 2; i < x; i++) {
        if(x % 2 == 0) return 0;
    }

    return 1;
}

int decomposicaoFatoresPrimos(int x, int y) {
    if (x ==  0) return y;
    if (y ==  0) return x;

    int divisor = 2;
    int produtoFatores = (x % 2 == 0 && y % 2 == 0) ? 2 : 1;

    for (int divisor = 3; (x != 1 || y != 1) && (x > divisor && y > divisor); divisor+=2) {
        if (isPrimo(divisor) && x % divisor == 0 && y % divisor == 0) {
            x = x / divisor;
            y = y / divisor;

            produtoFatores = produtoFatores * divisor;
        }
    }

    return produtoFatores;
}

int mdc(int num1, int num2) {

    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}

int main() {
    int n1, n2;

    printf("Digite numeros para calculo de mdc\n");

    scanf("%d\n%d", &n1, &n2);

    printf("\nPelo Metodo divisoes sucessivas o mdc entre %d e %d e %d\n", n1, n2, mdc(n1, n2));


    printf("\nPelo Metodo decomposicao em fatores primos o mdc entre %d e %d e %d\n", n1, n2, decomposicaoFatoresPrimos(n1, n2));
}
