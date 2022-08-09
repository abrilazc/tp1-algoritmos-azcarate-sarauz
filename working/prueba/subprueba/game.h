#ifndef _GAME_H_
#define _GAME_H_


#include "figura.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
//#include "nave.h"
#include "nivel.h"
#define MAX_TIPOS 8


figura_t ***inicio(size_t cant_figuras[MAX_TIPOS]);


#endif