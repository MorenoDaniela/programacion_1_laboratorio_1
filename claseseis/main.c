#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char nombre [10];
    char buffer [10];
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



int nombreValido (char* array, int* limite, int* retorno,)
{

}
*/
