#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getInt(char *message, char *errorMessage, int minimum, int maximum, int retries, int *input);
int getFloat(char *message, char *errorMessage, float minimum, float maximum, int retries, float *input);
int getChar(char *message, char *errorMessage, char minimum, char maximum, int retries, char *input);

#endif // FUNCIONES_H_INCLUDED
