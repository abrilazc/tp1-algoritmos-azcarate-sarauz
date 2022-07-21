#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdbool.h>

#define LONG_NOM 20
#define INF_MASK 0x01
#define TIPO_MASK 0x07
#define CANTIDAD_PUNTOS_MASK 0x3ff
#define MASK_G 0x2
#define MASK_B 0x1


typedef enum{ICONO,NIVEL,SPRITE,OTRO}figura_tipo_t;
const char* figura_tipo_a_cadena(figura_tipo_t figura);
bool leer_encabezado_figura(FILE *f, char nombre[], figura_tipo_t *tipo, bool *infinito, size_t *cantidad_polilineas);
polilinea_t *leer_polilinea(FILE *f);

#endif