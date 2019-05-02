#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "publicidad.h"
#define CANT_PANTALLAS 10
#define CANT_PUBLICIDAD 10

int main()
{
    int opcion;
    int generadorId=1;
    //int posicion;
    //int idEncontrado;
    int generadorIdPublicidad=1;
    Pantalla auxArray [CANT_PANTALLAS];
    Publicidad auxArrayPublicidad [CANT_PUBLICIDAD];

    pant_initArray(auxArray,CANT_PANTALLAS);
    pub_initArray(auxArrayPublicidad,CANT_PUBLICIDAD);

    while (opcion!=11)
    {
        printf("\n 1- Alta de pantalla.");
        printf("\n 2- Modificar datos de pantalla.");
        printf("\n 3- Baja de una pantalla.");
        printf("\n 4- Contratar una publicidad.");
        printf("\n 5- Modificar condiciones de una publicidad.");
        printf("\n 6- Cancelar publicidad.");
        printf("\n 7- Consulta facturacion.");
        printf("\n 8- Listar publicidades.");
        printf("\n 9- Listar pantallas.");
        printf("\n 10- Informes.\n");
        printf("\n 11- Salir.\n");
        scanf ("%d",&opcion);
        fflush(stdin);

        switch (opcion)
        {
            case 1 :
                    if (pant_alta("\nNo se pudo cargar correctamente.",auxArray,3,CANT_PANTALLAS,generadorId)==0)
                    {
                        generadorId++;
                        printf ("\nAlta exitosa :)");
                    }
                    else
                    {
                        printf ("\nError, no se pudo cargar, vuelta a intentarlo.");
                    }

            break;

            case 2 :
                    pant_modificar("No se pudo modificar con exito",auxArray,CANT_PANTALLAS);
            break;

            case 3 :
                    pant_baja("Ingrese el id a borrar","No se pudo bajar con exito",auxArray,CANT_PANTALLAS);

            break;

            case 4 :
                    pant_printArray(auxArray,CANT_PANTALLAS);
                    printf ("ACAA");
                    //pub_alta("No se pudo dar de alta la publicidad.", auxArrayPublicidad,3,CANT_PUBLICIDAD,generadorIdPublicidad);
                    //idEncontrado = pant_findId("Ingrese el id de la pantalla en la que va a publicitar: ","Error, no se pudo encontrar el id",auxArray,&posicion,CANT_PANTALLAS);
                    if (pub_alta("No se pudo dar de alta la publicidad.", auxArray, auxArrayPublicidad,3,CANT_PUBLICIDAD,generadorIdPublicidad)==0)
                    {
                        printf ("Entro aca");
                        generadorIdPublicidad++;
                        printf ("\nAlta de publicidad exitosa");
                    }
                        else
                            {
                                printf ("\nError, no se pudo dar de alta correctamente.");
                            }
            break;

            case 5 :
            break;

            case 6 :

            break;

            case 7 :

            break;

            case 8 :
                    pub_printArray(auxArrayPublicidad,auxArray,CANT_PUBLICIDAD);
            break;

            case 9 :
                    pant_printArray(auxArray,CANT_PANTALLAS);
            break;

            case 10 :

            break;

            case 11 :
            break;

            default :
            printf ("\n Opcion no valida, ingrese una opcion valida.\n");
            break;
        }
    }
    return 0;
}
