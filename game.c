
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdint.h>

#include "figura.h"
#include "nave.h"


typedef enum{
    INICIO,
    NIVEL1NE,
    NIVEL1SE,
    NIVEL1R,
    NIVEL1NW,
    NIVEL1SW,
}niveles_t;

void render_figura(float pos[2]){
    float nave[][2]={{8, 0}, {-1, 6}, {-4, 4}, {-4, 2}, {-2, 0}, {-4, -2}, {-4, -4}, {-1, -6}, {8, 0}};
    
}