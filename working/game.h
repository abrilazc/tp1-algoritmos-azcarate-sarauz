#ifndef _GAME_H_
#define _GAME_H_


#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdint.h>

#include "game.h"
//#include "nave.h"
#include "figura.h"

struct nave;

typedef struct nave nave_t;

figura_t ***inicio(size_t *cant_figuras);

void cargar_nivel(size_t nivel);

void render_elemento(figura_t); //llamada para renderizar la nave del jugador en tal posicion con tal angulo

void render_entorno();


#endif