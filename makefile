OBJS=calcular_area.o\
		 calcular_area_monte_carlo.o


all:pi
calcular_area.o: calcular_area.c calculos.h
calcular_area_monte_carlo.o: calcular_area_monte_carlo.c calculos.h
pi: pi.c $(OBJS) calculos.h
	gcc pi.c -o pi $(OBJS) -lm
