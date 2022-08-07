#include <SDL2/SDL.h>
#include "nave.h"
#include "nivel.h"
#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include "fisica.h"
//pantallas
void pantalla_inicio(nave_t *nave,figura_t ***figura,nivel_t **niveles, SDL_Window *window, SDL_Renderer *renderer, SDL_Event event);
void cargar_nivel(nave_t *nave,nivel_t *nivel,figura_t ***figuras);

//estado nave
void estado_nave(nave_t *nave, float pos_g[2]);

//iteraciones inicio
void dibujar_planetas(float planeta[7][2], SDL_Renderer *renderer, figura_t ***figuras);
void iteracion_nave_inicio(nave_t *nave,float planeta[7][2]);
void iteraciones_colisiones_inicio(nave_t nave, float planeta[7][2]);

void texto(nave_t *nave);

void dibujar_letras(char *texto, float posicion[2]);