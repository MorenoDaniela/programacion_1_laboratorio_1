#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#define QTY_EMPLEADOS 10

int main()
{
    char auxName[50];

    char arrayNombres [QTY_EMPLEADOS][50];

    /*strncpy (arrayNombres[0],"JUAN",50);
    strncpy (arrayNombres[1],"ANA",50);
    strncpy (arrayNombres[2],"SOL",50);*/

    getName ("Ingrese nombre", "error",5,25,3,auxName);


    /*printArray (arrayNombres,4);

    if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }*/
    return 0;
}





/*Hacer un programa con el siguiente menu:
   1) ingresar nuevo nombre (no acepta nombres repetidos)
   2) listar todo
   3) ordenar por nombre
   4) Borrar nombre. Se ingresa el nombre y si se encuentra se elimina de la lista

El programa permitira ingresar hasta 100 nombres.

4) Modificar el programa para que ademas del nombre se ingrese y guarde el DNI.*/

//inicializar
//encontrar el vacio (que pueda devolver el indice donde esta vacio)
//encontrar el nombre si esta o no(que me devuelva el indice en donde esta el nombre)


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
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

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}


int isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

int printArray (char arrayStr[][50], int limite)
{
    int i;

    for (i=0;i<limite;i++)
    {
        printf ("%s:",arrayStr[i]);
    }
    return 0;
}

int iniciaCero (char arrayStr [][50], int limite)
{
    int i;
    for (i=0;i<limite;i++)
    {
        strncpy (arrayStr[i],"\0",50);
    }
    return 0;
}

int encontrarVacio (char arrayStr[][50],int limite, int* posicionVacia)
{
    int retorno = -1;
    int i;
    for (i=0;i<limite;i++)
    {
        if (strcmp (arrayStr[i], "\0")==0)
        {
            *posicionVacia = i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int encontrarNombre (char arrayStr [][50],char* nombre,int* posicionRepetida, int limite)
{
    int retorno =-1;
    int i;
    for (i=0;i<limite;i++)
    {
        if (strcmp (arrayStr[i], nombre)==0)
        {
            *posicionRepetida=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

//----------------------------------------

#define TRUE 1
#define FALSE 0

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//-------------------------------------

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);


int isValidName (char* cadena);

int printArray (char arrayStr[][50], int limite);

int encontrarNombre (char arrayStr [][50],char* nombre,int* posicionRepetida, int limite);

int encontrarVacio (char arrayStr[][50],int limite, int* posicionVacia);

int iniciaCero (char arrayStr [][50], int limite);
