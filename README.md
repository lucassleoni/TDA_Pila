TDA Pila (Vector Dinámico)

La implementación del TDA Pila incluído en 'TDA Pila (Lucas Leoni).zip' posee los siguientes programas:
    1) 'pila.h' es la biblioteca que incluye las firmas de las funciones primitivas para el funcionamiento de la pila.
    2) 'pila.c' es el programa con la implementación de la pila.
    3) 'makefile' es el programa que facilita el acceso a las líneas de compilación y ejecución de la pila, las pruebas y Valgrind.
    4) 'Consigna' es la consigna del trabajo pŕactico.


Funciones del TDA Pila

Aclaración: todas las funciones utilizadas verifican (previo a ser ejecutadas) que no haya ningún error,
            (ver 'Funciones Propias > Verificación de errores generales').

1) Creación de la pila ---> pila_t* pila_crear();
     Crea la estructra 'pila_t pila'.
     Devuelve un puntero a la estructura 'pila_t pila' inicializada y reserva la memeoria necesaria para su almacenamiento en el Heap.
     Devuelve NULL en caso de haber habido un error al crear la pila.

2) Apilar elementos ---> int pila_apilar(pila_t* pila, void* elemento);
     Apila el elemento recibido, redimensionando la pila en caso de que esta se encuentre llena antes de apilar
     (ver 'Compilación y Convenciones > Criterio de Redimensionamiento').
     Devuelve '0' si la operación tuvo éxito y '-1' si falló.

3) Desapilar elementos ---> int pila_desapilar(pila_t* pila);
     Desapila el elemento en la última posición de la pila y verifica si es necesario redimensionar
     (ver 'Compilación y Convenciones > Criterio de Redimensionamiento').
     Devuelve '0' si la operación tuvo éxito y '-1' si falló.

4) Pila vacía ---> bool pila_vacia(pila_t* pila);
     Determina si la pila está vacía (es decir, si tiene 0 elementos).
     Devuelve 'true' si la pila está vacía o es nula, y 'false' en cualquier otro caso.

5) Cantidad de elementos ---> int pila_cantidad(pila_t* pila);
     Devuelve la cantidad de elementos presentes en la pila.
     Devuelve '0' si la pila es nula o está vacía.

6) Tope de la pila ---> void* pila_tope(pila_t* pila);
     Devuelve el último elemento de la pila (el elemento situado en la posición tope, sea cual sea su tipo de dato).
     Devuelve NULL si la pila es nula o está vacía.

7) Destrucción de la pila ---> void pila_destruir(pila_t* pila);
     Destruye la estructura 'pila_t pila' (liberando toda la memoria previamente ocupada/reservada por/para ella en el Heap).


Funciones Propias (para modularizar la implementacíon de la pila)

1) Verificación de errores generales ---> bool hay_error(pila_t* pila);
     Devuelve 'true' si:
        1.1) La estructura 'pila_t pila' es nula.
        1.2) El vector de elementos es nulo.
        1.3) El tope del vector es menor a 0.
        1.4) El tope del vector es mayor al tamaño de la pila.

2) Verificación de pila llena ---> bool pila_llena(pila_t* pila);
     Determina si la pila está llena.
     Devuelve 'true' si la pila está llena (es decir, si tiene tantos elementos como espacios en ella).
     Si la pila no existe devolverá 'false'.

3) Redimensionamiento de la pila ---> int pila_redimensionar(pila_t* pila, int nuevo_tamanio);
     Redimensiona el tamaño de la pila según el tamaño/proporción recibido.
     Devuelve '0' si pudo redimensionar o '-1' en caso contrario.


Pruebas (Testing)

En la carpeta se incluye una serie de pruebas que testean casos bordes, intermedios y normales del funcionamiento de la pila.
Todas las funciones que requieren que la estructura 'pila_t pila' no sea nula, verifican previamente si esta fue creada con éxito y,
de no ser así, imprimen por pantalla que la prueba no pudo ser llevada a cabo.
Si una prueba es ejecutada, destruye la estructura al finalizar, liberando la memoria utilizada para la misma.
Las pruebas (funciones void) implementadas son las siguientes:

