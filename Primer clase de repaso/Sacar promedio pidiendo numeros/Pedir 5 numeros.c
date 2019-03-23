#include <stdio.h>
#include <stdlib.h>

/** \brief
  *
  * \param
  * \param
  *ingrese la nota de 5 alumnos (entre 0 y 10)
  *informar cuantos aprobaron
  *el promedio de todas las notas
  *el promedio de los que no aprobaron
  * \return int

  */
  void ingresarNotas (void)
  int pedirNumero (void);
  float sacarPromedio (int suma, int cantidad);
  int sacarAprobacion (int notaMinima,int nota);

  int main ()
  {
      ingresarNotas();
  }

  void ingresarNotas ()
  {
      int notaIngresada;
      int sumaTotal;
      int sumaNoAprobados;
      int contadorAprobados;
      int contadorNoaprobados;
      float promedioTotal;
      float promedioNoAprobados;


      sumaTotal=0;
      sumaNoAprobados;
      contadorAprobados=0;
      contadorNoaprobados=0;

      for (int i=0;i<5;i++)
      {
          notaIngresada = pedirNumero();
          sumaTotal=sumaTotal+notaIngresada;
          if (sacarAprobacion(6,notaIngresada)
              {
                  contadorAprobados++;
              }
              else
              {
                  contadorNoAprobados++;
                  sumaNoAprobados = sumaNoAprobados+notaIngresada;
              }
      }
      promedioTotal= sacarPromedio(sumaTotal,i);
      promedioNoAprobados= sacarPromedio(sumaNoAprobados,contadorNoAprobados);
      printf ("Cuantos aprobaron %d",contadorAprobados);
      printf ("Cuantos no aprobaron %d",contadorNoAprobados);
      prnttf ("El promedio de todas las notas es &f",promedioTotal);
      printf ("El promedio de de los que no aprobaron es &f",promedioNoAprobados);
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

float sacarPromedio (int suma, int cantidad)
{
    float retorno;
    retorno = (float)suma/cantidad;
    return retorno;
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
