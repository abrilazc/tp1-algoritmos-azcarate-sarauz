struct nivel{
    char[20] nombre;
    figura_t *figura;
    bool infinito;
    tanque_t *tanque;
    torreta_t *torreta;
    reactor_t *reactor;
};
//Creacion niveles
nivel_t *crear_nivel(figura_t *figura){
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
        conjunto_nivel[i]=crear_nivel(figura);//ke
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