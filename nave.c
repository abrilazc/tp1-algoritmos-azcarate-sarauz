#include "nave.h"

#include <stdint.h>

typedef struct{
    polilinea_t **polilinea;
    double direccion;
    double v[2];
    uint16_t combustible;
    bool escudo;
    bool chorro;
}nave_t;

nave_t *nave_crear(){
    nave_t *nave=malloc(sizeof(nave_t));
    if(nave==NULL)
        return NULL;
    nave->polilinea=polilinea_fig();
}

