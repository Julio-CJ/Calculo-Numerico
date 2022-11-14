#ifndef DataStructure_Metodos_h
#define DataStructure_Metodos_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef float (*funcao)(float);

void bisseccao(double a, double b, float erro, int imax, funcao f);
void newton(float a, float erro, int imax, funcao f, funcao df);

#endif