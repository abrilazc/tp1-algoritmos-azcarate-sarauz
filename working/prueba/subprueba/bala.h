#ifndef _BALA_H_
#define _BALA_H_

#include "lista.h"

#define MAX_BAL_ENEM 10
#define MAX_BAL_PROP 10
#define MAX_BAL_TIEM 10
#define MAX_BAL_VELO 20

struct bala;
typedef struct bala bala_t;

bala_t *crear_bala(float posicion[2],float direccion);
bool disparo(lista_t *lista,float posicion[2],float direccion);

bool destruir_disparos(lista_t lista);
float get_tiempo(bala_t bala);
void restar_tiempo(bala_t bala,float tiempo);