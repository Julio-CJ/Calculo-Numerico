#include "Metodos.h"

void bisseccao(float a, float b, float erro, funcao f) {
    //verifica se existe raiz no intervalo
    if(f(a) * f(b) < 0) {
        //zera as variaveis auxiliares
        float c = 0;
        float erroa = 0;
        float errob = 0;
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
            printf("Na iteração %d a raiz é aproximandamente: %f\n", i, c);
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
        }while ((erroa > erro || errob > erro));
        printf("A raiz é aproximadamente: %f\n", c);
    }
    else {
        printf("Sem raiz nesse intervalo.\n");
    }
}

void newton_raphson(float a, float erro, funcao f, funcao df) {
    float x = 0;
    float xant;
    int i=0;
    do {
        xant = x;
        x = x - (f(x))/(df(x));
        i++;
        printf("\nInteracao: %d raiz: %f f(x): %f", i, x, f(x));
    }while(fabs((x-xant)/x) > erro);
    printf("\nA raiz eh aproximadamente: %f\n", x);
}

int gauss_seidel(float a[MAX][MAX], float b[MAX], float x[MAX], int n, float erro) {
    int i, j, t = 0;
    float y[MAX], maiorErro, vErro[MAX];
    printf("\n");
    //verifica se algum a(i,i) e igual a zero
    for(i = 0; i < n; i++){
        if(a[i,i] == 0) {
            printf("O a(%d,%d) é igual a ZERO!!!\n", i+1, i+1);
            return 0; 
        }
    }
    do {
        for (i = 0; i < n; i++) {
            //calcula o valor atualizado de x
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++) {
                if (j != i) {
                    y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                }                
            }
            //calcula o erro
            vErro[i] = (y[i] - x[i]) / y[i];
            vErro[i] = abs(vErro[i]);
            //atualiza x
            x[i] = y[i];

            printf("x(%d) = %f   ", i+1, y[i]);
        }
        //verifica qual o maior erro
        maiorErro = 0;
        for(i = 0; i < n; i++) {
            if(vErro[i] > maiorErro) {
                maiorErro = vErro[i];
            }
        }
        t++;
        printf("\n");
        //Condição da parada
    } while(maiorErro >= erro);
    printf("Com erro de %f e %d loops, os valores finais de x:\n", maiorErro, t);
    for (i = 0; i < n; i++) {
        printf("x(%d) = %f\n", i+1, x[i]);
    }
    return 1;
}