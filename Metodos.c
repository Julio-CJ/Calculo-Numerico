#include "Metodos.h"

void bisseccao(double a, double b, float erro, int imax, funcao f) {
    if(f(a) * f(b) < 0) {
        double c = 0;
        double erroa = 0;
        double errob = 0;
        int i = 0;
        do {
            i++;
            c = (a + b)/2;
            if (f(a) * f(c) < 0) {
                b = c;
            }
            else {
                a = c;
            }
            printf("Na iteração %d a raiz é aproximandamente: %lf\n", i, c);
            erroa = a-c;
            errob = b-c;
            if(erroa < 0) {
                erroa = -erroa;
            }
            if(errob < 0) {
                errob = -errob;
            }
        }while ((erroa > erro || errob > 0) && i <= imax);
        printf("A raiz é aproximadamente: %lf\n", c);
    }
    else {
        printf("Sem raiz nesse intervalo.\n");
    }
}