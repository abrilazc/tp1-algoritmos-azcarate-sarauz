#ifndef _POLILINEA_H_
#define _POLILINEA_H_

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <SDL2/SDL.h>
#include "color.h"
#include "config.h"
struct polilinea;
typedef struct polilinea polilinea_t;

//Creacion polilinea
polilinea_t *polilinea_crear_vacia(size_t n,color_t color);
polilinea_t *polilinea_crear(const float puntos[][2], size_t n,color_t color);

//Getters
size_t polilinea_cantidad_puntos(const polilinea_t *polilinea);
bool polilinea_obtener_punto(const polilinea_t *polilinea, size_t pos, float *x, float *y);
color_t polilinea_color(const polilinea_t *polilinea);

//Setters
bool polilinea_setear_punto(polilinea_t *polilinea, size_t pos, float x, float y);
bool polilinea_setear_color(polilinea_t *polilinea, color_t color);
void polilinea_trasladar(polilinea_t *polilinea, double traslacion[2]);
void polilinea_rotar(polilinea_t *polilinea, double angulo);
bool dibujar_polilinea(SDL_Renderer *renderer,polilinea_t *polilinea, float posicion[2], float escala);

//Memoria
polilinea_t *polilinea_clonar(const polilinea_t *polilinea);

//Destruccion polilinea
void polilinea_destruir(polilinea_t *polilinea);

#endif