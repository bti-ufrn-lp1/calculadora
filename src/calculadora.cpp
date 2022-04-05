#include <cmath>

#include <iostream>
using std::cout;
using std::endl;

#include "calculadora.h"

void imprimir(float x) {
    cout << x << endl;
}

int somar(int x, int y) {
    return x + y;
}

int subtrair(int x, int y) {
    return x - y;
}

int multiplicar(int x, int y) {
    return x * y;
}

float dividir(int x, int y) {
    if (y == 0) {
        return NAN;
    } else {
        return x / y;
    }
}