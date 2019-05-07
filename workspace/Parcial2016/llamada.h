#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    int idAsociado;
    int idAmbulancia;
    float tiempo;
    int motivo;//infarto 0 acv 1 gripe 2
    int estado;//estado pendiente 1 cumplido 0
    int idLlamada;
}Llamada;


#endif // LLAMADA_H_INCLUDED
