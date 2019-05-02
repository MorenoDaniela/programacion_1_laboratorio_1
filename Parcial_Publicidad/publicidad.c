#ifndef PUBLICIDAD_C_INCLUDED
#define PUBLICIDAD_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "funciones.h"
#include "pantalla.h"
#include "publicidad.h"
#include <string.h>
#define CANT_PANTALLAS 10
#define CANT_PUBLICIDAD 10

int pub_initArray (Publicidad* arrayPublicidad, int limite)
{
    int retorno = -1;
    int i;
    if (arrayPublicidad != NULL && limite>0)
    {
        for (i=0;i<=limite;i++)
        {
            arrayPublicidad[i].isEmpty=1;
        }
        retorno =0;
    }
    return retorno;
}

int pub_findEmpty (Publicidad* arrayPublicidad, int limite)
{
    int retorno = -1;
    int i;

    if (arrayPublicidad != NULL && limite>0)
    {
        for (i=0;i<limite;i++)
        {
            if (arrayPublicidad[i].isEmpty == 1)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int pub_printArray(Publicidad* arrayPublicidad,Pantalla* arrayPantalla, int limite)
{
    int retorno=-1;
    int i;
    //int posicion;

        for (i=0;i<=limite;i++)
        {
            if (arrayPublicidad[i].isEmpty==0)
            {
                //revisar
                printf("\nId pantalla: %d",arrayPantalla[i].idPantalla);
                printf("\nEstado pantalla: %d",arrayPublicidad[i].isEmpty);
                printf("\nNombre pantalla: %s",arrayPantalla[i].nombre);
                printf("\nCantidad de dias: %d",arrayPublicidad[i].dias);
                printf("\nNombre del video: %s",arrayPublicidad[i].archivo);
                printf("\nCuit: %s \n",arrayPublicidad[i].cuit);
            }
            retorno=1;
        }

    return retorno;
}

int pub_alta (char* msjError,Pantalla* arrayPantalla, Publicidad* arrayPublicidad,int reintentos, int limite, int id)
{
    int retorno = -1;
    int lugarVacio;
    int bufferId;
    //int posicion;
    int bufferDias;
    char bufferCuit[4096];
    char bufferArchivo[4046];
    //Pantalla bufferPantalla;

    if (msjError !=NULL && arrayPublicidad != NULL)
    {
        if (pub_findEmpty(arrayPublicidad,limite)!=-1)
        {
            lugarVacio = pub_findEmpty(arrayPublicidad,limite);

            if (getInt("Ingrese el id de la pantalla por contratar: ","Error, id no valido",5,CANT_PUBLICIDAD,3,&bufferId)==0 &&
                getString ("\n Ingrese cuit: ", "\nError, cuit no valido.", 11, 11, reintentos,bufferCuit)==0 &&
                getInt("\nIngrese la cantidad de dias :","\nError, dias no validos.",1,20,reintentos,&bufferDias)==0 &&
                getString ("\n Ingrese el nombre del archivo: ", "\nError, nombre no valido.",5,50,reintentos,bufferArchivo)==0)
            {
                strncpy (arrayPublicidad[lugarVacio].cuit,bufferCuit,11);
                strncpy(arrayPublicidad[lugarVacio].archivo,bufferArchivo,50);
                arrayPublicidad[lugarVacio].dias=bufferDias;
                arrayPantalla[lugarVacio].idPantalla=bufferId;
                arrayPublicidad[pub_findEmpty(arrayPublicidad,limite)].idPublicidad =id;
                arrayPublicidad[pub_findEmpty(arrayPublicidad,limite)].isEmpty =0;
                retorno=0;
             }
        }
        else
        {
            printf ("\nNo hay espacio, borre alguno y vuelva a intentarlo.\n");
        }
    }
    return retorno;
}

int pub_FindId(Pantalla* arrayPantalla, int limite, int* idEncontrado, int id)
{
    int i;
    int retorno =-1;

    for (i=0;i<limite;i++)
    {
        if (arrayPantalla[i].idPantalla == id)
        {
            retorno = 0;
            *idEncontrado=i;
            break;
        }
    }
    return retorno;
}

#endif // PUBLICIDAD_C_INCLUDED
