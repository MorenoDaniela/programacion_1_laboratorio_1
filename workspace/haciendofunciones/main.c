#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 8

int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getDni ( char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int isValidDni (char* cadena);

int main()
{
    char auxDni [CANTIDAD];
    getDni ("Ingrese dni: ","Error",7,8,3,auxDni);
}

int getDni ( char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno =-1;
    char bufferDni[4096];

    if (msg!=NULL && msgError!=NULL && minimo>maximo && reintentos>=0 && resultado!=NULL)
    {
        if (!getString(msg, msgError, minimo, maximo, reintentos, bufferDni))
        {
            if (isValidDni(bufferDni))
            {
                strncpy(resultado, bufferDni,maximo);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int isValidDni (char* cadena)
{
    int retorno = 1;
    int i;
    for (i=0; cadena[i] != '\0';i++)
    {
        if (cadena[i] >=0 && cadena[i]<=9)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

