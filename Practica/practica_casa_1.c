#include <stdio.h>
#include <stdlib.h>

//el define es para definir la cantidad de veces que va a correr el bucle en for
#define CANTIDAD 3
int main()
{
    int numero;
    float promedio; //uso flotante porque el promedio puede dar con decimal
    int contador;


    for (contador=0;contador<CANTIDAD;contador++)
    {
        printf ("Ingrese un numero: ");
        scanf ("%d",&numero);

        promedio = promedio + numero;


    }

    promedio = promedio/CANTIDAD;
    printf("El promedio es: %f",promedio); //vuelvo a usar para guardar %f porque es float el promedio
    return 0;
}

/*

int main ()
{
    int numero1;
    int numero2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf ("%d",&numero1);

    printf ("Ingrese segundo numero: ");
    scanf ("%d",&numero2);

    resultado = numero1+numero2;
    printf ("El resultado es:,resultado ");

    return 0;


}
*/
