#ifndef _COLOR_H
#define _COLOR_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>


typedef uint8_t color_t;
//crea un color de dato especial a partir de 3 booleanos
color_t color_crear(bool r, bool g, bool b);
//A apartir de un color_t se obtienen valores aptos para RGB
//los valores son 0 o 255
void color_a_rgb(color_t c, uint8_t *r, uint8_t *g, uint8_t *b);

#endif