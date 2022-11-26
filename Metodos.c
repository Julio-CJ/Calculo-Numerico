#include "Metodos.h"

void bisseccao(double a, double b, float erro, int imax, funcao f) {
    //verifica se existe raiz no intervalo
    if(f(a) * f(b) < 0) {
        //zera as variaveis auxiliares
        double c = 0;
        double erroa = 0;
        double errob = 0;
        int i = 0;
        do {
            //incrementa a variavel i para evitar loop infinito
            i++;
            //calcula o meio do intervalo
            c = (a + b)/2;
            //verifica em qual metade esta a raiz
            if (f(a) * f(c) < 0) {
                b = c;
            }
            else {
                a = c;
            }
            //atualiza a situação
            printf("Na iteração %d a raiz é aproximandamente: %lf\n", i, c);
            //calcula o erro em função do intervalo
            erroa = a-c;
            errob = b-c;
            //garante o modulo do erro
            if(erroa < 0) {
                erroa = -erroa;
            }
            if(errob < 0) {
                errob = -errob;
            }
            //condição de parada
        }while ((erroa > erro || errob > erro) && i < imax);
        printf("A raiz é aproximadamente: %lf\n", c);
    }
    else {
        printf("Sem raiz nesse intervalo.\n");
    }
}