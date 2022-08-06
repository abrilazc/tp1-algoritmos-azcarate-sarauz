#ifndef _NAVE_H_
#define _NAVE_H_

#include "figura.h"

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

//getters
bool chorro_get(nave_t *nave);
bool escudo_get(nave_t *nave);
double direccion_get(nave_t *nave);
void velocidad_get(nave_t *nave, float velocidad[2]);
uint8_t vidas_get(nave_t *nave);

#endif