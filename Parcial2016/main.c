#include <stdio.h>
#include <stdlib.h>
#include "asociado.h"
#include "llamada.h"
#include "funciones.h"
#include "validaciones.h"

#define MAX_SOCIOS 10
#define MAX_LLAMADOS 10

int main()
{
    int opcion;
    int lugarVacio;
    int flag=0;
    Asociado socios[MAX_SOCIOS];
    Llamada llamados [MAX_LLAMADOS];

    //sistema en 0
    asociado_initAsociado(socios,MAX_SOCIOS);
    llamada_initLlamadas(llamados,MAX_LLAMADOS);
    //flag=1;

    while (opcion!=9)
    {
        getInt("\n1-Alta del asociado.\n2-Modificar datos del asociado.\n3-Baja del asociado.\n4-Nueva llamada."
               "\n5-Asignar ambulancia.\n6-Nombre y apellido del asociado con mas llamados."
               "\n7-Motivos mas recurrentes y cantidad.\n8-Motivo que mas demora en ser resuelto.\n9-Salir.\n"
               ,"\nError opcion no valida\n",1,10,3,&opcion);
        switch(opcion)
        {
            case 1:
            {
                lugarVacio=asociado_findFree(socios,MAX_SOCIOS);
                fflush(stdin);
                    if(asociado_nuevo("Se dara de alta un nuevo asociado.\n","No se pudo dar de alta\n",socios,lugarVacio,3,MAX_SOCIOS)==0)
                    {
                        flag=1;
                        printf("\n****Se dio de alta exitosamente.****\n");
                    }
                    else
                    {
                        printf ("No se pudo realizar el alta.\n");
                    }
                break;
            }
            case 2://modificar
            {
                asociado_print(socios, MAX_SOCIOS);
                fflush(stdin);
                modificarDatos("\nIngrese el id del asociado a modificar : \n","\nError, no se pudo modificar con exito.\n",socios,3,MAX_SOCIOS);
                break;
            }
            case 3://baja
            {
                    if (flag)
                    {
                        asociado_print(socios, MAX_SOCIOS);
                        if (asociado_baja("\nIngrese el id del asociado a dar de baja : \n","Id no encontrado\n",socios,3,MAX_SOCIOS)==0)
                        {
                            printf ("\n**Baja con exito.**\n");
                        }
                    }
                    else
                    {
                        printf ("\nNo hay asociados para dar de baja.\n");
                    }


                break;
            }
            case 4:
            {

                break;
            }
            case 5:
            {

                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {

                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {

                break;
            }


        }//fin switch

    }//fin while
}//fin main
