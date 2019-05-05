#ifndef ASOCIADO_C_INCLUDED
#define ASOCIADO_C_INCLUDED
#include "asociado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
//static int generarId(void);

int asociado_initAsociado(Asociado* asociados,int limite)
{
    int i;
    int retorno = -1;
    if(asociados!=NULL && limite>0)
    {
        for(i=0; i<=limite;i++)
        {
            asociados[i].idAsociado=-1;
            asociados[i].isEmpty=1;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int asociado_findFree(Asociado* asociados, int limite)
{
    int i;
    int retorno=-1;
    for(i=0;i<=limite;i++)
    {
        if(asociados[i].isEmpty!=0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int asociado_nuevo(char* msj, char* msjError, Asociado* asociados,int lugarVacio,int reintentos, int limite)
{
    char bufferNombre[50];
    char bufferApellido[50];
    char bufferDni[50];
    int bufferEdad;
    int retorno=-1;


    if(asociados!=NULL && limite>0 && msj!=NULL && msjError!=NULL)
    {
            if(getName("Ingrese nombre del asociado: \n","Error, nombre no valido.\n",4,50,3,bufferNombre)==0 &&
                getApellido("Ingrese apellido del asociado: \n","Error, apellido no valido.",3,50,3,bufferApellido)==0)
            {
                if(getDni("Ingrese dni del asociado: \n","Error, dni no valido\n",7,9,3,bufferDni)==0 &&
                    getInt ("Ingrese edad del asociado: \n","Error, edad no valida\n",18,150,3,&bufferEdad)==0)
                {
                   strncpy(asociados[lugarVacio].nombre,bufferNombre,sizeof(bufferNombre));
                    strncpy(asociados[lugarVacio].apellido,bufferApellido,sizeof(bufferApellido));
                    strncpy(asociados[lugarVacio].dni,bufferDni,sizeof(bufferDni));
                    asociados[lugarVacio].edad=bufferEdad;
                    asociados[lugarVacio].idAsociado=lugarVacio;
                    asociados[lugarVacio].isEmpty=0;
                    retorno=0;
                }
            }
            else
            {
                printf(msjError);
            }
    }
    return retorno;
}

int asociado_baja(char* msj, char* msjError,Asociado* asociados,int reintentos,int limite)
{
    int retorno=-1;
    int i;
    int bufferId;

    if (getInt(msj,"Opcion no valida.Ingrese de nuevo : \n",0,limite,reintentos,&bufferId)!=-1)
    {
        for(i=0;i<limite;i++)
        {
            if (asociados[i].idAsociado == bufferId)
            {
                asociados[i].isEmpty=1;
                retorno=0;
                break;
            }
            else
                {
                    printf(msjError);
                    break;
                }
        }
    }
    return retorno;
}

int asociado_print(Asociado* asociados, int limite)
{
    int i;
    int retorno =-1;

    for (i=0;i<=limite;i++)
    {
        if (asociados[i].isEmpty==0)
        {
            printf ("Nombre del asociado: %s \n",asociados[i].nombre);
            printf ("Apellido del asociado: %s \n",asociados[i].apellido);
            printf ("Dni del asociado: %s \n",asociados[i].dni);
            printf ("Edad del asociado: %d \n",asociados[i].edad);
            printf ("Id del asociado: %d \n",asociados[i].idAsociado);
            printf ("Estado del asociado: %d \n",asociados[i].isEmpty);
        }
        retorno =0;
        break;
    }
    return retorno;
}

int findById (char* msj,char* msjError, Asociado* socios, int* id, int limite)
{
    int retorno = -1;
    int i;
    Asociado bufferSocios;

    if (getInt(msj,"\nError, vuelva a ingresar: ",1,1,3,&bufferSocios.idAsociado)==0)
    {
        for (i=0;i<limite;i++)
        {
            if (socios[i].idAsociado == bufferSocios.idAsociado)
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

int modificarDatos(char* msj, char* msjError,Asociado* socios,int reintentos, int limite)
{
    int retorno=-1;
    int i;
    int bufferId;
    char bufferName[50];
    char bufferApellido[50];
    char bufferDni[50];
    int bufferEdad;
    int opcion;

    if (getInt(msj,"Opcion no valida\n",0,limite,reintentos,&bufferId)==0)
    {
        for (i=0;i<limite;i++)
        {
            if (socios[i].idAsociado==bufferId)
            {
                while (opcion!=5)
                {
                    getInt("\nIngrese el dato a modificar: \n 1-Nombre\n2-Apellido\n3-Dni\n4-Edad\n5-Salir\n","Opcion no valida",1,5,reintentos,&opcion);
                        switch(opcion)
                        {
                            case 1:
                                {
                                    fflush(stdin);
                                    if (getName("\nIngrese el nuevo nombre: \n","Error, nombre no valido.",3,25,reintentos,bufferName)==0)
                                    {
                                        strncpy(socios[i].nombre,bufferName,sizeof(bufferName));
                                    }
                                        else
                                        {
                                            printf(msjError);
                                        }
                                }
                                break;
                            case 2:
                                {
                                    fflush(stdin);
                                    if (getApellido("\nIngrese el nuevo apellido: \n","Error, apellido no valido",3,50,reintentos,bufferApellido)==0)
                                    {
                                        strncpy(socios[i].apellido,bufferApellido,sizeof(bufferApellido));
                                    }
                                        else
                                        {
                                            printf(msjError);
                                        }
                                }
                                break;
                            case 3:
                                {
                                    fflush(stdin);
                                    if (getDni("\nIngrese el nuevo dni: \n","Error, dni no valido\n",7,9,reintentos,bufferDni)==0)
                                    {
                                        strncpy(socios[i].dni,bufferDni,sizeof(bufferDni));
                                    }
                                        else
                                        {
                                            printf(msjError);
                                        }
                                }
                                break;
                            case 4:
                                {
                                    fflush(stdin);
                                    if (getInt("\nIngrese la nueva edad: \n","Error,edad no valida\n",18,150,reintentos,&bufferEdad)==0)
                                    {
                                        socios[i].edad=bufferEdad;
                                    }
                                        else
                                        {
                                            printf(msjError);
                                        }
                                }
                                break;
                            case 5:
                                {

                                }
                                break;
                        }//fin switch
                        retorno =0;
                }//fin while
            }
            else
            {
                printf ("\nError, id no encontrado.\n");
                break;
            }
        }//fin del for
    }
    return retorno;
}
#endif // ASOCIADO_C_INCLUDED
