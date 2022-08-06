#ifndef _NAVE_H_
#define _NAVE_H_

#include "figura.h"
#include "config.h"
#include <stdint.h>

struct nave;

typedef struct nave nave_t;

//setters
nave_t *nave_crear();
void chorro_set(nave_t *nave);
void chorro_clear(nave_t *nave);
void escudo_set(nave_t *nave);
void escudo_clear(nave_t *nave);
void velocidad_set(nave_t *nave, float velocidad[2]);
void respawnear_nave();
void vidas_incrementar(nave_t *nave);
bool vidas_decrementar(nave_t *nave); //devuelve false si se quedo sin vidas
void combustible_cargar(nave_t *nave);
bool combustible_usar(nave_t *nave);//devuelve false si se quedo sin combustible, anula la propulsion y el escudo.

//getters
bool chorro_get(nave_t *nave);
bool escudo_get(nave_t *nave);
double direccion_get(nave_t *nave);
void velocidad_get(nave_t *nave, float velocidad[2]);
size_t combustible_get(nave_t *nave);
uint8_t vidas_get(nave_t *nave);

#endif