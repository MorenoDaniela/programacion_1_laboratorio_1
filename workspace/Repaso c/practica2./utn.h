#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include <string.h>

int getPrecio (char* mensaje, float *elPrecio)
{
    char ingreso [50];
    float auxPrecio;
    int retorno=0;
    printf (mensaje);
    scanf ("%s",ingreso);
    auxPrecio = atof(ingreso);
    if (auxPrecio>0)
    {
        *elPrecio = auxPrecio;

    }
    return retorno;
}

int getCodigo (char* mensaje, char *codigo)
{
    char ingreso [50];
    int retorno =0;
    printf (mensaje);
    scanf ("%s",ingreso);
    if (strlen(ingreso)==6)
    {
        strcpy (codigo,ingreso);
        retorno =1;

    }
    return retorno;
}

#endif // UTN_H_INCLUDED
