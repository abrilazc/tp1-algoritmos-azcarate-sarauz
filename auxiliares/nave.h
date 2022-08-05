#ifndef _NAVE_H_
#define _NAVE_H_

#include "figura.h"

struct nave;

typedef struct nave nave_t;

//setters
nave_t *nave_crear();
void nave_pos_set(nave_t nave, float pos[2]);
void chorro_set(nave_t nave);
void chorro_clear(nave_t nave);
void escudo_set(nave_t nave);
void escudo_clear(nave_t nave);
void combustible_llenar(nave_t nave);
void combustible_usar(nave_t nave);

//getters
bool chorro_get(nave_t nave);
bool escudo_get(nave_t nave);
void posicion_get(nave_t, float pos[2]);
void velocidad_get(nave_t nave, float v[2]);
float direccion_get(nave_t nave);
uint16_t combustible_get(nave_t nave);


#endif
