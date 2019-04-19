#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTY_EMPLEADOS 10
#define MAXIMO_NOMBRE 25

int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int isValidName (char* cadena);
int printArray (char arrayStr[][50], int limite);
int findName (char arrayStr [][50],int limite,char* nombre);
int findEmpty (char arrayStr[][50],int limite);
int startAtZero (char arrayStr [][50], int limite);

int main()
{
    char auxName [50];
    char arrayNombres [QTY_EMPLEADOS] [50];
    int opcion;
    int lugarVacio;
    //int i;
    //testeando
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
                getName ("Ingrese un nombre: ","Error.",2,MAXIMO_NOMBRE,3,auxName);
                while (findName(arrayNombres,QTY_EMPLEADOS,auxName)>=0)
                {
                    printf ("\nEl nombre ingresado esta repetido.");
                    getName ("Ingrese un nombre nuevamente: ","Error",2,MAXIMO_NOMBRE,3,auxName);
                }
                lugarVacio= findEmpty(arrayNombres, QTY_EMPLEADOS);
                strncpy(arrayNombres[lugarVacio],auxName,MAXIMO_NOMBRE);
                //printf ("%s",arrayNombres[lugarVacio]);
            break;

            case 2 :
                for (int i=0;(strncmp(arrayNombres[i],"\0",MAXIMO_NOMBRE)!=0);i++)
                {
                    printf ("%s\n",arrayNombres[i]);
                }
                /*i =0;
                while (strncmp(arrayNombres[i],"\0",MAXIMO_NOMBRE)!=0)
                {
                    printf ("%s\n",arrayNombres[i]);
                    i++;//hacer con for
                }*/
            break;

            case 3 :

            break;

            case 4 :
                getName("\nIngrese el nombre a borrar: \n","Error\n",2,MAXIMO_NOMBRE,3,auxName);
                lugarVacio = findName(arrayNombres,QTY_EMPLEADOS,auxName);
                if (lugarVacio==-1)
                {
                    printf ("El nombre no se encontro.\n");

                }
                else
                {
                    strncpy (arrayNombres[lugarVacio],"\0",MAXIMO_NOMBRE);
                }
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
    for (i=0;i<=limite;i++)
    {
        printf ("%s\n",arrayStr[i]);
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












