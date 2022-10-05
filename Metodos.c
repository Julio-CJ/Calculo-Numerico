#include "Metodos.h"

void bisseccao(float a, float b, float erro, int imax, funcao f) {
    if(f(a) * f(b) < 0) {
        float c;
        int i = 0;
        while ((f(a) >= erro || f(b) >= erro) && i <= imax) {
            c = (a + b)/2;
            if (f(a) * f(c) < 0) {
                b = c;
            }
            else {
                a = c;
            }
            printf("Na iteração %d a raiz é aproximandamente: %f\n", i, c);
            i++;
        }
        printf("A raiz é aproximadamente: %f\n", c);
    }
    else {
        printf("Sem raiz nesse intervalo.\n");
    }
}