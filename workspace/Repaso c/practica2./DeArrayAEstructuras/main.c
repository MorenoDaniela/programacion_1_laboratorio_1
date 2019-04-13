#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 3
typedef struct{
    float precios ;
    char codigos[7];
}Producto;

int getPrecio(char *mensaje,float *elPrecio);
int getCodigo(char *mensaje,char *codigo);





/** \brief
 * vamos aadministrar los productos de un comercio
 * cod 6 caracteres
 *  precio

 * \return int
 *
 *
 */
int main()
{

    float precios[TAMANIO] ;
    char codigos[TAMANIO][7];
    //char codigos[7][TAMANIO];
    Producto unProducto;
    int i;
    int j;
    while(getPrecio("ingrese precio  , por fa!!!",&unProducto.precios)==0){
        printf("error ...");
       }


        while(getCodigo("ingrese Codigo  , por fa!!!",unProducto.codigos)==0){
        printf("error ...");
       }
    printf("codigo:%s precio: %f \n",unProducto.codigos,unProducto.precios);

     for(i=0;i<TAMANIO;i++)
    {
       while(getPrecio("ingrese precio  , por fa!!!",&precios[i])==0){
        printf("error ...");
       }


        while(getCodigo("ingrese Codigo  , por fa!!!",codigos[i])==0){
        printf("error ...");
       }

    }

    for(i=0;i<TAMANIO;i++)
    {
        printf("codigo:%s precio: %f \n",codigos[i],precios[i]);
    }

    for(i=0;i<TAMANIO;i++)
    {
        for(j=0;j<TAMANIO;j++)
        {
            if(precios[i]<precios[j])
            {
                int aux=precios[i];
                precios[i]=precios[j];
                precios[j]=aux;

                char auxCo[7];
                strcpy(auxCo,codigos[i]);
                strcpy(codigos[i],codigos[j]);
                strcpy(codigos[j],auxCo);

            }
        }
    }
    for(i=0;i<TAMANIO;i++)
    {
        printf("codigo:%s precio: %f \n",codigos[i],precios[i]);
    }
    printf("De array a estruturas \n");
    return 0;
}
int getCodigo(char *mensaje,char *codigo)
{
    char ingreso[50];
    int retorno=0;
    printf(mensaje);
    scanf("%s",ingreso);
    if( strlen(ingreso)==6)
    {
        strcpy(codigo,ingreso);
        retorno=1;
    }
    return retorno;

}
int getPrecio(char *mensaje,float *elPrecio)
{
    char ingreso[50];
    float auxPrecio;
    int retorno=0;
    printf(mensaje);
    scanf("%s",ingreso);
    auxPrecio=atof(ingreso);
    if(auxPrecio>0)
    {
      *elPrecio  = auxPrecio;
      retorno= 1;
    }
    return retorno;

}
