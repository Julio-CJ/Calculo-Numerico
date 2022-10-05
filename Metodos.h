#ifndef DataStructure_Metodos_h
#define DataStructure_Metodos_h

#include <stdlib.h>
#include <stdio.h>

typedef float (*funcao)(float);

void bisseccao(float a, float b, float erro, int imax, funcao f);

#endif