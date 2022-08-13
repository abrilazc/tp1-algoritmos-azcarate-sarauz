//Estructuras nodos
struct nodo_bala{
    struct nodo *proximo;
    float[2] posicion;
    float direccion;
    float respawn;
}
struct lista_bala{
    struct nodo_bala *primer_nodo;
    figura_t **figura;
    size_t cantidad_elementos;
};

//Nodos
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
