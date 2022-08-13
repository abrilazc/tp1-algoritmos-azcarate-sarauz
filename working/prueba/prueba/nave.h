#ifndef _NAVE_H_
#define _NAVE_H_

#include "figura.h"
#include "config.h"
#include <stdint.h>


struct nave;

typedef struct nave nave_t;

//setters
nave_t *nave_crear(figura_t **figura);
void nave_posicion_set(nave_t *nave, float posicion[2]);
void nave_velocidad_set(nave_t *nave, float velocidad[2]);
void nave_direccion_set(nave_t *nave, float direccion);
void chorro_set(nave_t *nave);
void chorro_clear(nave_t *nave);
void escudo_set(nave_t *nave);
void escudo_clear(nave_t *nave);
void respawnear_nave(nave_t *nave,float posicion[2]);
void vidas_incrementar(nave_t *nave);
bool vidas_decrementar(nave_t *nave); //devuelve false si se quedo sin vidas
void combustible_cargar(nave_t *nave);
bool combustible_usar(nave_t *nave);//devuelve false si se quedo sin combustible, anula la propulsion y el escudo.
void nave_rotar_horario(nave_t *nave);
void nave_rotar_antihorario(nave_t *nave);
void puntos_torreta(nave_t *nave);
void puntos_nivel(nave_t *nave, size_t puntos);

//getters
bool chorro_get(nave_t *nave);
bool escudo_get(nave_t *nave);
void nave_posicion_get(nave_t *nave, float posicion[2]);
void nave_velocidad_get(nave_t *nave, float velocidad[2]);
double direccion_get(nave_t *nave);
float combustible_get(nave_t *nave);
uint8_t vidas_get(nave_t *nave);

//destrucción

void nave_destruir(nave_t *nave);

#endif