#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED

int ingresarNumero(char *mensaje, float *unOperador)
{
    float numero;
    printf ("%s",mensaje);
    scanf ("%f",&numero);
    *unOperador = numero;
    return 0;
}

int sumar (float numeroUnoSuma, float numeroDosSuma, int retorno1, int retorno2)
{
    int retornoSuma = -1;
    float suma;

    if (retorno1==-1 || retorno2==-1)
    {
        printf ("\nError, no se ingreso un operando."\n);
    }
    else
    {
        suma = numeroUnoSuma + numeroDosSuma;
        printf ("\nEl resultado de la suma es: %.2f\n",suma);
        return 0;
    }
    return retornoSuma;
}

int restar(float numeroUnoResta, float numeroDosResta, int retorno1, int retorno2)
{
    int retornoResta = -1;
    float resta;

    if (retorno1==-1 || retorno2==-1)
    {
        printf ("\nError, no se ingreso un operando.\n");
    }
    else
    {
        resta = numeroUnoResta - numeroDosResta;
        printf ("\nEl resultado de la resta es: %.2f\n",resta);
        return 0;
    }
    return retornoResta;
}

int multiplicar(float numeroUnoMultiplicador, float numeroDosMultiplicador, int retorno1, int retorno2)
{
    int retornoMultiplicacion = -1;
    float multiplicacion;
    if (retorno1==-1 || retorno2==-1)
    {
        printf ("\nError, no se ingreso un operando.\n");
    }
    else
    {
        multiplicacion = numeroUnoMultiplicador * numeroDosMultiplicador;
        printf ("\nEl resultado de la multiplicacion es: %.2f\n",multiplicacion);
        return 0;
    }
    return retornoMultiplicacion;
}
int dividir(float numeroUnoDividendo, float numeroDosDivisor, int retorno1, int retorno2)
{
    int retornoDivision = -1;
    float division;
    if (retorno1==-1 || retorno2==-1)
    {
        printf ("\nError, no se ingreso un operando.\n");
    }
    else
    {
        if (numeroDosDivisor == 0)
        {
            printf ("\nError, no se puede dividir por cero.\n");
        }
        else
        {
            division = numeroUnoDividendo / numeroDosDivisor;
            printf ("\nEl resultado de la division es: %.2f\n",division);
            retornoDivision = 0;
        }
    }
    return retornoDivision;
}

int factorial (int numeroFactorial, int retorno1)
{
    int retornoFactorial=-1;
    int resultadoFactorial=1;

    if (retorno1 ==-1)
    {
        printf ("\n Error, no se ingreso el operando.\n");
    }
    else
        {
            if (numeroFactorial<0)
            {
                printf ("\nNo se puede calcular el factorial de un numero negativo.\n");
                return retornoFactorial;
            }
            else
            {
                for (int contador=1;contador<=numeroFactorial;contador++)
                {
                    resultadoFactorial=resultadoFactorial*contador;
                }
                printf ("\n El resultado del factorial de %.2d es : %.2d\n",numeroFactorial,resultadoFactorial);

            }
        }

    return 0;
}


#endif // FUNCIONES_C_INCLUDED
