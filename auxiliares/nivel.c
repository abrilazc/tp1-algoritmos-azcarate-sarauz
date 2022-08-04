#include "nivel.h"

struct nivel{
    char[20] nombre;
    figura_t *figura;
    bool infinito;
    lista_t *tanque;
    lista_t *torreta;
    reactor_t *reactor;
};

//Estructuras nodos
struct lista{
    struct nodo *primer_nodo;
    size_t cantidad_elementos;
};
struct nodo{
    struct nodo *proximo;
    float[2] posicion;
    float direccion;
}
struct nodo_bala{
    struct nodo *proximo;
    float[2] posicion;
    float direccion;
    size_t respawn;
}
//Nodos

/*
    Buscar nodos no se si es necesaria
    Quitar nodo (revisar)
*/
nodo_t *crear_nodo(float posicion [2], float direccion){
    nodo_t *nodo=malloc(sizeof(nodo));
    if(nodo==NULL) return NULL;

    nodo->proximo=NULL;
    nodo->posicion[0]=posicion[0];
    nodo->posicion[1]=posicion[1];
    nodo->direccion=direccion;

    return nodo;
}
lista_t *crear_lista(float *posicion [2], float *direccion, size_t cantidad){
    lista_t *nueva=malloc(sizeof(lista_t));
    if(nueva==NULL) return NULL;
    
    nodo_t *nodo[cantidad];
    for(size_t i=0; i<cantidad; i++){
        nodo[i]=crear_nodo(posicion[i],direccion[i]);
        if(i>1){
        (nodo->proximo)[i-1]=nodo[i];
        }
    }
    nueva->primer_nodo=nodo[0];
    nueva->cantidad_elementos=cantidad;

    return nueva;
}
nodo_pos_t *crear_nodo_bala(float posicion[2]){
    nodo_pos_t *nodo=malloc(sizeof(nodo_pos_t));
    if(nodo==NULL) return NULL;

    nodo->proximo=NULL;
    nodo->posicion[0]=posicion[0];
    nodo->posicion[1]=posicion[1];

    return nodo;
}
nodo_t *buscar_nodo(lista_t lista, float posicion[2]){
    size_t cantidad=lista->cantidad_elementos;
    
    nodo_t *nodo=lista->primer_nodo;
    float pos_nodo[2]=nodo->posicion;

    for(size_t i=0; i<cantidad; i++){
        if(posicion==pos_nodo) return nodo;
        pos_nodo=nodo->proximo->posicion;
        nodo=nodo->proximo;
    }
    return NULL;
}
void quitar_nodo(lista_t *lista, float posicion[2]){
    if(lista->primer_nodo==NULL) return;
    size_t cantidad=lista->cantidad_elementos;
    
    nodo_t *nodo=lista->primer_nodo;
    nodo_t *nodo_ant=NULL;
    float pos_nodo[2]=nodo->posicion;

    for(size_t i=0; i<cantidad; i++){
        if(posicion==pos_nodo){
            nodo_ant->proximo=nodo->proximo;
            if(i==0){
                lista->primer_nodo=nodo_ant;
            }
            lista->canditad_elementos--;
            destruir(nodo);
        }
        nodo_ant=nodo;
        nodo=nodo->proximo;
        pos_nodo=nodo->posicion;  
    }
}
void destruir_nodo(nodo_t nodo){
    free(nodo->proximo);
    free(nodo);
}
void destruir_lista(lista_t *lista){
    nodo_t *nodo_act=lista->primer_nodo;
    while(nodo_act!=NULL){
        nodo_t *aux=nodo_act;
        nodo_act=nodo_act->proximo;
        destruir_nodo(aux);
    }
    free(lista);
}

/*
    iteracion
        
        size_t cantidad_torretas=cantidad(lista_torretas);
        size_t cantidad_tanques=cantidad(lista_tanques);
        size_t cantidad_balas=cantidad(lista_balas);
        size_t tiempo=0;
        
        tiempo+=DT;
        if(cantidad_torretas!=0)
        float torretas_pos[cantidad_torretas][2]=posiciones(lista_torretas);
        //dibujar
        for(size_t i=0;i<cantidad_torretas;i++){
            if(interseccion(nave_pos,alcance_torretas[i]) && (tiempo%4==0)){
                //si puede hacer una bala:
                crear_nodo_bala(lista_bala);
                cantidad_balas++;
                //dibujar
            }
        }
        

        if(cantidad_tanques!=0)
        float tanques_pos[cantidad_tanques][2]=posiciones(lista_tanques);
        //dibujar

        if(cantidad_balas!=0)
            float balas_pos[cantidad_balas][2]=posiciones(lista_balas);
            //dibujar
            for(size_t j=0;j<cantidad_balas;j++){
                if(interseccion(nave_pos,balas_pos[i])){
                    //pierde_vida;
                    cantidad_torretas=cantidad(lista_torretas);
                    torretas_pos=posiciones(lista_torretas);
                    //dibujar
                }
            }

            if(cantidad_torretas!=0){
                for(size_t i=0;i<cantidad_torretas;i++){
                    for(size_t j=0;j<cantidad_balas;j++){
                        if(interseccion(torretas_pos[j],balas_pos[i])){
                            quitar_nodo(lista_torretas,torretas_pos[j]);
                            cantidad_torretas=cantidad(lista_torretas);
                            torretas_pos=posiciones(lista_torretas);
                            //dibujar
                        }
                    }
                }
            }
*/

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


