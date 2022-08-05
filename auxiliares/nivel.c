#include "nivel.h"

struct nivel{
    char[20] nombre;
    figura_t *figura;
    bool infinito;
    lista_t *tanque;
    lista_t *torreta;
    reactor_t *reactor;
};


//Creacion niveles
nivel_t *crear_nivel(figura_t figura){
    nivel_t *nivel_nuevo=malloc(sizeof(nivel_t));
    if(nivel_t==NULL) return NULL;

    char[20] nombre=nombre_fig(figura)
    nivel->nombre=nombre;//quizas, ni es necesario
    nivel->figura=figura;//alguna funcion de figura_t que me de una figura del bloque figuras;
    nivel->infinito=infinito_fig(figura);
    nivel->tanque=disponer_tanques(nombre);
    nivel->torreta=disponer_torretas(nombre);
    nivel->ractor=disponer_reactor(nombre);
}
nivel_t **crear_niveles(figura_t **figura){
    size_t cantidad_niveles=contar_tipo("NIVEL");
    nivel_t **conjunto_niveles=malloc(sizeof(nivel_t*)*cantidad_niveles);
    if(conjunto_niveles==NULL) return NULL;

    for(size_t i=0,i<cantidad_niveles,i++){
        figura_t *figura=conjunto_niveles[i];
        conjunto_nivel[i]=crear_nivel(figura)
    }
    return conjunto_niveles;
}

//Destruir nivel
void destruir_nivel(nivel_t nivel){
    //destruir (figura); este no va, porque lo unico que obtiene es la direccion de otro generador de figura
    destruir(tanque);
    destruir(torreta);
    destruir(reactor);
    free(nivel);
}
void destruir_niveles(nivel_t **niveles, size_t cantidad_niveles){
    for(size_t i=0,i<cantidad_niveles,i++){
        destruir_nivel(nivel[i];)
    }
    free(niveles);
}


