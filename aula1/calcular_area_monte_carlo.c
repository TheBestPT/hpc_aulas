#include "calculos.h"
#include <stdlib.h>

double calcular_area_monte_carlo(double a,
                      double b,
                      int n, //numero de pontos no calculo da soma
                      double (*fptr)(double)){
  double y = drand48();
  double x = drand48();

  int c = 0;
  for(int k = 0; k < n ; k++){
    y = drand48();
    x = drand48();

    double r = y*y + x*x;
    if(r <= 1.0){
      c += 1;
    }
  }

  return (double) c / (double) n;
}
