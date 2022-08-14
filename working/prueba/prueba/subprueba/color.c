#include "color.h"
#define MASK_R 0x4
#define MASK_G 0x2
#define MASK_B 0x1

color_t color_crear(bool r, bool g, bool b){
    return r<<2|g<<1|b;
}

void color_a_rgb(color_t c, uint8_t *r, uint8_t *g, uint8_t *b){
    *r=255*((c&MASK_R)>>2);
    *g=255*((c&MASK_G)>>1);
    *b=255*(c&MASK_B);
}