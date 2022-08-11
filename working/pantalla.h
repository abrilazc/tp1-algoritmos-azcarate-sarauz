#ifndef _PANTALLA_H_
#define _PANTALLA_H_

#include <SDL2/SDL.h>
//#include "nave.h"
//#include "nivel.h"
#include "game.h"
#include <stdbool.h>
#include <stdio.h>
//#include "fisica.h"
//#include "bala.h"
#include "lista.h"
#include "caracteres.h"


//pantallas
void cargar_pantalla_inicio(nave_t *nave,nivel_t **niveles,figura_t ***figuras, planeta_nombre planeta_actual,bool spawn);
bool pantalla_inicio_mostrar(nave_t *nave,figura_t ***figuras, nivel_t **niveles, SDL_Renderer *renderer, float *f, planeta_nombre *planeta_actual);
void cargar_nivel(nave_t *nave,nivel_t **niveles, planeta_nombre planeta_actual);
void pantalla_nivel(nave_t *nave, figura_t ***figuras,nivel_t **niveles, SDL_Renderer *renderer, bool *goto_inicio, planeta_nombre *planeta_actual, float *f, float *centro);
//estado nave
void estado_nave(nave_t *nave, float pos_g[2]);

//iteraciones inicio
void dibujar_planetas(float planeta[7][2], SDL_Renderer *renderer, figura_t ***figuras);
void iteracion_nave_inicio(nave_t *nave,float planeta[7][2]);
void iteraciones_colisiones_inicio(nave_t nave, float planeta[7][2]);

//se revisa que si algun elemento de una lista se interseca con la nave
bool interseccion_lista_nave(nave_t *nave,size_t *cantidad, lista_t *lista,figura_t **figuras,char *nombre);
//dibuja en en SDL todos los elementos de una lista
void dibujar_lista(figura_t **figuras, lista_t *lista,char *nombre,SDL_Renderer *renderer, float escala);
//revisa si hay interseccion entre los elementos de 2 listas o cuantas hay si es una municion a torreta
size_t interseccion_lista_lista(lista_t *lista, lista_t *lista_2,size_t *cantidad_2);
//revisa si la nave toca alguna polilinea,concretamente la superficie de un planeta
bool interseccion_nave_polilinea(nave_t *nave,figura_t **figura,planeta_nombre nombre);

void texto(nave_t *nave, figura_t ***figuras, SDL_Renderer *renderer);

void dibujar_letras(char *texto, float posicion[2]);



#endif