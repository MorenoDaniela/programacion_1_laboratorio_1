#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 15
int getMail (char* msg, char* msgError, int minimo, int maximo, int reintentos, char*resultado);
isValidMail(char* cadena);
int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);


int main()
{
    char auxMail [CANTIDAD];
    getMail("Ingrese su mail: ", "Error, caracteres invalidos.", 5,15,3,auxMail);
    return 0;
}

int getMail (char* msg, char* msgError, int minimo, int maximo, int reintentos, char*resultado)
{
   int retorno = -1;
   char bufferMail[4096];
   if (msg !=NULL && msgError !=NULL && minimo<maximo && reintentos >=0 && resultado !=NULL)
   {
       if (!getString (msg, msgError,minimo,maximo,reintentos,bufferMail))
       {
           if (isValidMail(bufferMail))
           {
               strncpy (resultado, bufferMail, maximo);
               retorno=0;
           }
       }
   }
   return retorno;
}

isValidMail(char* cadena)
{
    int retorno = 1;
    int i;
    for (i=0; cadena[i]!= '\0'; i++)
    {
        if ((cadena[i]>'Z' || cadena [i] < 'A') && (cadena[i]>'z' || cadena[i]<'a') && cadena[i]=='@' && cadena[i]=='-' && cadena[i]=='.' && cadena[i]=='_' && (cadena[i]>=0 || cadena[i]<=9))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}
