CC = gcc
CFLAGS = -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

compile: pila.c minipruebas_pila_vd.c
	$(CC) $(CFLAGS) pila.c minipruebas_pila_vd.c -o pila_vd -g 

pila: compile
	clear
	./pila_vd

valgrind: compile
	clear
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pila_vd