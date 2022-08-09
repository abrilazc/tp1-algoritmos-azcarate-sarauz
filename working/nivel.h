#ifndef _NIVEL_H_
#define _NIVEL_H_

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "figura.h"
//#include "config.h"


struct vector;
struct objeto;
struct reactor;
struct nivel;

typedef struct vector vector_t;
typedef struct objeto objeto_t;
typedef struct reactor reactor_t;
typedef struct nivel nivel_t;


typedef enum{NIVEL1NE,NIVEL1SE,NIVEL1R,NIVEL1NW,NIVEL1SW}planeta_nombre;

//CREARS
//niveles
nivel_t *crear_nivel(figura_t **figura,planeta_nombre planeta);
nivel_t **crear_niveles(figura_t **figura, size_t cantidad);
////combustible, torreta y reactor
lista_t *lista_combustible(planeta_nombre planeta);
lista_t *lista_torreta(planeta_nombre planeta);
reactor_t *crear_reactor(planeta_nombre planeta);
//bala_t *crear_bala(float posicion[2],float direccion);
//objetos
objeto_t *crear_objeto(vector_t *referencia, size_t fila);
void armar_lista_combustible(lista_t *lista, planeta_nombre planeta);
void armar_lista_torreta(lista_t *lista, planeta_nombre planeta);

//CARGAS
//cargar nivel
nivel_t *cargar_datos_nivel(nivel_t **niveles,planeta_nombre nombre);

//TABLAS DE BUSQUEDA Y ARREGLOS
//Cantidades
const size_t cantidad_combustible(planeta_nombre nombre);
const size_t cantidad_torretas(planeta_nombre nombre);
const bool cantidad_reactores(planeta_nombre nombre);
//Nombres
const char* nombre_asignado(planeta_nombre nombre);
//getter externo
bool get_infinito(nivel_t *nivel);
//reactor_t *get_reactor_nivel(nivel_t *nivel)
size_t get_cantidad_torretas(nivel_t *nivel);
size_t get_cantidad_combustible(nivel_t *nivel);
lista_t *get_lista_torreta(nivel_t *nivel);
lista_t *get_lista_combustible(nivel_t *nivel);
figura_t *get_figura_nivel(nivel_t *nivel);
void objeto_a_posicion(objeto_t *objeto,float *posicion);
void objeto_a_direccion(objeto_t *objeto,float *direccion);
//reactor
bool check_reactor_nivel(nivel_t *nivel);
void get_posicion_reactor(nivel_t *nivel, float *posicion);
float get_direccion_reactor(nivel_t *nivel);
float get_tiempo(nivel_t *nivel);

//DESTRUIR
//lista_destruir
void destruir_cosa(objeto_t *objeto);
void destruir_bien(void *objeto);
void destruir_reactor(reactor_t *reactor);
//nivel
void destruir_nivel(nivel_t *nivel);
void destruir_niveles(nivel_t **niveles, size_t cantidad_niveles);

#endif 