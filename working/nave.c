//#include "nave.h"
#include <stdint.h>
#include "figura.h"
typedef struct{
    figura_t **figura;
    float posicion[2];
    float v[2];
    float direccion;
    uint16_t combustible;
    bool escudo;
    bool chorro;
}nave_t;

nave_t *nave_crear(){
    nave_t *nave=malloc(sizeof(nave_t));
    if(nave==NULL)
        return NULL;
    nave->figura=malloc(sizeof(figura_t *)*2);
    if(nave->figura==NULL){
        free (nave);
        return NULL;
    }
    nave->escudo=false;
    nave->chorro=false;
    nave->direccion=PI/2;
    *(nave->posicion)=0;
    *(nave->posicion+1)=0;
    nave->combustible=JUEGO_COMBUSTIBLE_INICIAL;
    return nave;
}

