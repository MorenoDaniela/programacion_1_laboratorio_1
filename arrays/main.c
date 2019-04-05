#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDAD_ALUMNOS 55

int main()
{
    int aEdades [CANTIDAD_ALUMNOS];


    getArrayInt("Ingrese edad", "Edad invalida", 120, 0, 5, aEdades);




/*
    int getInt (char* msg, char* msgErr, int maximo, int minimo, int reintentos, int* resultado)

    int getArrayInt (char* msg, char* msgErr, int maximo, int minimo, int reintentos, int* ArrayResultado, int limite)
    //llama a la funcion de arriba, en la funcion de arriba se declara un buffer y se le pasa a esta y recien cuando se que no es un error scaneo

    int obtenerNum (char* msg, char* msgError, int maximo, int minimo, int reintentos, int* resultado)
    {
        int retorno=-1;
        int numero;

        if (resultado!=NULL &&msg!=NULL &&msgError!=NULL && minimo<=maximo && reintentos<0)
        {

        }
    }
}

/*int* pEdades;//puntero a edades
    int bufferEdad;
    int aEdades [CANTIDAD_ALUMNOS];//no poner un numero adentro de [] mejor definir arriba con define

    aEdades [100] =22;//le digo que en la posicion 100 guarde el num 22
    bufferEdad = aEdades [400];//en el buffer se guarda lo que hay en la posicion 400 por ejemp
    pEdades = &aEdades[88];// es lo mismo que pEdades = aEdades;
    //el nombre de un array indica el indice la primer posicion de un elemento

    pEdades = aEdades;
    pEdades [88] = 11;//esta opcion es lo mismo que *(pEdades+88) =11; pero es peor
    bufferEdad = pEdades[188];//esto es lo mismo que la linea 20
    *(pEdades+88) = 11;//en el lugar donde estaba antes +88 posiciones ahi quiero escribir
    bufferEdad = *(pEdades+188);//esta linea es lo mismo que la linea 18
    //tipo de array y tipo de puntero TIENEN QUE SER IGUALES EN EL TIPO (int, char, float)
    */
