#include "calculos.h"

double calcular_area(double a, double b, int n, //numero de pontos no calculo da soma
                     double (*fptr)(double)){
  double dx = (double) (b-a) / (double) n;
  double soma = 0.0;
  double x = a;
  for(int k = 0; k < n; k++){
    soma += fptr(x) * dx;
    x += dx;
  }
  return soma;
}



