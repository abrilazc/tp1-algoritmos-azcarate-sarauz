#include "nave.h"
struct nave{
    figura_t **figura;
    float posicion[2];
    float velocidad[2];
    float direccion;
    float combustible;
    bool escudo;
    bool chorro;
    uint8_t vidas;
    size_t puntos;
};

static void nave_rotar(nave_t *nave, float angulo){
    for(size_t i=0;i<4;i++){
        figura_rotar(*(nave->figura+i),angulo);
    }
}

nave_t *nave_crear(figura_t **figura){
    nave_t *nave=malloc(sizeof(nave_t));
    if(nave==NULL)
        return NULL;
    nave->figura=figura;
    nave->escudo=false;
    nave->chorro=false;
    nave->direccion=NAVE_ANGULO_INICIAL;
    nave_rotar(nave, nave->direccion);
    *(nave->posicion)=0;
    *(nave->posicion+1)=0;
    *(nave->velocidad)=0;
    *(nave->velocidad+1)=0;
    nave->combustible=JUEGO_COMBUSTIBLE_INICIAL;
    nave->vidas=3;
    return nave;
}

//setters
void nave_posicion_set(nave_t *nave, float posicion[2]){
    nave->posicion[0]=posicion[0];
    nave->posicion[1]=posicion[1];
}

void nave_velocidad_set(nave_t *nave, float velocidad[2]){
    *(nave->velocidad)=velocidad[0];
    *(nave->velocidad+1)=velocidad[1];
}

void nave_direccion_set(nave_t *nave, float direccion){
    (nave->direccion)=direccion;
}

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

void vidas_incrementar(nave_t *nave){
    nave->vidas++;
}
bool vidas_decrementar(nave_t *nave){
    if(nave->vidas==0)
        return false;
    nave->vidas--;
    return true;
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
void nave_rotar_horario(nave_t *nave){
    (nave->direccion)-=NAVE_ROTACION_PASO;
    printf("\nhorario direccion: %.2f",nave->direccion);
    nave_rotar(nave,-(NAVE_ROTACION_PASO));
}
void nave_rotar_antihorario(nave_t *nave){
    (nave->direccion)+=NAVE_ROTACION_PASO;
    printf("\nantihorario direccion: %.2f",nave->direccion);
    nave_rotar(nave,(NAVE_ROTACION_PASO));
    if(nave->direccion>=2*PI)
        nave->direccion-=2*PI;
}


//getters
bool chorro_get(nave_t *nave){
    return nave->chorro;
}
bool escudo_get(nave_t *nave){
    return nave->escudo;
}
void nave_posicion_get(nave_t *nave, float posicion[2]){
    posicion[0]=*(nave->posicion);
    posicion[1]=*(nave->posicion+1);
}

void nave_velocidad_get(nave_t *nave, float velocidad[2]){
    velocidad[0]=*(nave->velocidad);
    velocidad[1]=*(nave->velocidad+1);
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
float combustible_get(nave_t *nave){
    return  nave->combustible;
}

//destruccion

void nave_destruir(nave_t *nave){    
    free(nave);
}