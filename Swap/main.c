#include <stdio.h>
#include <stdlib.h>

void sortArrayInt (int* array, int limit)
{
int i;
int flagSwap;
int auxiliar;

do
{
    for (i=0; i<limit-1; i++)
    {
        flagSwap=0;
        if (array [i] > array [i+1])
        {
            auxiliar = array [i];
            array [i] = array [i+1];
            array [i+1] = auxiliar;
            flagSwap = 1;
        }
    }

}while (flagSwap)

}
