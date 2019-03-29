#include <stdio.h>
#include <stdlib.h>

int getInt (char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado);
int getFloat (char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado);
int isValidInt (int numero, int minimo, int maximo);
int isValidFloat (float numero, float minimo, float maximo);
