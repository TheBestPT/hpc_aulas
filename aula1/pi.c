#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculos.h"

double f(double x){
  return sqrt(1.0 - x *x);
}

int main(int argc, char *argv[]){
	printf("%s\n", "Calcular PI");
	double a = 0.0;
  double b = 1.0;
  double n = 1000;
  double y = calcular_area(a, b, n,&f);
	printf("Pi: %g\n", 4.0 * y);
  printf("Pi MC: %g\n", 4.0 * calcular_area_monte_carlo(a, b, n, &f));
  printf("Test make");
	return EXIT_SUCCESS;
}
