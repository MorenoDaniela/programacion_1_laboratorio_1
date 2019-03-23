#include <stdio.h>
#include <stdlib.h>

int pedirNumero (void);
float sacarPromedio (int suma, int cantidad);

int main()
{
    int numero;
    float promedio;
    numero = pedirNumero ();
    printf ("El numero ingresado fue : %d",numero);
    promedio = sacarPromedio(94,5);
    printf ("El promedio fue: %f",promedio);
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

float sacarPromedio (int suma, int cantidad)
{
    float retorno;
    retorno = (float)suma/cantidad;
    return retorno;
}



//Funcion sacar promedio
//float ... (int suma, int cantidad)
