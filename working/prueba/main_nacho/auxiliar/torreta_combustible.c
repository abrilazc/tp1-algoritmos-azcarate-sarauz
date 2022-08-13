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
struct nivel{
	....
	lista_t torreta;
}


struct torreta{
	float[2] posicion;
	float direccion;
}

crear lista
for(tamaño)
crear_torreta
lista_agregar_al principio

float torreta_n1[8][3]=...........
float datos=torreta_n1[i];

torreta_t *crear_torreta(size_t tamaño,float datos[3]){
	torreta_t nueva=malloc(sizeof(torreta_t)*tamaño);
	if(!nueva) return null;

	nueva->posicion[0]=datos

*/