#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 3
#include <limits.h>

int sacarPromedio (void);
int calcularPromedio (int valorAcumulado, int cantidad, float *promedio);
int maximoMinimo (int valor, int *maximo, int *minimo);


int main()
{
    sacarPromedio ();
    //maximoMinimo (int valor, int *maximo, int *minimo);
    return 0;
}

int sacarPromedio ()
{
    int numero;
    int acumulador=0;
    float promedio;
    int contador;
    int minimo = INT_MAX;
    int maximo = INT_MIN;

    for (contador=0;contador<CANTIDAD;contador++)
    {
        printf ("Ingrese un numero: ");
        scanf("%d",&numero);
        acumulador=acumulador+numero;

        if (maximoMinimo(numero, &maximo, &minimo));
        {
            printf ("Error.");
            break;
        }

    }
    //promedio = (float)acumulador/CANTIDAD; //pongo float para que de con coma el promedio
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
    int retorno = -1;
    if (*maximo != NULL && *minimo != NULL)
    {
        if (valor>*minimo)
        {
            *minimo = valor;
        }

        if (valor>*maximo)
        {
            *maximo = valor;
        }
        retorno = 0;
    }
    return retorno;
}




//hacer una funcion que calcule el maximo y el minimo
