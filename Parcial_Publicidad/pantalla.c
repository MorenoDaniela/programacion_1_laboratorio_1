#ifndef PANTALLA_C_INCLUDED
#define PANTALLA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "funciones.h"
#include "pantalla.h"
#include <string.h>
#define CANT_PANTALLAS 10

int pant_initArray (Pantalla* arrayPantalla, int limite)
{
    int retorno = -1;
    int i;
    if (arrayPantalla != NULL && limite>0)
    {
        for (i=0;i<=limite;i++)
        {
            arrayPantalla[i].isEmpty=1;
        }
        retorno =0;
    }
    return retorno;
}

int pant_findEmpty (Pantalla* arrayPantalla, int limite)
{
    int retorno = -1;
    int i;

    if (arrayPantalla != NULL && limite>0)
    {
        for (i=0;i<limite;i++)
        {
            if (arrayPantalla[i].isEmpty == 1)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int pant_printArray(Pantalla* arrayPantalla, int limite)
{
    int retorno=-1;
    int i;

        for (i=0;i<=limite;i++)
        {
            if (arrayPantalla[i].isEmpty==0)
            {
                printf("\nId pantalla: %d",arrayPantalla[i].idPantalla);
                printf("\nEstado pantalla: %d",arrayPantalla[i].isEmpty);
                printf("\nNombre pantalla: %s",arrayPantalla[i].nombre);
                printf("\nDireccion: %s",arrayPantalla[i].direccion);
                printf("\nPrecio: %.2f",arrayPantalla[i].precio);
                printf("\nTipo: %s \n",arrayPantalla[i].tipo);
            }
            retorno=1;
        }

    return retorno;
}

int pant_alta (char* msjError, Pantalla* arrayPantalla,int reintentos, int limite, int id)
{
    int retorno = -1;
    int lugarVacio;
    char bufferDireccion [4096];
    char bufferTipo[4096];
    float bufferPrecio;
    char bufferName[4046];

    if (msjError !=NULL && arrayPantalla != NULL)
    {
        if (pant_findEmpty(arrayPantalla,limite)!=-1)
        {
            lugarVacio = pant_findEmpty(arrayPantalla,limite);

            if (getName("\n Ingrese nombre : ","\nError, nombre no valido.",3,25,reintentos,bufferName)==0 &&
                getString ("\n Ingrese direccion: ", "\nError, direccion no valida.", 5, 50, reintentos,bufferDireccion)==0 &&
                getFloat("\nIngrese el precio :","\nError, precio no valido.",2,25000,reintentos,&bufferPrecio)==0 &&
                getString ("\n Ingrese tipo de pantalla LCD o LED: ", "\nError, tipo de pantalla no valido.",3,4,reintentos,bufferTipo)==0)
            {
                strncpy (arrayPantalla[lugarVacio].nombre,bufferName,25);
                strncpy(arrayPantalla[lugarVacio].direccion,bufferDireccion,50);
                arrayPantalla[lugarVacio].precio=bufferPrecio;
                strncpy (arrayPantalla[lugarVacio].tipo,bufferTipo,4);
                arrayPantalla[pant_findEmpty(arrayPantalla,limite)].idPantalla =id;
                arrayPantalla[pant_findEmpty(arrayPantalla,limite)].isEmpty =0;
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



int pant_findId (char* msj,char* msjError, Pantalla* arrayPantalla, int* id, int limite)
{
    int retorno = -1;
    int i;
    Pantalla bufferPantalla;

    if (getInt(msj,"\nError, vuelva a ingresar: ",1,1,3,&bufferPantalla.idPantalla)==0)
    {
        for (i=0;i<limite;i++)
        {
            if (arrayPantalla[i].idPantalla == bufferPantalla.idPantalla)
            {
                retorno=i;
                *id=i;
                break;
            }
        }
    }
    else
    {
        printf (msjError);
    }
    return retorno;
}

int pant_baja(char* msj, char* msjError, Pantalla* arrayPantalla, int limite)
{
    int retorno=-1;
    int posicion;

    pant_printArray(arrayPantalla,limite);

    if (pant_findId("\nIngrese el id de la pantalla a bajar: ","\nError, no se encontro el id.\n",arrayPantalla,&posicion,limite)!=-1)
    {
        if (arrayPantalla[posicion].isEmpty==0)
        {
            arrayPantalla[posicion].isEmpty=1;
            retorno = 0;
        }
    }
    return retorno;
}

int pant_modificar(char*msjError, Pantalla* arrayPantalla, int limite)
{
    int retorno=-1;
    int posicion;
    int opcion;
    //Pantalla bufferPantalla;

    pant_printArray(arrayPantalla,limite);

    if (pant_findId("\nIngrese el id de la pantalla a modificar: ","\nError, no se encontro el id.ªn",arrayPantalla,&posicion,limite)!=-1)
    {
        if (arrayPantalla[posicion].isEmpty==0)
            {
               while (opcion!=5)
               {
                   printf ("\nIngrese una opcion para modificar el dato que desee.");
                   printf ("\n1-Modificar nombre.");
                   printf ("\n2-Modificar direccion.");
                   printf ("\n3-Modificar precio.");
                   printf ("\n4-Modificar tipo de pantalla.");
                   printf ("\n5-Salir de modificacion.");
                   scanf ("%d",&opcion);
                   fflush(stdin);

                   switch (opcion)
                    {
                    case 1 :
                        getName ("\nIngrese el nuevo nombre: ","\nError, nombre no valido",4,25,3,arrayPantalla[posicion].nombre);
                        //strncpy (arrayPantalla[posicion].nombre,bufferPantalla[posicion].nombre,25);
                        printf ("\nNombre cambiado con exito");
                        break;
                    case 2 :
                        getString ("\nIngrese la nueva direccion: ","\nError direccion no valida",2,50,3,arrayPantalla[posicion].direccion);
                        //strncpy (arrayPantalla[posicion].direccion,bufferPantalla[posicion].direccion,50);
                        printf ("Direccion cambiada con exito");
                        break;
                    case 3 :
                        getFloat ("\nIngrese el precio nuevo: ","\nError precio no valido.",1,2500,3,&arrayPantalla[posicion].precio);
                        //arrayPantalla[posicion].precio == bufferPantalla[posicion].precio;
                        printf ("\nPrecio cambiado con exito");
                        break;
                    case 4 :
                        getString ("\nIngrese el tipo de pantalla nuevo: ","\nError, tipo de pantalla no valido",3,3,3,arrayPantalla[posicion].tipo);
                        //strncpy (arrayPantalla[posicion].tipo,bufferPantalla[posicion].tipo,3);
                        printf ("\nTipo cambiado con exito");
                        break;
                    case 5:
                        break;
                    default :
                        printf ("\nOpcion incorrecta");
                        break;
                    }
                }


            }
            retorno = 0;
    }
    else
    {
        printf ("No se encontro el id");
    }
    return retorno;

}

#endif // PANTALLA_C_INCLUDED
