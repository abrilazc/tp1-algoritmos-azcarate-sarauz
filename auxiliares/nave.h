#ifndef _NAVE_H_
#define _NAVE_H_

#include "figura.h"

struct nave;

typedef struct nave nave_t;

//setters
nave_t *nave_crear();
void chorro_set(nave_t nave);
void chorro_clear(nave_t nave);
void escudo_set(nave_t nave);
void escudo_clear(nave_t nave);



//getters
bool chorro_get(nave_t nave);
bool escudo_get(nave_t nave);
void velocidad_get(nave_t nave);
double direccion_get(nave_t nave);


#endif