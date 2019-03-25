#include <stdio.h>
#include <stdlib.h>

void claseUnoRepaso (void);

/** \brief
 * pide un numero entre 1 y 10
 * \param no tiene parametro de entrada
 * \param
 * \return
 *es el numero que debe retornar
 */
int pedirNumero (void);

/** \brief
 * saca el promedio con los datos que tiene como parametros
 * \param suma int
 * \param cantidad int
 * \return
 * el promedio retornado
 */

float sacarPromedio (int suma, int cantidad);
/** \brief
  *retorna 1 si el alumno aprobo la materia
  *retorna 0 si el alumno no aprobo la materia
  * \param notainima int
  *nota minima para aprobar la materia
  * \param nota int
  *nota que se saco el alumno
  * \return int
  *0 para no aprobo
  *1 para aprobado
  */
 int sacarAprobacion(int notaMinima, int nota);
 /** \brief
  * ingrese la nota de 5 alumnos (entre 0 y 10)
  * informar cuantos aprobaron
  * el promedio de notas de todos
  * el promedio de notas de los que no aprobaron
  * \param
  * \param
  * \return int
  *
  */





int main()
{
    claseUnoRepaso();

    /*
    int numero;
    float promedio;
    int estaAprobado;
    numero = pedirNumero ();
    printf ("El numero ingresado fue : %d",numero);
    promedio = sacarPromedio(100,5);
    printf ("El promedio fue: %f",promedio);
        estaAprobado=sacarAprobacion(6,numero);
        if (estaAprobado==1)
        {
            printf ("Aprobo.");
        }
        else
        {
            printf ("No aprobo.");
        }
        return 0;
        */
}

void claseUnoRepaso()
{
    int notaIngresada;
    int sumaTotal;
    int sumaNoAprobados;
    int contadorAprobados;
    int contadorNoAprobados;
    float promedioTotal;
    float promedioNoAprobados;

    sumaTotal=0;
    sumaNoAprobados=0;
    contadorAprobados=0;
    contadorNoAprobados=0;

    for (int i=0;i<5;i++)
    {
        notaIngresada=pedirNumero();
        sumaTotal=sumaTotal+notaIngresada;
        if(sacarAprobacion(6,notaIngresada))
        {
            contadorAprobados++;
        }
        else
        {
            contadorNoAprobados++;
            sumaNoAprobados=sumaNoAprobados+notaIngresada;
        }
    }

    promedioTotal=sacarPromedio(sumaTotal,i);
    promedioNoAprobados=sacarPromedio(sumaNoAprobados,contadorNoAprobados);
    printf ("Cuantos aprobaron %d",contadorAprobados);
    printf ("Promedio de notas de todos ",promedioTotal);
    printf ("El promedio de notas de los que no aprobaron: ",promedioNoAprobados);
}

int pedirNumero ()
{
    int numero;
    printf ("Ingrese un numero entero entre 0 y 10:\n ");
    scanf ("%d",&numero);

    while (numero>10 || numero<0)
    {
        printf ("ERROR. Ingrese un numero entre 0 y 10: \n");
        scanf ("%d",&numero);
    }
    return numero;
}

float sacarPromedio (int suma, int cantidad)
{
    float retorno;
    retorno = (float)suma/cantidad;
    return retorno;
}

int sacarAprobacion(int notaMinima, int nota)
{
    int retorno;
    if (nota>= notaMinima)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

//Funcion sacar promedio
//1.prototipo
//2.implementar
//3.usarla en el main o en otra funcion
