#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

typedef struct
{
    int idPublicidad;
    int isEmpty;
    char cuit[20];
    int dias;
    char archivo[250];
    int idPantalla;
}Publicidad;

int pub_alta (char* msjError,Pantalla* arrayPantalla, Publicidad* arrayPublicidad,int reintentos, int limite, int id);
int pub_printArray(Publicidad* arrayPublicidad,Pantalla* arrayPantalla, int limite);
int pub_findEmpty (Publicidad* arrayPublicidad, int limite);
int pub_initArray (Publicidad* arrayPublicidad, int limite);

#endif // PUBLICIDAD_H_INCLUDED
