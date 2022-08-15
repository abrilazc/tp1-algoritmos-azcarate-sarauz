#include "bala.h"
struct bala{
    float posicion[2];
    float direccion;
    float velocidad;
    float tiempo;
};

bala_t *crear_bala(float posicion[2],float direccion){
    
    bala_t *bala=malloc(sizeof(bala_t));
    if(bala==NULL) return NULL;

    bala->posicion[0]=posicion[0];
    bala->posicion[1]=posicion[1];
    bala->direccion=direccion;
    bala->tiempo=25;

    return bala;
}

bool disparo(lista_t *lista,float posicion[2],float direccion){
    bala_t *bala=crear_bala(posicion,direccion);
    return lista_insertar_ultimo(lista,bala);
}

bool destruir_disparos(lista_t *lista){
    size_t largo_lista=lista_largo(lista);
    lista_iter_t *lista_iter=lista_iter_crear(lista);
    size_t i=0;
    while(i<largo_lista){
        bala_t *bala=lista_iter_ver_actual(lista_iter);
        float tiempo=obtener_tiempo(bala);
        restar_tiempo(bala,tiempo);
        if(tiempo<(3*DT)){
            if(lista_iter_borrar(lista_iter)==NULL){
                lista_iter_destruir(lista_iter);
                return true;
            }
            lista_iter_avanzar(lista_iter);
        }
        i++;
    }
    lista_iter_destruir(lista_iter);
    return false;
}
float obtener_tiempo(bala_t *bala){
    return bala->tiempo;
}
void restar_tiempo(bala_t *bala,float tiempo){
    bala->tiempo-=DT;
}
void posicion_bala(bala_t *bala,float posicion[2]){
    posicion[0]=(bala->posicion)[0];
    posicion[1]=(bala->posicion)[1];
}
float direccion_bala(bala_t *bala){
    return bala->direccion;
}

static void set_posicion_bala(bala_t *bala, float posicion[2]){
    (bala->posicion)[0]=posicion[0];
    (bala->posicion)[1]=posicion[1];
}

void trayectoria_disparo(lista_t *lista){
    size_t largo=lista_largo(lista);
    float posicion_actual[2];
    lista_iter_t *lista_iter=lista_iter_crear(lista);
    for(size_t i=0;i<largo;i++){
        bala_t *bala=lista_iter_ver_actual(lista_iter);
        float direccion=direccion_bala(bala);
        posicion_bala(bala,posicion_actual);
        float velocidad[]={MAX_BAL_VELO*cos(direccion),MAX_BAL_VELO*sin(direccion)};
        //float velocidad[]={MAX_BAL_VELO,MAX_BAL_VELO};
        //rotar_punto(velocidad,posicion_actual,direccion);
        trasladar(posicion_actual,velocidad);
        set_posicion_bala(bala,posicion_actual);
        lista_iter_avanzar(lista_iter);
    }
    lista_iter_destruir(lista_iter);
}


void vaciar_bala(lista_t *lista){
    lista_iter_t *listar=lista_iter_crear(lista);
    while(lista_iter_ver_actual(listar)!=NULL){
        lista_iter_borrar(listar);
        lista_iter_avanzar(listar);
    }
    lista_iter_destruir(listar);
}
void destruir_bala(bala_t *bala){
    free(bala);
}
void liquidar_municion(void *bala){
    destruir_bala(bala);
}