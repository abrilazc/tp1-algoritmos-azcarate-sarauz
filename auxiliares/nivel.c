#include "nivel.h"

pantalla_inicio(nave_t nave){
    float planetas[7][2]={
        (388, 218),//base
        (663, 473),//p1
        (671, 145),//p2
        (110, 79),//p3
        (204, 455),//p4
        (111, 307),//p5
        (457, 364)//estrella
    };

    dibujar_figura(renderer,,"BASE",planetas[0],1);
    for(size_t i=1;i<6;i++){
        char planeta_p[9]="PLANETA";
        char ii=i+;
        strcat(planeta_p,ii);
        dibujar_figura(renderer,,planeta_p,planetas[i],1);
    }
    
    dibujar_figura(renderer,,"ESTRELLA",planetas[7],1);
    
    //abajo dice planetas[0]
    //pero hay que pasarle la posicion de la nave
    //y a la posicion de la nave asignarle planeta[0]
    dibujar_figura(renderer,,"NAVE",planetas[0],1)
}


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
    float respawn;
}

//Nodos
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
void destruir_nodo(nodo_t *nodo){
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

//Balas

nodo_pos_t *crear_nodo_bala(float posicion[2]){
    nodo_pos_t *nodo=malloc(sizeof(nodo_pos_t));
    if(nodo==NULL) return NULL;

    nodo->proximo=NULL;
    nodo->posicion[0]=posicion[0];
    nodo->posicion[1]=posicion[1];
    nodo->direccion=direccion;
    nodo->respawn=0;

    return nodo;
}
lista_t *lista_bala(float *posicion [2], float *direccion, size_t cantidad, size_t respawn){
    lista_t *nueva=malloc(sizeof(lista_t));
    if(nueva==NULL) return NULL;
    
    nodo_bala_t *nodo[cantidad];
    for(size_t i=0; i<cantidad; i++){
        nodo[i]=crear_nodo_bala(posicion[i],direccion[i],0);
        if(i>1){
        (nodo->proximo)[i-1]=nodo[i];
        }
    }
    nodo->primer_nodo=nodo[0];
    nodo->cantidad_elementos=cantidad;

    return nueva;
}
void agregar_elemento_b(lista_t lista){
    void *aux=
}
void quitar_nodo_b(lista_t *lista, float posicion[2]){
    if(lista->primer_nodo==NULL) return;
    size_t cantidad=lista->cantidad_elementos;
    
    nodo_bala_t *nodo=lista->primer_nodo;
    nodo_bala_t *nodo_ant=NULL;
    float respawn=nodo->respawn;

    for(size_t i=0; i<cantidad; i++){
        if(respawn>TIEMPO_B){
            nodo_ant->proximo=nodo->proximo;
            if(i==0){
                lista->primer_nodo=nodo_ant;
            }
            lista->canditad_elementos--;
            destruir(nodo);
        }
        nodo_ant=nodo;
        nodo=nodo->proximo;
        respawn=nodo->respawn;  
    }
}
void destruir_nodo_b(nodo_bala_t *nodo){
    free(nodo->proximo);
    free(nodo);
}
void destruir_lista_b(lista_t *lista){
    nodo_bala_t *nodo_act=lista->primer_nodo;
    while(nodo_act!=NULL){
        nodo_bala_t *aux=nodo_act;
        nodo_act=nodo_act->proximo;
        destruir_nodo(aux);
    }
    free(lista);
}


/*
    
        
        size_t cantidad_torretas=cantidad(lista_torretas);
        size_t cantidad_tanques=cantidad(lista_tanques);
        size_t cantidad_balas=cantidad(lista_balas);
    
        //acomoda torretas

        if(cantidad_torretas!=0)
        float torretas_pos[cantidad_torretas][2]=posiciones(lista_torretas);
        //dibujar
        for(size_t i=0;i<cantidad_torretas;i++){
            if(interseccion(nave_pos,alcance_torretas[i])){
                //si puede hacer una bala:
                crear_nodo_bala(lista_bala);
                cantidad_balas++;
                //dibujar
            }
        }
        
        //acomoda tanques

        if(cantidad_tanques!=0)
        float tanques_pos[cantidad_tanques][2]=posiciones(lista_tanques);
        //dibujar

        //acomoda balas

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

            for(size_t j=0;j<cantidad_balas;j++){
                size_t vida_bala=lista_balas->nodo_actual->vida;
                if(vida_bala>5){
                    quitar_nodo//bala?
                }else{
                    lista_balas->nodo_actualvida++;
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
lista_t *lista_tanques(char *nombre){
    size_t cantidad=cantidad_tanques(nombre);
    float [cantidad][2]=posiciones_tanques(nombre);
    float [cantidad]=direcciones_tanques(nombre);
    lista_t *tanque_nuevo=crear_lista(posicion,direccion,cantidad);

    return tanque_nuevo;
}
lista_t *lista_torreta(char *nombre){
    size_t cantidad=cantidad_torretas(nombre);
    float [cantidad][2]=posiciones_torretas(nombre);
    float [cantidad]=direcciones_torretas(nombre);
    lista_t *torreta_nueva=crear_lista(posicion,direccion,cantidad);

    return torreta_nueva;
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


/*nodo_t *buscar_nodo(lista_t lista, float posicion[2]){
    size_t cantidad=lista->cantidad_elementos;
    
    nodo_t *nodo=lista->primer_nodo;
    float pos_nodo[2]=nodo->posicion;

    for(size_t i=0; i<cantidad; i++){
        if(posicion==pos_nodo) return nodo;
        pos_nodo=nodo->proximo->posicion;
        nodo=nodo->proximo;
    }
    return NULL;
}*/