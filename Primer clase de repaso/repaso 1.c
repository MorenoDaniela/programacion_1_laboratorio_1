#include <stdio.h>
#include <stdlib.h>

int pedirNumero (void);

int main()
{
    int numero;
    numero = pedirNumero ();
    printf ("El numero ingresado fue : %d",numero);
}

int pedirNumero ()
{
    int numero;
    printf ("Ingrese un numero entero entre 0 y 10:\n ");
    scanf ("%d",&numero);

    while (numero>10 || numero<0)
    {
        printf ("ERROR. Ingrese un numero entre 0 y 10: \n");
        scanf ("%d",&numero);
    }
    return numero;
}

//Funcion que pida numeros enteros entre 0 y 10.
//1.prototipo
//2.implementar
//3.usar en el main
