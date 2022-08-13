#ifndef CARACTERES_H
#define CARACTERES_H

#include <SDL2/SDL.h>

#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

#include "polilinea.h"

#define ESP_LET 6


typedef enum letras{
   	A, B, C, D, E, F, g, H, I, J, K, L, M, N, O, P, Q, R,
   	S, T, U, V, W, X, Y, Z, CERO, UNO, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, OCHO, NUEVE, DERECHA,
   	IZQUIERDA, ARRIBA, ABAJO, ESPACIO,
}letras_t;

typedef struct caracter cater_t;

//pasa una palabra a dibujo de polilinea, apto solo para caracteres de la A a la Z, espacio y numero decimales
void palabra_a_polilinea(SDL_Renderer *renderer,char *palabra, float posicion[2],  bool r, bool ge, bool b, float escala);
//pasa un numero int a dibujo de polilinea, apto solo para numeros que necesiten menos de 10 caracteres
void numero_a_polilinea(int numero,SDL_Renderer *renderer, float posicion[2],  bool r, bool ge, bool b, float escala);

extern const float caracter_a[7][2];
extern const float caracter_b[12][2];
extern const float caracter_c[4][2];
extern const float caracter_d[7][2];
extern const float caracter_e[7][2];
extern const float caracter_f[6][2];
extern const float caracter_g[7][2];
extern const float caracter_h[6][2];
extern const float caracter_i[6][2];
extern const float caracter_j[4][2];
extern const float caracter_k[6][2];
extern const float caracter_l[3][2];
extern const float caracter_m[5][2];
extern const float caracter_n[4][2];
extern const float caracter_o[5][2];
extern const float caracter_p[5][2];
extern const float caracter_q[9][2];
extern const float caracter_r[7][2];
extern const float caracter_s[6][2];
extern const float caracter_t[4][2];
extern const float caracter_u[4][2];
extern const float caracter_v[3][2];
extern const float caracter_w[5][2];
extern const float caracter_x[5][2];
extern const float caracter_y[5][2];
extern const float caracter_z[4][2];

extern const float caracter_0[5][2];
extern const float caracter_1[2][2];
extern const float caracter_2[6][2];
extern const float caracter_3[7][2];
extern const float caracter_4[5][2];
extern const float caracter_5[6][2];
extern const float caracter_6[5][2];
extern const float caracter_7[3][2];
extern const float caracter_8[7][2];
extern const float caracter_9[5][2];

extern const float caracter_derecha[5][2];
extern const float caracter_izquierda[5][2];
extern const float caracter_arriba[5][2];
extern const float caracter_abajo[5][2];

extern const float caracter_espacio[1][2];

//void dibujar_cadena(char * cadena, SDL_Renderer * renderer, float posicion_x, float posicion_y, float escala,bool r, bool g, bool b);

#endif
