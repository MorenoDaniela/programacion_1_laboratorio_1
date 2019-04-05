#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones.h"
int getArray(int* arrayPResultado,int limite,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{

    int i;
    int num;
    int ret;
    for (i=0;i<limite;i++)
    {
        ret = utn_getNumero(&num,"Ingrese Numero: ","Error al Ingresar Numero",1,10,3);
        if (ret)
        {
            break;
        }
        else
        {
        *(arrayPResultado+1)= num;
        }

    }
    return ret;
}

/*int utn_getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    int num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getInt(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}*/

/*int getInt(int *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atoi(buffer);
    return 0;
}*/

int utn_getFloat(float *pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    float num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getFloat(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getFloat(float *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atof(buffer);
    return 0;
}

int utn_getChar(char* pResultado,const char *mensaje,const char *mensajeError,const char *minimo,const char *maximo,int reintentos)
{
    int ret = -1;
    char buffer[64];
    int i;

    do{
        printf("%s",mensaje);
        scanf("%s", buffer);
        i=0;
        while (buffer[i]!='\0' && i<2)
        {

            if (buffer[0]>=minimo[0] && buffer[0]<=maximo[0])
            {
                ret=0;
            }
            i++;
        }

        if (ret==0 && i==1)
        {
            pResultado = buffer;
            break;
        }
        reintentos--;
        printf("%s\n",mensajeError);
        ret = -1;
        __fpurge(stdin);

    }while (reintentos>0);
    return ret;
}

int getInt (char* msg, char* msgErr, int maximo, int minimo, int reintentos, int* resultado)

int getArrayInt (char* msg, char* msgError, int maximo, int minimo, int reintentos, int* resultado, int limite)
{
        int retorno=-1;
        int i;
        int buffer;

        if (resultado!=NULL &&msg!=NULL &&msgError!=NULL && minimo<=maximo && reintentos>=0 && limite>0)
        {
            retorno =0;
            for (i=0;i<limite;i++)
            {
                if (utn_getNumero(msg, msgError, maximo, minimo, reintentos)==0)
                {
                    resultado [i]=buffer;
                    //return 0;
                }
                else
                {
                    return retorno;
                    //break;
                }
            }
        }

        return retorno;
}

void printArrayInt (int* arrayResultado, int limite)
{
    int i;
    for (i=o;i<limite;i++)
    {
        printf ("%d\n", arrayResultado[i]);

    }
}









