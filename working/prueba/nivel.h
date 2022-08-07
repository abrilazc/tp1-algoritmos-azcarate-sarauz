#ifndef _NIVEL_H_
#define _NIVEL_H_

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "figura.h"


struct vector;
struct objeto;
struct reactor;
struct nivel;

typedef struct vector vector_t;
typedef struct objeto objeto_t;
typedef struct reactor reactor_t;
typedef struct nivel nivel_t;

typedef enum{NIVEL1NE,NIVEL1SE,NIVEL1R,NIVEL1NW,NIVEL1SW}planeta_nombre;

//Crear
//niveles
nivel_t *crear_nivel(figura_t **figura,planeta_nombre planeta);
nivel_t **crear_niveles(figura_t **figura, size_t cantidad);
//listas y reactor
lista_t *lista_combustible(planeta_nombre planeta);
lista_t *lista_torreta(planeta_nombre planeta);
reactor_t *crear_reactor(planeta_nombre planeta);

//Admin
objeto_t *crear_objeto(vector_t *referencia, size_t fila);
void armar_lista_combustible(lista_t *lista, planeta_nombre planeta);
void armar_lista_torreta(lista_t *lista, planeta_nombre planeta);

//Cantidades
const size_t cantidad_combustible(planeta_nombre nombre);
const size_t cantidad_torretas(planeta_nombre nombre);
const bool cantidad_reactores(planeta_nombre nombre);

//Nombres
const char* nombre_asignado(planeta_nombre nombre);

//getter interno
//lista_largo
void objeto_a_posicion(objeto_t *objeto,float *posicion);
void objeto_a_direccion(objeto_t *objeto,float *direccion);

//getter externo
bool get_bool_nivel(reactor_t *reactor);

//DESTRUIR
//lista_destruir
void destruir_cosa(objeto_t *objeto);
void destruir_bien(void *objeto);
void destruir_reactor(reactor_t *reactor);
//nivel
void destruir_nivel(nivel_t *nivel);
void destruir_niveles(nivel_t **niveles, size_t cantidad_niveles);

#endif 