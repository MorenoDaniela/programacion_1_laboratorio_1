#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[256];
    float precio;
    char tipo[5];
}Pantalla;

int pant_initArray (Pantalla* arrayPantalla, int limite);
int pant_findEmpty (Pantalla* arrayPantalla, int limite);
int pant_printArray(Pantalla* arrayPantalla, int limite);
int pant_alta(char* msjError, Pantalla* arrayPantalla,int reintentos, int limite,int id);
int pant_baja(char* msj, char* msjError, Pantalla* arrayPantalla, int limite);
int pant_findId (char *msj, char* msjError, Pantalla* arrayPantalla, int* id, int limite);
int pant_modificar(char*msjError, Pantalla* arrayPantalla, int limite);

#endif // PANTALLA_H_INCLUDED
