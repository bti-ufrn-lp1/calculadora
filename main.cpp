#include "calculadora.h"

int main() {
    int soma = somar(20, 10);
    int subtracao = subtrair(20, 10);
    int multiplicacao = multiplicar(20, 10);
    int divisao = dividir(20, 10);

    imprimir(soma);
    imprimir(subtracao);
    imprimir(multiplicacao);
    imprimir(divisao);

    return 0;
}