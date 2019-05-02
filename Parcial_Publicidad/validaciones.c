#ifndef VALIDACIONES_C_INCLUDED
#define VALIDACIONES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int isValidInt(int number, int minimum, int maximum)
{
    if(number >= minimum && number <= maximum)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int isValidFloat(float number, float minimum, float maximum)
{
    if(number >= minimum && number <= maximum)
    {
        return 1;
    }
    return 0;
}

int isValidChar(char letter, char minimum, char maximum)
{
    if(letter>=minimum && letter <= maximum)
    {
        return 1;
    }
    return 0;
}

int isValidName (char* cadena)
{
    int retorno = 1;
    int i;
    for( i=0 ; cadena[i] != '\0' ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

#endif // VALIDACIONES_C_INCLUDED
