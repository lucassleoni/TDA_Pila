TDA Pila (Vector Dinámico)

Pruebas (testing):
1) 

Compilación y convenciones sobre la implementación de la pila:
1) Inicialmente, la pila se creará con 10 esapcios libres y totalmente vacía.

2) El criterio de redimensionamiento utilizado en este caso es:
     2.1) Si la pila está llena y se intenta apilar un elemento más, se duplicará su tamaño y luego se apilará el elemento.
     2.2) Si se desapilan elementos hasta llegar a la mitad de su tamaño, este se reducirá a la cantidad de elementos presentes en la pila.

3) La carpeta cuenta con un programa 'makefile' que posee los siguientes comandos:
     3.1) 'make compile' ejecutará la línea de compilación (compilará el programa pila.c junto con las pruebas que testean su funcionamiento):
           gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 pila.c minipruebas_pila_vd.c -o pila_vd -g
     3.2) 'make pila' compilará el programa con la línea mencionada en el punto (3.1) y ejecutará las pruebas incluídas en la carpeta.
     3.2) 'make valgrind' ejecutrá la línea (mostrando los resultados de las pruebas por pantalla):
           valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pila_vd