1) ejecutar_caso_feliz();
     Es la prueba provista por la cátedra, cuyo funcionamiento es apilar 6 elementos y, por cada vez que apila, imprimir por pantalla
     la cantidad de elementos que la pila posee (para verificar si efectivamente fueron todos apilados). Luego, imprime el elemento
     en la posición tope y lo despila, mostrando el nuevo tamaño de la pila (siguiendo este algoritmo hasta que el tamaño sea 0),
     para finalmente destruir la estructura y liberar la memoria utilizada.

     Esta prueba testea:
        1.1) La creación de la estructura 'pila_t pila'.
        1.2) El apilamiento/desapilamiento de varios elementos.
        1.3) Si las funciones 'pila_cantidad' y 'pila_tope' funcionan correctamente.
        1.4) La destrucción de la estructura 'pila_t pila' (verificada al correr el comando 'make valgrind').
    
2) desapilar_pila_vacia_deberia_devolver_NULL();
     Intenta desapilar un elemento de la pila vacía e imprime por pantalla si efectivamente la función 'pila_desapilar' devuelve NULL.

3) llenar_pila_y_volver_a_apilar_deberia_redimensionar();
     Llena la pila hasta que tenga tantos elementos como espacios disponibles (es decir, hasta que el tope sea igual al tamaño).
     Luego, apila un elemento más y verifica (imprimiendo por pantalla) si la pila fue redimensionada según la convención establecida
     (ver 'Compilación y Convenciones > Criterio de Redimensionamiento').

4) desapilar_hasta_la_mitad_de_su_tamanio_deberia_redimensionar();
     Apila 11 elementos (uno más que la capacidad inicial) para redimensionar la pila. Luego, desapila el último (tal que la cantidad
     de elementos sea igual a la mitad de su tamaño), teniendo que redimensionar y verifica (imprimiendo por pantalla) si la
     redimensión se corresponde con la convención establecida (ver 'Compilación y Convenciones > Criterio de Redimensionamiento').

5) si_la_pila_es_nula_deberia_fallar_apilar_y_desapilar();
     Se inicializa un puntero 'pila_t* pila' en NULL (un pila nula) y se verifica si apilar y desapilar devuelven ambos
     el código error establecido (-1), imprimiendo el resultado de la prueba por pantalla.

6) ver_tope_de_pila_nula_deberia_devolver_NULL();
     Se inicializa un puntero 'pila_t* pila' en NULL (un pila nula) y se verifica si ver el tope de la pila devuelve NULL,
     imprimiendo el resultado de la prueba por pantalla.

7) si_la_pila_esta_vacia_entonces_pila_cantidad_deberia_devolver_cero();
     Se crea una estructura 'pila_t* pila' a la que no se le apila ningún elemento, para verificar (imprimiendo por pantalla el resultado
     de la prueba) si la función 'pila_cantidad' devuelve '0'.

8) si_lleno_y_vacio_la_pila_el_tamanio_no_deberia_ser_inferior_al_inicial();
     Se crea una estructura 'pila_t* pila', que es llenada y luego vaciada, para verificar (imprimiendo por pantalla el resultado de la prueba)
     si su tamaño es igual al tamaño inicial.


Compilación y Convenciones

1) Tamaño de la Pila
     Inicialmente, la pila se creará con un tamaño mínimo de 10 espacios libres y totalmente vacía.
     El mismo nunca será inferior al inicial (incluso si se la vacía por completo).

2) Criterio de Redimensionamiento
     2.1) Si la pila está llena y se intenta apilar un elemento más, se duplicará su tamaño y luego se apilará el elemento.
     2.2) Si se desapilan elementos hasta llegar a la mitad de su tamaño, el mismo se reducirá a la cantidad de elementos presentes en la pila.
          Caso borde: Al redimensionar, la pila nunca quedará con un tamaño inferior al inicial.

3) Makefile
   La carpeta cuenta con un programa 'makefile' que posee los siguientes comandos:
     3.1) 'make compile' compilará el programa 'pila.c' junto con las pruebas que testean su funcionamiento, ejecutando la línea de compilación:
              gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 pila.c minipruebas_pila_vd.c -o pila_vd -g

     3.2) 'make pila' compilará el programa con la línea mencionada en el punto (3.1) y luego ejecutará las pruebas (incluídas en la carpeta) con la línea:
              ./pila_vd

     3.2) 'make valgrind' ejecutrá Valgrind (mostrando los resultados de las pruebas por pantalla) con la línea:
              valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pila_vd
