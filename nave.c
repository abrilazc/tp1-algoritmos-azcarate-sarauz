#include "nave.h"

#include <stdint.h>

typedef struct{
    polilinea_t **polilinea;
    float angulo;
    float v[2];
    uint16_t combustible;
    bool escudo;
    bool chorro;
}nave_t;