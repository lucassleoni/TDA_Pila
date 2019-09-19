#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pila.h"

#define FALLO -1
#define EXITO 0
#define PILA_VACIA 0
#define REDIMENSION 2
#define TAMANIO_INICIAL 10

// Pre C.: Se debe recibir un puntero al struct pila_t pila.
// Post C.: Devuelve 'true' si hay algún error que invalide la pila (es decir si no existe la pila, si el tope es negativo o si 'tope > tamaño').
bool hay_error(pila_t* pila){
	return ((!pila) || (!(pila->elementos)) || ((pila->tope) < PILA_VACIA) || ((pila->tope) > (pila->tamanio)));
}

// Pre C.: Se debe recibir un puntero al struct pila_t pila.
// Post C.: Devuelve 'true' si la pila está llena (si tiene tantos elementos como espacios en ella).
bool pila_llena(pila_t* pila){
	return ((pila->tope) == (pila->tamanio));
}

/* 
 * Determina si la pila está vacia.
 * Devuelve true si está vacía, false en caso contrario.
 * Si la pila no existe devolverá true.
 */
bool pila_vacia(pila_t* pila){
	if(!pila){
		return true;
	}
	return ((pila->tope) == PILA_VACIA);
}

/* 
 * Crea una pila, reservando la memoria necesearia para almacenar la
 * estructura.
 * Devuelve un puntero a la estructura pila_t creada o NULL si no pudo
 * crearla.
 */
pila_t* pila_crear(){
	pila_t* pila = malloc(sizeof(pila_t));
	if(!pila){
		return NULL;
	}

	pila->elementos = malloc(sizeof(void*) * TAMANIO_INICIAL);
	if(!(pila->elementos)){
		free(pila);
		return NULL;
	}

	pila->tope = PILA_VACIA;
	pila->tamanio = TAMANIO_INICIAL;
	return pila;
}

// Pre C.: Debe recibir la pila y el tamaño numérico (o proporción) al que se quiere redimensionar el vector de elementos.
// Post C.: Devuelve 0 si pudo redimensionar o -1 en caso contrario.
int pila_redimensionar(pila_t* pila, int nuevo_tamanio){
	if(hay_error(pila)){
		return FALLO;
	}
	
	void* elementos_aux = realloc(pila->elementos, sizeof(void*) * (long unsigned int) nuevo_tamanio);
	if(!elementos_aux){
		return FALLO;
	}
	pila->elementos = elementos_aux;
	pila->tamanio = nuevo_tamanio;

	return EXITO;
}

/* 
 * Apila un elemento.
 * Devuelve 0 si pudo o -1 en caso contrario.
 */
int pila_apilar(pila_t* pila, void* elemento){
	if(hay_error(pila)){
		return FALLO;
	}

	if(pila_llena(pila)){
		if(pila_redimensionar(pila, (pila->tamanio) * REDIMENSION) == FALLO){
			return FALLO;
		}
	}

	if((pila->tope) < (pila->tamanio)){
		pila->elementos[(pila->tope)] = elemento;
		(pila->tope)++;
	}

	return EXITO;
}

/* 
 * Desapila un elemento.
 * Devuelve 0 si pudo desapilar o -1 si no pudo.
 */
int pila_desapilar(pila_t* pila){
	if((hay_error(pila)) || (pila_vacia(pila))){
		return FALLO;
	}


	(pila->tope)--;

	if((pila->tope) <= ((pila->tamanio) / 2)){
		if(pila_redimensionar(pila, (pila->tamanio) / REDIMENSION) == FALLO){
			return FALLO;
		}
	}
	return EXITO;
}

/* 
 * Devuelve la cantidad de elementos almacenados en la pila.
 * Si la pila no existe devolverá 0.
 */
int pila_cantidad(pila_t* pila){
	if(hay_error(pila)){
		return PILA_VACIA;
	}
	return (pila->tope);
}

/*
 * Devuelve el elemento en el tope de la pila o NULL
 * en caso de estar vacía.
 * Si la pila no existe devolverá NULL.
 */
void* pila_tope(pila_t* pila){
	if((hay_error(pila)) || (pila_vacia(pila))){
		return NULL;
	}
	return (pila->elementos[(pila->tope)-1]);
}

/* 
 * Destruye la pila liberando la memoria reservada para la misma.
 */
void pila_destruir(pila_t* pila){
	if(hay_error(pila)){
		return;
	}
	free(pila->elementos);
	free(pila);
}