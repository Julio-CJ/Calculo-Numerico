#include "Metodos.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float f(float x) {
    float y;

    float R = x;
    float L = 5;
    float t = 0.05;
    float C = 0.0001;
    float qq0 = 0.01;

    y = 1 / exp(R*t/(2*L)) * cos(sqrt(1/(L*C) - pow(R/(2*L), 2)) * t) - qq0;

    return y;
}

int main () {
    int opc = 0;

    do {
        printf("\n");
        printf("Escolha uma opção: \n");
        printf("(1) - Usar método;\n");
        printf("(0) - Sair.\n");
        scanf("%d", &opc);
        int imax;
        float a, b, erro;

        switch ( opc ) {
            case 1 :
                

                printf("Digite o valor de a: ");
                scanf("%f", &a);
                printf("Digite o valor de b: ");
                scanf("%f", &b);
                printf("Digite o valor do erro: ");
                scanf("%f", &erro);
                printf("Digite o valor maximo de iteracoes imax: ");
                scanf("%d", &imax);

                printf("O valor de a: %f\n", a);
                printf("O valor de b: %f\n", b);
                printf("O valor de erro: %f\n", erro);
                printf("O valor maximo de iteracoes imax: %d\n", imax);

                bisseccao(a, b, erro, imax, f);
                break;
            case 0 :
                printf("\n");
                printf("Saindo.\n");
                break;
            default :
                printf("\n");
                printf("Opção inválida.\n");
        }
    } while (opc != 0);
    return EXIT_SUCCESS;
}