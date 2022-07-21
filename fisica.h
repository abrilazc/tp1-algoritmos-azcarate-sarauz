#ifndef _FISICA_H_
#define _FISICA_H_

#include <stddef.h>
#include <stdbool.h>


void colision_rebote(float pos[2], float v[2], size_t dim[2]); //llamada en caso de colisiones que causan un rebote

void acelerar(float v[2], float angulo, float a, float dt); //llamada para cambiar la velocidad de la nave

void gravedad(float v[2], bool planeta_infinito, float pos[2], float pos_g[2], float g, float dt); //llamada para cambiar la velocidad de la nave por efecto de la gravedad

void mover(float pos[2],float v[2],float dt); //llamada para mover un objeto

void rotar_nave(float pos[2], float *angulo, bool horario, float rotacion_paso); //llamada para cambiar el angulo de la nave

bool colision(const float polilinea[][2], size_t n, float pos[2], float radio); //llamada para verificar si la nave chocó, return true si chocó

#endif 
