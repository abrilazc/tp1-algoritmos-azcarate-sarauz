#ifndef _GAME_H_
#define _GAME_H_


#include "figura.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include "nave.h"
#include "nivel.h"
#include "fisica.h"

#define MAX_TIPOS 8


figura_t ***inicio(size_t cant_figuras[MAX_TIPOS]);

void registrar_teclas(nave_t *nave, SDL_Event event, bool *held_down);

void clear_renderer(SDL_Renderer *renderer);

void render_nave(nave_t *nave, SDL_Renderer *renderer, figura_t ***figuras, size_t f);

bool camara_inf(nave_t *nave, bool *inicio);

void muerte(nave_t *nave);

void calcular_escala_inf(float posicion_nave_y, float *escalada);

void calcular_centro_inf(const float escala,const float posicion_nave_x, float *centro);

<<<<<<< HEAD
void min_max(figura_t **figuras, planeta_nombre planeta_actual,float min[2],float max[2]);

void calcular_escala(figura_t **figuras, planeta_nombre planeta_actual,float *escala, float *centro);
=======
void calcular_escala(figura_t **figuras, planeta_nombre *planeta_actual,float *escala, float *centro,float min_max[2]);
>>>>>>> ced9728a7d8953de9bc8aabd90cf54f23b18275c

#endif