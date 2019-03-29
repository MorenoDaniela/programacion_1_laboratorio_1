#include <stdio.h>
#include <stdlib.h>

int isValidInt (int numero, int minimo, int maximo) //isIntInRange
{
    if (numero>=minimo && numero<=maximo)
    {
        return 1 ;
    }
    return 0;
}

int getInt (char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado)
{
    int i;
    int bufferInt;
    int retorno = -1;
    if (mensaje != NULL && mensajeError !=NULL && resultado !=NULL && maximo>=minimo && reintentos>=0)
    {
        for (i=0;i<=reintentos;i++)
        {
            printf ("%s", mensaje);
            scanf ("%d",&bufferInt);
            if (isValidInt (bufferInt, minimo, maximo))
            {
                *resultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf ("%s",mensajeError);
            }
         }
    }

    return retorno;
}

int getFloat (char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado)
{
    int i;
    float bufferFloat;
    int retorno = -1;
    if (mensaje !=NULL && mensajeError !=NULL && resultado != NULL && maximo>=minimo && reintentos>=0)
    {
        for (i=0;i<=reintentos;i++)
        {
            printf ("%s",mensaje);
            scanf ("%f",&bufferFloat);
            if (isValidFloat (bufferFloat, minimo, maximo))
            {
                *resultado = bufferFloat;
                retorno = 0 ;
                break;
            }
            else
            {
                printf ("%s",mensajeError);
            }
        }
        return retorno;
    }
}

int isValidFloat (float numero, float minimo, float maximo)
{
    if (numero>=minimo && numero<=maximo)
    {
        return 1;
    }
    return 0;
}

int getChar (char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    int i;
    char bufferChar;
    int retorno = -1;
    if (mensaje !=NULL && mensajeError !=NULL && resultado != NULL && maximo>=minimo && reintentos>=0)
    {
        for (i=0;i<=reintentos;i++)
        {
            printf ("%s",mensaje);
            scanf ("%f",&bufferChar);
            if (isValidChar (bufferChar, minimo, maximo))
            {
                *resultado = bufferChar;
                retorno = 0 ;
                break;
            }
            else
            {
                printf ("%s",mensajeError);
            }
        }
        return retorno;
    }
}

int isValidChar (char texto, char minimo, char maximo)
{
    if (texto>=minimo && texto<=maximo)
    {
        return 1;
    }
    return 0;
}

