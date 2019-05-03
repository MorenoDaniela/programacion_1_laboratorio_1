#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "Publicidad.h"
#include "utn_strings.h"
#include "incluye.h"
#include <string.h>

int mostrarMenorADiez (Pantalla* arrayPan,int limitePan, Publicidad* arrayPub,int limitePub)
{
    Pantalla aux;
    int i;

    for (i=0;i<limitePan;i++)
    {
        if (arrayPub[i].isEmpty==1)
        {
        continue;
        }
        if (arrayPub[i].dias<=10)
        {
            getById(arrayPan,arrayPub[i].idPantalla,limitePan,&aux);

            printf ("Nombre: %s\n",aux.nombre);
            printf ("Precio unitario: %.2f\n",aux.precio);
            printf ("Dias contratados: %d\n",arrayPub[i].dias);
            printf ("Precio total de la contratacion: %.2f\n", aux.precio * arrayPub[i].dias);
        }
    }
    return 0;
}

