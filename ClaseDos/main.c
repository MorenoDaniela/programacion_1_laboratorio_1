#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5
#include <limits.h>

int sacarPromedio (void);
int calcularPromedio (int valorAcumulado, int CANTIDAD, float *promedio);
int maximoMinimo (void);
int minimo = INT_MAX;
int maximo = INT_MIN;

int main()
{
    sacarPromedio ();
    //maximoMinimo ();
}

int sacarPromedio (void)
{
    int numero;
    int acumulador=0;
    float promedio;
    int contador;

    for (contador=0;contador<CANTIDAD;contador++)
    {
        printf ("Ingrese un numero: ");
        scanf("%d",&numero);
        acumulador=acumulador+numero;

        maximoMinimo (valor, &maximo, &minimo);

    }
    //promedio = (float)acumulador/CANTIDAD_DE_NUMEROS_PEDIDOS; //pongo float para que de con coma el promedio
    if (calcularPromedio(acumulador,CANTIDAD,&promedio)== 0)
    {
        printf ("El promedio es: %.2f",promedio); //.2 para que me de con DOS decimales
    }
        else
        {
            printf ("ERROR.");
        }
    printf ("El maximo es: %d",maximo);
    printf ("El minimo es: %d",minimo);

    return 0;
}


int calcularPromedio (int valorAcumulado, int cantidad, float *promedio)
{
    int retorno = -1;
    if (cantidad > 0 && promedio != NULL)
    {
        *promedio = (float)valorAcumulado/cantidad;
        retorno = 0;
    }
    return retorno;
}

int maximoMinimo (int valor, int *maximo, int *minimo)
{
    if (valor>*minimo)
    {
        *minimo = valor;
    }

    if (valor>*maximo)
    {
        *maximo = valor;
    }

    return 0;
}




//hacer una funcion que calcule el maximo y el minimo