//Setear direcciones a tanques, torretas y reactores
tanque_t *disponer_tanques(char *nombre){
    size_t cantidad_tanques=cantidad_tanques(nombre);
    tanque_t *tanque_nuevo=crear_tanque(cantidad_tanques);
    if(tanque_nuevo==NULL) return NULL;
    return tanque_nuevo;
}
torreta_t *disponer_torretas(char *nombre){
    size_t cantidad_torretas=cantidad_torretas(nombre);
    tanque_t *torreta_nuevo=crear_torreta(cantidad_tanques);
    if(torreta_nuevo==NULL) return NULL;
    return torreta_nuevo;
}
reactor_t *disponer_reactor(char *nombre){
    if(cantidad_reactores(nombre)){
        reactor_t *reactor_nuevo=crear_reactor(1);
        return reactor_nuevo;
    }
    return NULL;
}


//Setear cantidades
const size_t cantidad_tanques(char *nombre){
    static const size_t cantidad[]={
    [NIVEL1NE]=2,
    [NIVEL1SE]=2,
    [NIVEL1R]=0,
    [NIVEL1NW]=4,
    [NIVEL1SW]=3;
    }
    return cantidad[nombre];
}
const size_t cantidad_torretas(char *nombre){
    static const size_t cantidad[]={
    [NIVEL1NE]=2,
    [NIVEL1SE]=4,
    [NIVEL1R]=0,
    [NIVEL1NW]=8,
    [NIVEL1SW]=6;
    }
    return cantidad[nombre];
}
const bool cantidad_reactores(char *nombre){
    static const bool cantidad[]={
    [NIVEL1NE]=0,
    [NIVEL1SE]=0,
    [NIVEL1R]=1,
    [NIVEL1NW]=0,
    [NIVEL1SW]=0;
    }
    return cantidad[nombre];
}

/*
//Setear posiciones
const float[3]* posicion_tanques(char *nombre){
    static const size_t* cantidad[]={
    [NIVEL1NE]={(1064, 13, 0), (1685, 113, 0)},
    [NIVEL1SE]={(482, 94, 0), (1751, 247, 0)},
    [NIVEL1R]={(0,0,0)},
    [NIVEL1NW]={(188, 429, 0), (667, 600, 0), (1054, 404, 3.14), (574, 344, 3.14)},
    [NIVEL1SW]={(820, 46, 0), (1196, 68, 0), (1602, 46, 0)} ;
    }
    return posicion[nombre];
}
const float[3]* posicion_torretas(char *nombre){
    static const size_t* cantidad[]={
    [NIVEL1NE]={(916, 75, -0.66), (1425, 159, 0.66)},
    [NIVEL1SE]={(423, 195, -0.66), (806, 215, -0.33), (1254, 153, 0.66), (1587, 223, 2.23)},
    [NIVEL1R]={(0,0,0)},
    [NIVEL1NW]={(257, 440, 0.66), (719, 674, 2.23), (985, 565, 0), (1125, 417, 3.8), (862, 163, 3.8), (626, 323, 2.23), (505, 331, 3.8), (378, 296, 2.23)},
    [NIVEL1SW]={(70, 46, 0), (506, 12, 0), (952, 12, 0), (1385, 12, 0), (757, 210, 3.14), (1161, 210, 3.14)};
    }
    return posicion[nombre];
}
const float[3]* posicion_torretas(char *nombre){
    static const size_t* cantidad[]={
    [NIVEL1NE]={(0,0,0)},
    [NIVEL1SE]={(0,0,0)},
    [NIVEL1R]={(815, 309, 0)},
    [NIVEL1NW]={(0,0,0)},
    [NIVEL1SW]={(0,0,0)};
    }
    return posicion[nombre];
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
}*/
