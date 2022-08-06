//Estructuras nodos
struct lista{
    struct nodo *primer_nodo;
    figura_t **figura;
    size_t cantidad_elementos;
};
struct nodo{
    struct nodo *proximo;
    float[2] posicion;
    float direccion;
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
lista_t *crear_lista(figura_t **figuras,float *posicion [2], float *direccion, size_t cantidad){
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
    nueva->figura=figuras;
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

//Setear posiciones

/*
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
*/