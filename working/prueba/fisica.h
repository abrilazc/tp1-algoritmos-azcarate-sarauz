#ifndef _FISICA_H_
#define _FISICA_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "polilinea.h"
#include "nave.h"

#define RADIONAVE 1//o cualquier valor
#define DT 1/(JUEGO_FPS*1.00)



void colision_rebote(nave_t *nave); //llamada en caso de colisiones que causan un rebote

void computar_posicion(nave_t *nave, float pos_g[2]);

void trasladar(float pos[2],float v[2]); //llamada para mover un objeto

bool colision(float polilinea[][2], size_t n, float pos[2], float radio); //llamada para verificar si la nave chocó, return true si chocó

void rotar_punto(float punto[2], float pos[2], float angulo);

#endif 
