#ifndef _FISICA_H_
#define _FISICA_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "polilinea.h"

#define RADIONAVE 1//o cualquier valor
#define DT 1/JUEGO_FPS


void colision_rebote(float pos[2], float v[2], size_t dim[2]); //llamada en caso de colisiones que causan un rebote

void acelerar(float v[2], float angulo); //llamada para cambiar la velocidad de la nave

//void gravedad(float v[2], bool planeta_infinito, float pos[2], float pos_g[2]); //llamada para cambiar la velocidad de la nave por efecto de la gravedad

void computar_velocidad(float velocidad[2], float aceleracion[2]);

void trasladar(float pos[2],float v[2]); //llamada para mover un objeto

//chequear esta funcion
//void rotar_nave(polilinea_t *polilinea, double *angulo, bool horario); //llamada para cambiar el angulo de la nave

bool colision(float polilinea[][2], size_t n, float pos[2], float radio); //llamada para verificar si la nave chocó, return true si chocó

#endif 
