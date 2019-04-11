#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getString (char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* string);
int getNumber(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* resultado);
int isValidNumber(char *str);

int main()
{
    char ingreso[25];
    getString("Ingrese el string\n", "Error\n", 4, 25, 3, ingreso);
    printf("%s", ingreso);
    return 0;
}



int getNumber(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, int* resultado)
{
    int retorno = -1;
    char buffer[18];
    int bufferInt;

    if(mensaje != NULL && mensajeError!=NULL && minimo>maximo && reintentos>=0 && resultado!=NULL)
    {
        if(getString(mensaje,mensajeError,1,16,reintentos,buffer)==0)
        {
            if(isValidNumber(buffer))
            {
                bufferInt = atoi(buffer);
                if(bufferInt >= minimo && bufferInt <= maximo)
                {
                    *resultado = bufferInt;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

int isValidNumber(char *str)
{
    return 1;
}

int getString (char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char* string)
{
    char buffer [maximo];
    int bufferLongitud;
    int retorno = 1;

    if (mensaje!=NULL && mensajeError!=NULL && string!=NULL &&maximo>=minimo && reintentos >=0)
    {
        do
        {
            printf ("%s",mensaje);
            fgets (buffer, sizeof (buffer), stdin);
            bufferLongitud = strlen (buffer);
            buffer[bufferLongitud-1] = '\0';

            if (bufferLongitud<minimo)
            {
                printf ("%s",mensajeError);
            }
            else
            {
                retorno =0;
                strncpy(string, buffer, maximo);
                break;
            }
            reintentos--;
        }while (reintentos >=0);
    }
    return retorno;
}
