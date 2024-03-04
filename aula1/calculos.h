#ifndef _CALCULOS
#define _CALCULOS 1
#endif

extern double calcular_area(double a, double b, int n, double (*fptr)(double)); 

extern double calcular_area_monte_carlo(double a, double b, int n, double (*fptr)(double));
