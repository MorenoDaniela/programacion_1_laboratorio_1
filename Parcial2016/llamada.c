#ifndef LLAMADA_C_INCLUDED
#define LLAMADA_C_INCLUDED
#include "llamada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int llamada_initLlamadas(Llamada* llamado,int limite)
{
    int i;
    if(llamado!=NULL && limite>0)
    {
        for(i=0; i<limite;i++)
        {
            llamado[i].idLlamada=-1;
            llamado[i].estado=1;
        }
    }
    return 0;
}

int llamada_findFree(Llamada* llamados, int limite)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if(llamados[i].estado==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
//int llamada_nueva

#endif // LLAMADA_C_INCLUDED
