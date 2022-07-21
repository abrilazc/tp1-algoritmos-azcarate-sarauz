
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "polilineas.h"

typedef struct {
    char figura_nombre[20];
    bool infinito;
    size_t n_polilineas;
    polilinea_t *polilineas;
}   figura_t;



void render_nave(float pos[2], float angulo){
    
}