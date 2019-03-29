#include <stdio.h>
#include <stdlib.h>

int getInt (char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado);
float getFloat (char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado);
int isValidInt (int numero, int minimo, int maximo);
float isValidFloat (float numero, float minimo, float maximo);

int main()
{
    /*int numeroIngresado;
    getInt ("Ingrese el numero","Error", 0, 50, 2,&numeroIngresado);
    printf ("\n El numero ingresado es %d",numeroIngresado);
    */
    float numeroIngresadoFlotante;
    getFloat ("Ingrese el numero","Error", 0, 100, 2, &numeroIngresadoFlotante);
    printf ("\n El numero ingresado es %f",numeroIngresadoFlotante);
    return 0;
}

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

float getFloat (char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado)
{
    int i;
    float bufferFloat;
    int retorno = -1;
    if (mensaje !=NULL && mensajeError !=NULL && resultado != NULL && maximo>=minimo && reintentos>=0)
    {
        for (i=0;i>=reintentos;i++)
        {
            printf ("%s",mensaje);
            scanf ("%f",&bufferFloat);
            if (isValidFloat (bufferFloat, minimo, maximo))
            {
                *resultado = bufferFloat;
                retorno =0 ;
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

float isValidFloat (float numero, float maximo, float minimo)
{
    if (numero>=minimo && numero<=maximo)
    {
        return 1;
    }
    return 0;
}
