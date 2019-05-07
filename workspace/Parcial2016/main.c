#include <stdio.h>
#include <stdlib.h>
#include "asociado.h"
#include "llamada.h"
#include "funciones.h"
#include "validaciones.h"
#include <string.h>
#define MAX_SOCIOS 10
#define MAX_LLAMADOS 10
#define REINTENTOS 3
int main()
{
    int opcion=0;
    int idSocio=0;
    int idLlam=0;
    int lugarVacioAsociado;
    int lugarVacioLlamada;
    int flag=0;
    Asociado asociados [MAX_SOCIOS];
    Llamada llamadas [MAX_LLAMADOS];

    uno_initStruct(asociados, MAX_SOCIOS);

   //probar
    strcpy(asociados[0].nombre,"Daniela");
    strcpy(asociados[0].apellido,"Moreno");
    strcpy(asociados[0].dni,"35753206");
    asociados[0].edad=28;
    asociados[0].isEmpty=0;
    asociados[0].idAsociado=0;

    strcpy(asociados[1].nombre,"Natalia");
    strcpy(asociados[1].apellido,"Dumrauf");
    strcpy(asociados[1].dni,"30000000");
    asociados[1].edad=25;
    asociados[1].isEmpty=0;
    asociados[1].idAsociado=1;

    strcpy(asociados[2].nombre,"Marina");
    strcpy(asociados[2].apellido,"Gallardo");
    strcpy(asociados[2].dni,"18161002");
    asociados[2].edad=53;
    asociados[2].isEmpty=0;
    asociados[2].idAsociado=2;
    flag=1;
    //fin probar

    while (opcion!=9)
    {
        getInt("\nMENU\n1-Alta asociado.\n2-Baja asociado.\n3-Modificar asociado.\n"
               "4-Nueva llamada.\n5-Asignar ambulancia\n"
               "6-Nombre y apellido del asociado con mas llamadas.\n"
               "7-Motivos mas recurrentes y cantidad.\n"
               "8-Motivo que mas demora.\n9-Salir\n","Error, opcion no valida.\n",1,9,REINTENTOS,&opcion);
               system("cls");//system("clear");

               switch(opcion)
               {
                    case 1:
                            if (uno_findEmpty(asociados,MAX_SOCIOS,&lugarVacioAsociado)!=0)
                            {
                                printf ("\nNo hay espacio, lleno.\n");
                            }
                            else
                            {
                                switch (uno_alta(asociados,lugarVacioAsociado,idSocio,MAX_SOCIOS))
                                {
                                case 0:
                                    printf ("\n***Ingreso correcto.***\n");
                                    idSocio++;
                                    flag=1;
                                    break;
                                case 1:
                                    printf("\n***Ingreso incorrecto.***\n");
                                    break;
                                }
                            }
                    break;
                   case 2:
                        if (flag==1)
                        {
                            uno_print(asociados,MAX_SOCIOS);
                            if (uno_baja(asociados,MAX_SOCIOS)==0)
                            {
                                printf ("\nSe borro con exito.");
                            }
                        }else
                            {
                                printf("No hay asociados para dar de baja.\n");
                            }
                    break;
                   case 3:
                        if(flag==1)
                        {
                            uno_print(asociados,MAX_SOCIOS);
                            if (uno_modificar("Ingrese el id del asociado a modificar: \n",asociados,MAX_SOCIOS)==0)
                            {
                                printf ("Se modifico con exito los datos del asociado.\n");
                            }
                        }else
                            {
                                printf("No hay asociados para modificar.\n");
                            }
                    break;
                    case 4:

                    break;
                    case 5:

                    break;
                    case 6:

                    break;
                    case 7:

                    break;
                    case 8:

                    break;
                    case 9:

                    break;
               }
    }
return 0;
}
