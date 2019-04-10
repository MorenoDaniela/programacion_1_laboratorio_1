#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int main()
{

    char nombre [MAX];
    char buffer [MAX];
    int flag = 1;
    printf ("Ingrese su nombre: ");
    fgets (nombre, sizeof(nombre), stdin);//stdin representa el archivo de la consola donde estoy guardando
    int letras = strlen(nombre);//cree esra variable para decirle al strlen que en letra esta lo que escribio el usuario

    for (int i=0;i<letras-1;i++)
    {
        if(nombre[i] < 'A' || nombre[i] > 'z')
        {

            flag = 0;
            break;
        }
        //printf("%d", i);
    }

    if(flag)
    {
        printf ("\nEl nombre ingresado es: %s", nombre);
    }else
    {
        printf("\nError, caracteres invalidos.");
    }


    return 0;
}
    /*
    char nombre [7]={'H', 'O', 'L', 'A', '\0'};//esto es lo mismo
    char nombre2 [7]="HOLA";//que esto, esta es la que se usa.
    // ESTO NO!!!!!     nombre = "Juan";


    //paso destino, origen, y tamaño del destino
    strncpy(nombre, nombre2, sizeof(nombre)); //que tamaño tiene reservado en memoria ese array //sizeof(nombre)
    printf ("\n %s", nombre);
    fgets(nombre, sizeof(nombre), stdin);//la funcion fgets lee una cantidad de caracteres de un archivo, 1 donde dejo las cosas, el tamaño maximo,
    //NOOOOOO  scanf ("%s",nombre); SE USA FGETS
    printf ("\n %s", nombre);
    //strlen() //LEE DESDE UN ARCHIVO UNA CANTIDAD DE CARACTERES
    //strcnp() //LE PASO DOS STRING, ME DICE SI EL DE LA DERECHA ES MAS GRANDE QUE EL DE LA IZQ, IGUALES 0, o EL DE LA IZQ + GRANDE QUE EL DE LA DERECHA

    //PIDO UN NOMBRE, LO GUARDO EN BUFFER, (CREE DOS VARIABLES, NOMBRE Y BUFFER), VALIDAR CARACTERES, GUARDAR EN VARIABLE DESTINO, MOSTRAR POR PANTALLA.
    return 0;



int getString (char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int *string)
{
    char buffer [maximo];
    int retorno = 1;

    if (mensaje!=NULL && mensajeError!=NULL && string!=NULL &&maximo>=minimo && reintentos >=0)
    {
        do
        {
            fgets (string, sizeof (string), stdin);
            int letra = strlen (string);

            for (int i =0; i<letras-1; i++)
            {
                if (string[i] <'A' || string [i] > 'z')
                {
                    retorno = 0;
                    break;
                }

            }

            if (retorno)
            {
                printf ("%s",mensaje);
            }
            else
            {
                pritnf ("%s",mensajeError);
            }
        }while (reintentos >=0);
    }
    return retorno;
}
*/
