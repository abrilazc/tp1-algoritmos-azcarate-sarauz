
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdint.h>

#include "polilinea.h"

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



void render_nave(float pos[2], float angulo){
    
}