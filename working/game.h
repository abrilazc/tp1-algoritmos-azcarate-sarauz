#ifndef _GAME_H_
#define _GAME_H_


#include "figura.h"

struct nave;

typedef struct nave nave_t;

figura_t ***inicio(void);

void cargar_nivel(size_t nivel);

void render_elemento(figura_t); //llamada para renderizar la nave del jugador en tal posicion con tal angulo

void render_entorno();


#endif