#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED
#include "math.h"

struct Triangulo {

    int a,b,c;

    Triangulo() { }

    Triangulo(int l1, int l2,int l3) {
        a = l1;
        b = l2;
        c = l3;
    }

    int mostrarPerimetro() {
        return a+b+c;
    }

    float mostrarArea() {
        float sm = mostrarPerimetro()/2; // Semiperimetro
        return sqrt(sm*(sm-a)*(sm-b)*(sm-c)); // Utiliza a fórmula de Heron para calculo da área
    }

    bool isTriangulo() {
        if( (a < (b+c)) && (b < (a+c)) && (c < (b+a)) ) { // verifica se é triangulo
            return true;
        } else {
            return false;
        }
    }
};

#endif // TRIANGULO_H_INCLUDED
