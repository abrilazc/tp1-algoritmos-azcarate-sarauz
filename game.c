
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdint.h>

#include "polilinea.h"

#define NAVE {{8, 0}, {-1, 6}, {-4, 4}, {-4, 2}, {-2, 0}, {-4, -2}, {-4, -4}, {-1, -6}, {8, 0}}

typedef enum{
    INICIO,
    NIVEL1NE,
    NIVEL1SE,
    NIVEL1R,
    NIVEL1NW,
    NIVEL1SW,
}niveles_t;
typedef enum{
    ICONO,
    NIVEL,
    NAVE_CHORRO,
    ESTRELLA,
    BASE,
    COMBUSTIBLE,
    TORRETA,
    REACTOR,
}tipo_elementos_t;

struct elemento {
    char nombre[20];
    tipo_elementos_t tipo;
    bool infinito;
    size_t n_polilineas;
    polilinea_t *polilineas;
};

void render_nave( float pos[2], float angulo){
    float nave[][2]={{8, 0}, {-1, 6}, {-4, 4}, {-4, 2}, {-2, 0}, {-4, -2}, {-4, -4}, {-1, -6}, {8, 0}};
    
}