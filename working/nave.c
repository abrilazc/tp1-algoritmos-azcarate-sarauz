#include "nave.h"

typedef struct{
    figura_t **figura;
    float posicion[2];
    float velocidad[2];
    float direccion;
    size_t combustible;
    bool escudo;
    bool chorro;
    uint8_t vidas;
    size_t puntos;
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
    nave->vidas=3;
    return nave;
}

//setters

void chorro_set(nave_t *nave){
    nave->chorro=true;
}
void chorro_clear(nave_t *nave){
    nave->chorro=false;
}
void escudo_set(nave_t *nave){
    nave->escudo=true;
}
void escudo_clear(nave_t *nave){
    nave->escudo=false;
}
void velocidad_set(nave_t *nave, float velocidad[2]){
    *(nave->velocidad)=velocidad[0];
    *(nave->velocidad+1)=velocidad[1];
}
void vidas_incrementar(nave_t *nave){
    nave->vidas++;
}
bool vidas_decrementar(nave_t *nave){
    if(nave->vidas==0)
        return false;
        nave->vidas--;
}
void combustible_cargar(nave_t *nave){
    nave->combustible+=3000;
}
bool combustible_usar(nave_t *nave){
    if(nave->chorro)
        nave->combustible-=(JUEGO_COMBUSTIBLE_POT_X_SEG/JUEGO_FPS);    
    if(nave->escudo)
        nave->combustible-=(JUEGO_COMBUSTIBLE_ESC_X_SEG/JUEGO_FPS);
    if(nave->combustible<=0)
        return false;
    else
        return true;
}


//getters
bool chorro_get(nave_t *nave){
    return nave->chorro;
}
bool escudo_get(nave_t *nave){
    return nave->escudo;
}
double direccion_get(nave_t *nave){
    return nave->direccion;
}
void velocidad_get(nave_t *nave, float velocidad[2]){
    *(nave->velocidad)=velocidad[0];
    *(nave->velocidad+1)=velocidad[1];
}
uint8_t vidas_get(nave_t *nave){
    return nave->vidas;
    
}
size_t combustible_get(nave_t *nave){
    return  nave->combustible;
}