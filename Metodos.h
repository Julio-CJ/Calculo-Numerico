#ifndef DataStructure_Metodos_h
#define DataStructure_Metodos_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 10

typedef float (*funcao)(float);

void bisseccao(float a, float b, float erro, funcao f);

void newton_raphson(float a, float erro, funcao f, funcao df);

int gauss_seidel(float m[MAX][MAX], float b[MAX], float x[MAX], int n, float erro);

#endif