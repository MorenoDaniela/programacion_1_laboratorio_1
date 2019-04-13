#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define TAMANIO 3

int main()
{
    float precios [TAMANIO];
    char codigos [TAMANIO][7];
    int i;

    for (i=0;i<TAMANIO;i++)
    {
        while (getPrecio("Ingrese precio",&precios [i])==0)
        {
            printf ("Error...");

        }

        while (getCodigo("Ingrese el codigo",&codigos[i])==0)
        {
            printf ("Error...");
        }
    }

    for (i=0;i<TAMANIO;i++)
    {

    }

    for ()
    {

        for ()
        {

        }
    }


}
