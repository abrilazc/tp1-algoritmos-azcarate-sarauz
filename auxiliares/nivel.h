#ifndef _NIVEL_H_
#define _NIVEL_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "figura.h"

#define TIEMPO_B 5
//#include "rompibles.h" el que tiene torretas, tnaques y reactores

struct nivel;
typedef struct nivel nivel_t;

nivel_t *crear_nivel(char *nombre);
nivel_t **crear_niveles(char *nombre);

tanque_t *disponer_tanques(char *nombre);
torreta_t *disponer_torretas(char *nombre);
reactor_t *disponer_reactor(char *nombre);

typedef enum{NIVEL1NE,NIVEL1SE,NIVEL1R,NIVEL1NW,NIVEL1SW}planeta_nombre;//o que se yo

//setear cantidad
const size_t cantidad_tanques(char *nombre);
const size_t cantidad_torretas(char *nombre);
const bool cantidad_reactores(char *nombre);
/*
//setar posicion
const float*[3] posicion_tanques(char *nombre);
const float*[3] posicion_torretas(char *nombre);
const float*[3] posicion_reactores(char *nombre);

//Destruir nivel
void destruir_nivel(nivel_t nivel);
void destruir_niveles(nivel_t **niveles, size_t cantidad_niveles);
*/
#endif 