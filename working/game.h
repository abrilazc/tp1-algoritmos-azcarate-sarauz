#ifndef _GAME_H_
#define _GAME_H_


#include "figura.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include "nave.h"
#include "nivel.h"
#define MAX_TIPOS 8


figura_t ***inicio(size_t cant_figuras[MAX_TIPOS]);

void registrar_teclas(nave_t *nave, SDL_Event event, bool *held_down);

void clear_renderer(SDL_Renderer *renderer);

void render_nave(nave_t *nave, SDL_Renderer *renderer, figura_t ***figuras, size_t f);

void muerte(nave_t *nave);

void calcular_escala_inf(float posicion_nave_y, float *escala);

void calcular_centro_inf(const float escala,const float posicion_nave_x, float *centro);

void calcular_escala(figura_t **figuras, planeta_nombre *planeta_actual,float *escala, float *centro);

#endif