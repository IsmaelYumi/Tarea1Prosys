all: limpiar compilar ejecutable
limpiar:
	rm -f *.o
compilar: Tarea.c Funciones.c
	gcc -c Tarea.c
	gcc -c Funciones.c
ejecutable: Tarea.o Funciones.o
	gcc -o Tarea Tarea.o Funciones.o

