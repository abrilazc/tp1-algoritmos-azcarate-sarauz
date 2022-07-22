#ifndef _GAME_H_
#define _GAME_H_

#include <stdint.h>

typedef struct elemento elemento_t;

void cargar_nivel(size_t nivel);

void render_nave(elemento_t nave); //llamada para renderizar la nave del jugador en tal posicion con tal angulo

void render_entorno();


#endif