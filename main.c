#include "Metodos.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//definição da função f(x)
float f(float x) {
    float y;

    float R = x;
    float L = 5;
    float t = 0.05;
    float C = 0.0001;
    float qq0 = 0.01;

    y = exp(-1*(R*t/(2*L))) * cos(sqrt(1/(L*C) - pow(R/(2*L), 2)) * t) - qq0;
    
    return y;
}
float g(float x) {
    return(x - cos(x));
}
float dg(float x) {
    return(1 + sin(x));
}

int main () {
    //definindo as variaves
    int opc = 0;
    float ma[MAX][MAX], vb[MAX], vx[MAX], erro, a, b;
    int n, i, j;
    do {
        //menu
        printf("\n");
        printf("Escolha uma opção: \n");
        printf("(1) - Usar método da Bisseccao;\n");
        printf("(2) - Usar método de Newton-Raphson;\n");
        printf("(3) - Usar método de Gauss-Seidel;\n");
        printf("(0) - Sair.\n");
        scanf("%d", &opc);
        switch ( opc ) {
            case 1 :
                //escolher o intervalo
                printf("Digite o valor de a: ");
                scanf("%f", &a);
                printf("Digite o valor de b: ");
                scanf("%f", &b);
                //escolher o erro
                printf("Digite o valor do erro: ");
                scanf("%f", &erro);
                //conferindo os valores dados
                printf("O valor de a: %f\n", a);
                printf("O valor de b: %f\n", b);
                printf("O valor de erro: %f\n", erro);
                //chama o metodo e fornece as variaveis
                bisseccao(a, b, erro, f);
                break;
            case 2 :
                //escolher valor inicial
                printf("Digite o valor de a: ");
                scanf("%f", &a);
                //escolher o erro
                printf("Digite o valor do erro: ");
                scanf("%f", &erro);
                //conferindo os valores dados
                printf("O valor de a: %f\n", a);
                printf("O valor de erro: %f\n", erro);
                //chama o metodo e fornece as variaveis
                newton_raphson(a, erro, g, dg);
                break;
            case 3 :
                //escolher o tamanho da matriz
                printf("Digite o tamanho da matriz quadrada (Max %d): ", MAX);
                scanf("%d", &n);
                //escolher o erro
                printf("Digite o valor do erro: ");
                scanf("%f", &erro);
                //informar as variaveis da matriz M
                printf("LEMBRETE!!! Os valores a(i,i) devem ser diferentes de 0.\n");
                for (i = 0; i < n; i++) {   
                    for (j = 0; j < n; j++) {
                        printf("Digite o valor de a(%d,%d): ", i+1, j+1);
                        scanf("%f", &ma[i][j]);
                    }
                }
                //informar os valores do vetor v
                for (i = 0; i < n; i++) {
                    printf("Digite o valor de b(%d): ", i+1);
                    scanf("%f", &vb[i]);
                }
                //informar os valores iniciais de x
                for (i = 0; i < n; i++) {
                    printf("Digite o valor de x(%d): ", i+1);
                    scanf("%f", &vx[i]);
                }
                //conferindo os valores dados
                printf("O tamanho da matriz: %d\n", n);
                printf("O valor de erro: %f\n", erro);
                printf("A matriz aumentada M + b:\n");
                for (i = 0; i < n; i++) {   
                    for (j = 0; j < n; j++) {
                        printf("%f ", ma[i][j]);
                    }
                    printf("| %f\n", vb[i]);
                }
                printf("Os valores inicias de x:\n");
                for (i = 0; i < n; i++) {
                    printf("x(%d) = %f\n", i+1, vx[i]);
                }
                //chama o metodo e fornece as variaveis
                gauss_seidel(ma, vb, vx, n, erro);
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