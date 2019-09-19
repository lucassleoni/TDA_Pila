#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pila.h"

#define FALLO -1
#define EXITO 0
#define PILA_VACIA 0
#define REDIMENSION 2

// Pre C.: ---
// Post C.: Muestra por pantalla los distintos tamaños de la pila mientras agrega elementos y los imprime.
void ejecutar_caso_feliz(){
    pila_t* pila = pila_crear();

    char elemento1 = 'A';
    pila_apilar(pila, &elemento1);
    printf("Tamanio pila: %i\n", pila_cantidad(pila));
    
    char elemento2 = 'B';
    pila_apilar(pila, &elemento2);
    
    char elemento3 = 'C';
    pila_apilar(pila, &elemento3);
    printf("Tamanio pila: %i\n", pila_cantidad(pila));
    
    char elemento4 = 'D';
    pila_apilar(pila, &elemento4);
    
    char elemento5 = 'E';
    pila_apilar(pila, &elemento5);
    printf("Tamanio pila: %i\n", pila_cantidad(pila));

    char elemento6 = 'F';
    pila_apilar(pila, &elemento6);
    
    printf("%c\n", *(char*)pila_tope(pila));
    pila_desapilar(pila);
    
    printf("Tamanio pila: %i\n", pila_cantidad(pila));
    printf("%c\n", *(char*)pila_tope(pila));
    pila_desapilar(pila);
    
    printf("Tamanio pila: %i\n", pila_cantidad(pila));
    printf("%c\n", *(char*)pila_tope(pila));
    pila_desapilar(pila);
    
    printf("Tamanio pila: %i\n", pila_cantidad(pila));
    printf("%c\n", *(char*)pila_tope(pila));
    pila_desapilar(pila);
    
    printf("Tamanio pila: %i\n", pila_cantidad(pila));
    printf("%c\n", *(char*)pila_tope(pila));
    pila_desapilar(pila);
    
    printf("Tamanio pila: %i\n", pila_cantidad(pila));
    printf("%c\n", *(char*)pila_tope(pila));
    pila_desapilar(pila);
    
    printf("Tamanio pila: %i\n", pila_cantidad(pila));

    pila_destruir(pila);
}

// Pre C.: ---
// Post C.: Verifica que la pila esté vacía e imprime por pantalla el resultado de la prueba al intentar desapilar un elemento.
void desapilar_pila_vacia_deberia_devolver_NULL(){
    pila_t* pila = pila_crear();
    printf("Prueba #1: Desapilar pila vacía devuelve ERROR.\n");
    
    if(pila_vacia(pila)){
        if(pila_desapilar(pila) == FALLO){
           printf("\tEXITO: Prueba superada correctamente. \n");
        }
        else{
            printf("\tPrueba FALLIDA :(\n");
        }
    }

    pila_destruir(pila);
}
// Pre C.: ---
// Post C.: Apila elementos hasta que la pila no tenga espacios libres, sin redimensionar.
void llenar_pila(pila_t* pila, char elemento){
    if(!pila){
        return;
    }
    while(pila_cantidad(pila) < (pila->tamanio)){
        pila_apilar(pila, &elemento);
    }
}

// Pre C.: ---
// Post C.: Verifica que la rendimensión al ampliar la pila se ejecute correctamente,
//          comparando el tamaño antes y después de redimensionar, e imprime el resultado de la prueba por pantalla.
void llenar_pila_y_volver_a_apilar_deberia_redimensionar(){
    pila_t* pila = pila_crear();

    printf("\nPrueba #2: Verificar si el tamaño de la pila se duplica al apilar sobre la pila llena.\n");
    char elemento = 'A';
    int tamanio_comparacion = pila->tamanio;

    llenar_pila(pila, elemento);
    pila_apilar(pila, &elemento);
    printf("\t%s: ampliar vector duplica su tamaño.\n", (pila->tamanio) == tamanio_comparacion * 2?"EXITO":"FALLO");

    pila_destruir(pila);
}

// Pre C.: ---
// Post C.: Verifica que la rendimensión al reducir la pila se ejecute correctamente,
//          comparando el tamaño antes y después de redimensionar, e imprime el resultado de la prueba por pantalla.
void desapilar_hasta_la_mitad_de_tamanio_deberia_redimensionar(){
    pila_t* pila = pila_crear();

    printf("\nPrueba #3: Verificar si el tamaño de la pila se divide en 2 al desapilar hasta la mitad de su tamaño.\n");
    char elemento = 'A';

    llenar_pila(pila, elemento);
    pila_apilar(pila, &elemento);
    
    int tamanio_comparacion = pila->tamanio;
    pila_desapilar(pila);
    printf("\t%s: reducir el vector divide su tamaño a la mitad.\n", (pila->tamanio) == tamanio_comparacion / 2?"EXITO":"FALLO");

    pila_destruir(pila);
}

// Pre C.: ---
// Post C.: Imprime por pantalla si el resultado de la prueba al apilar/desapilar en una pila nula obtuve la respuesta esperada.
void si_la_pila_es_nula_deberia_fallar_apilar_y_desapilar(){
    pila_t* pila = NULL;
    printf("\nPrueba #4: Verificar si hay error al intentar apilar o desapilar en una pila nula.\n");
    
    char elemento = 'A';
    printf("\t%s: apilar y desapilar sobre una pila nula %s el código de error establecido (-1).\n",
        ((pila_apilar(pila, &elemento) == FALLO) && (pila_desapilar(pila) == FALLO))?"EXITO":"FALLO",
        ((pila_apilar(pila, &elemento) == FALLO) && (pila_desapilar(pila) == FALLO))?"devuelve":"no devuelve");
}
// Pre C.: ---
// Post C.: Imprime por pantalla el resultado de intentar ver el tope de una pila nula (que debería ser NULL).
void ver_tope_de_pila_nula_deberia_devolver_NULL(){
    pila_t* pila = NULL;

    printf("\nPrueba #5: Verificar si ver el tope de una pila nula devuelve NULL.\n");
    printf("\t%s: ver tope de pila nula %s NULL\n",
        (pila_tope(pila) == NULL?"EXITO":"FALLO"),
        (pila_tope(pila) == NULL?"devuelve":"no devuelve"));
}

// Pre C.: ---
// Post C.: Verifica que la cantidad de la pila sea 0 al estar vacía e imprime el resultado de la prueba por pantalla.
void si_la_pila_esta_vacia_entonces_pila_cantidad_deberia_devolver_cero(){
    pila_t* pila = pila_crear();

    printf("\nPrueba #6: Si la pila esta vacía, la función pila_cantidad devuelve 0.\n");
    printf("\t%s: al estar vacía la pila, la función pila_cantidad %s 0.\n",
        ((pila_cantidad(pila) == PILA_VACIA)?"EXITO":"FALLO"),
        ((pila_cantidad(pila) == PILA_VACIA)?"devuelve":"no devuelve"));

    pila_destruir(pila);
}

int main(){
    system("clear");

    //ejecutar_caso_feliz();
    desapilar_pila_vacia_deberia_devolver_NULL();
    llenar_pila_y_volver_a_apilar_deberia_redimensionar();
    desapilar_hasta_la_mitad_de_tamanio_deberia_redimensionar();
    si_la_pila_es_nula_deberia_fallar_apilar_y_desapilar();
    ver_tope_de_pila_nula_deberia_devolver_NULL();
    si_la_pila_esta_vacia_entonces_pila_cantidad_deberia_devolver_cero();

    return 0;
}