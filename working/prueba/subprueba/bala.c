#include "bala.h"
struct bala{
    float posicion[2];
    float direccion;
    float velocidad;
    size_t tiempo;
};

bala_t *crear_bala(float posicion[2],float direccion){
    
    bala_t *bala=malloc(sizeof(bala_t));
    if(bala==NULL) return NULL;

    bala->posicion[0]=posicion[0];
    bala->posicion[1]=posicion[1];
    bala->direccion=direccion;
    bala->velocidad=MAX_BAL_VELO;
    bala->tiempo=MAX_BAL_TIEM;

    return bala;
}

bool disparo(lista_t *lista,float posicion[2],float direccion){
    bala_t *bala=crear_bala(posicion,direccion);
    return lista_insertar_primero(lista,bala);
}

bool destruir_disparos(lista_t *lista){
    size_t largo_lista=lista_largo(lista);
    lista_iter_t *lista_iter=lista_iter_crear(lista);
    size_t i=0;
    while(i<largo_lista){
    bala_t *bala=lista_iter_ver_actual(lista_iter);
    float tiempo=obtener_tiempo(bala);
    if(tiempo<(MAX_BAL_TIEM/10)){
        if(lista_iter_borrar(lista_iter)==NULL){
            lista_iter_destruir(lista_iter);
            return true;
        }
        lista_iter_avanzar(lista_iter);
    }
    restar_tiempo(bala,tiempo);
    }
    lista_iter_destruir(lista_iter);
    return false;
}
float obtener_tiempo(bala_t *bala){
    return bala->tiempo;
}
void restar_tiempo(bala_t *bala,float tiempo){
    bala->tiempo=(tiempo-(1/JUEGO_FPS));
}

void destruir_bala(bala_t *bala){
    free(bala);
}
void liquidar_municion(void *bala){
    destruir_bala(bala);
}