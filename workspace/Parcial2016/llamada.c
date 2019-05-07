#ifndef LLAMADA_C_INCLUDED
#define LLAMADA_C_INCLUDED
#include "llamada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int dos_initStruct(Llamadas* call, int limite)
{
    int retorno = -1;
    int i;
    if (call!=NULL && limite>0)
    {
        for (i=0; i<limite; i++)
        {
            call[i].estado = 1;
            retorno=0;
        }
    }
    return retorno;
}

int dos_findEmpty (Llamada* call,int limite, int* resultado)
{
    int retorno=-1;
    int i;

    for (i=0;i<limite;i++)
    {
        if (call[i].estado==1)
        {
            *resultado=i;
            retorno=0;
            break;
        }
        //retorno = 1;
    }
    return retorno;
}

#endif // LLAMADA_C_INCLUDED
