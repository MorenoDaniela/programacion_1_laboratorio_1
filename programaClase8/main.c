#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTY_EMPLEADOS 10
#define MAXIMO_NOMBRE 50

int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int isValidName (char* cadena);
int printArray (char arrayStr[][50], int limite);
int findName (char arrayStr [][50],int limite,char* nombre);
int findEmpty (char arrayStr[][50],int limite);
int startAtZero (char arrayStr [][50], int limite);
int ordenarArray (char arrayStr [][50], char *nombre, int limite);
int borrarNombre(char* msgError, char arrayStr[][50], char *nombre, int limiteArray, int limiteNombre);
int cargarNombre (char*msgError, char arrayStr[][50],char *nombre, int limiteArray, int limiteNombre);

int main()
{
    char auxName [MAXIMO_NOMBRE];
    char arrayNombres [QTY_EMPLEADOS] [MAXIMO_NOMBRE];
    int opcion;

    strncpy(arrayNombres[0],"Juan",MAXIMO_NOMBRE);
    strncpy(arrayNombres[1],"Veronica",MAXIMO_NOMBRE);
    strncpy(arrayNombres[2],"Carolina",MAXIMO_NOMBRE);
    //
    startAtZero(arrayNombres,QTY_EMPLEADOS);

    while (opcion!=5)
    {
        printf ("\n1- Ingresar nombre.\n");
        printf ("\n2- Listar nombres.\n");
        printf ("\n3- Ordenar nombres.\n");
        printf ("\n4- Borrar nombre.\n");
        printf ("\n5- Salir.\n");
        scanf ("%d",&opcion);
        fflush(stdin);

       switch (opcion)
        {
            case 1 :
                cargarNombre ("El nombre ingresado esta repetido", arrayNombres,auxName, QTY_EMPLEADOS, MAXIMO_NOMBRE);
            break;

            case 2 :
                printArray (arrayNombres, QTY_EMPLEADOS);
            break;

            case 3 :
                ordenarArray (arrayNombres, auxName, QTY_EMPLEADOS);
            break;

            case 4 :
                borrarNombre("El nombre no se encontro",arrayNombres, auxName, QTY_EMPLEADOS, MAXIMO_NOMBRE);
            break;

            case 5 :
            break;

            default :
            printf ("\nOpcion no valida, ingrese una opcion valida.\n");
            break;
        }
    }
    return 0;
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

int getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
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
    int retorno = 1;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = 0;
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
        if (strncmp(arrayStr[i],"\0",limite)!=0)
            {
                printf ("%s\n",arrayStr[i]);
            }
    }
    return 0;
}

int startAtZero (char arrayStr [][50], int limite)
{
    int i;
    for (i=0;i<limite;i++)
    {
        strncpy (arrayStr[i],"\0",50);
    }
    return 0;
}

int findEmpty (char arrayStr[][50],int limite)
{
    int retorno = -1;
    int i;
    for (i=0;i<limite;i++)
    {
        if (strcmp (arrayStr[i], "\0")==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int findName (char arrayStr [][50],int limite, char* nombre)
{
    int retorno =-1;
    int i;
    for (i=0;i<limite;i++)
    {
        if (strcmp (arrayStr[i], nombre)==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int ordenarArray (char arrayStr [][50], char *nombre, int limite)
{
    int i;
    int j;
    for (i=0;i<limite;i++)
    {
        for (j=i;j<limite;j++)
        {
            if (strncmp(arrayStr[i],arrayStr[j],limite)>0)
            {
                strncpy(nombre,arrayStr[i],limite);
                strncpy(arrayStr[i],arrayStr[j],limite);
                strncpy(arrayStr[j],nombre,limite);
            }
        }
    }
    return 0;
}


int borrarNombre(char* msgError, char arrayStr[][50], char *nombre, int limiteArray, int limiteNombre)
{
    int lugarVacio;
    getName ("\nIngrese el nombre a borrar: \n","Error, nombre no valido.\n,",4,limiteNombre,3,nombre);
    lugarVacio = findName(arrayStr,limiteArray,nombre);
    if (lugarVacio==-1)
    {
        printf(msgError);
    }
    else
    {
        strncpy (arrayStr[lugarVacio],"\0",limiteNombre);
    }
    return 0;
}

int cargarNombre (char*msgError, char arrayStr[][50],char *nombre, int limiteArray, int limiteNombre)
{
    int lugarVacio;
    getName("Ingrese un nombre: ","Error",4,limiteNombre,3,nombre);
    while (findName(arrayStr,limiteArray,nombre)>0)
    {
        printf (msgError);
        getName("Ingrese un nombre: ","Error",4,limiteNombre,3,nombre);
    }
    lugarVacio =findEmpty(arrayStr,limiteArray);
    strncpy (arrayStr[lugarVacio],nombre,limiteNombre);
    return 0;
}








