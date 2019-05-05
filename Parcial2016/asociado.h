#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

typedef struct
{
    int idAsociado;
    char dni[50];
    char nombre[50];
    char apellido[50];
    int edad;
    int isEmpty;//estado habilitado 0 no habilitado 1
}Asociado;

int asociado_initAsociado(Asociado* asociados, int limite);
int asociado_findFree(Asociado* asociados, int limite);
//static int generarId(void);
int asociado_nuevo(char* msj, char* msjError, Asociado* asociados,int lugarVacio,int reintentos, int limite);
int asociado_print(Asociado* asociados, int limite);
int asociado_baja(char* msj, char* msjError,Asociado* asociados,int reintentos,int limite);
int findById (char* msj,char* msjError, Asociado* socios, int* id, int limite);
int modificarDatos(char* msj, char* msjError,Asociado* socios,int reintentos, int limite);


#endif // ASOCIADO_H_INCLUDED
